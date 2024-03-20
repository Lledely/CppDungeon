#include "BattleField.h"
#include "changers/ActionsChanger.h"
#include "actions/DeselectSkills.h"
#include "entity/Enemy.h"
#include "entity/MarkedAsAutoTurn.h"
#include "events/EnemyEncounter.h"
#include "entity/Hero.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "navigation/Map.h"
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "actions/UseSkill.h"
#include "actions/UseItem.h"
#include "generators/NumberGenerator.h"
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "actions/TurnEvent.h"
#include "actions/DeselectSkills.h"
namespace events {
    EnemyEncounter::EnemyEncounter() {

        std::vector<std::shared_ptr<entity::Entity>> tmpEnemies;
        int numberOfEnemies = generators::NumberGenerator::generate(1, 3);
        tmpEnemies.reserve(numberOfEnemies);

        for (int i = 0;i<numberOfEnemies;i++) {
            int num = generators::NumberGenerator::generate(0, 2);
            switch (num) {
            case 0:
                tmpEnemies.push_back(std::make_shared<enemies::BrigandRaider::BrigandRaider>());
                break;
            case 1:
                tmpEnemies.push_back(std::make_shared<enemies::BrigandFusilier::BrigandFusilier>());
                break;
            default:
                tmpEnemies.push_back(std::make_shared<enemies::CultistAcolyte::CultistAcolyte>());
                break;
            }
        }

        m_enemies = std::shared_ptr<Squad>(new Squad(tmpEnemies));
        m_priority = {};
        m_isInBattle = true;
        m_lastToMove = nullptr;
        m_battleField = std::shared_ptr<BattleField>(new BattleField(m_enemies, m_enemies));
    }

    std::shared_ptr<Squad> EnemyEncounter::getEnemies() {
        return m_enemies;
    }

    std::shared_ptr<entity::Entity> EnemyEncounter::getLastToMove() {
        return m_lastToMove;
    }

    bool EnemyEncounter::getIsInBattle() {
        return m_isInBattle;
    }

    std::vector<std::vector<char>> EnemyEncounter::draw() {
        std::vector<std::vector<char>> to_ret;
        for (auto &i: m_enemies->getEntities()) {
            to_ret.insert(to_ret.end(), i->draw().begin(), i->draw().end());
        }
        return to_ret;
    }

    std::shared_ptr<BattleField> EnemyEncounter::getBattleField() {
        return m_battleField;
    }

    void EnemyEncounter::_enemyMove(Player* player, std::shared_ptr<entity::Entity> entity, int rank, std::shared_ptr<BattleField> battleField) {
        std::cout << "i am attacking" << std::endl;
        auto skills = entity->getSkills();
        std::vector<std::shared_ptr<skillDesigns::Skill>> availableSkills;
        for (auto i: skills) {
            if (std::find(i->getAvaibleRank().begin(), i->getAvaibleRank().end(), rank) != i->getAvaibleRank().end()) {
                availableSkills.push_back(i);
            }
        }
        int num = generators::NumberGenerator::generate(0, availableSkills.size() - 1);
        auto skillToUse = availableSkills[num];
        int target = generators::NumberGenerator::generate(0, skillToUse->getAvaibleAllyTarget().size() + skillToUse->getAvaibleEnemyTarget().size() - 1);
        if (target < skillToUse->getAvaibleAllyTarget().size()) {
            skillToUse->use(battleField, entity, {player->getSquad()->getEntities().at(skillToUse->getAvaibleAllyTarget()[target])});
        }
        else {
            target -= skillToUse->getAvaibleAllyTarget().size();
            skillToUse->use(battleField, entity, {battleField->getEnemySquad(entity)->getEntities().at(skillToUse->getAvaibleEnemyTarget()[target])});
        }
    }

    bool EnemyEncounter::_checkAlive(std::vector<std::shared_ptr<entity::Entity>> entities) {
        for (auto i: entities) {
            if (i && i->isAlive()) {
                return true;
            }
        }
        return false;
    }
    void EnemyEncounter::_refreshPriority(){
        if (m_priority.empty()) {
            std::vector<std::shared_ptr<entity::Entity>> enemiesEntities = m_enemies->getEntities();
            std::vector<std::shared_ptr<entity::Entity>> priority = m_battleField->getEntities();
            std::sort(priority.begin(), priority.end(), [enemiesEntities] (std::shared_ptr<entity::Entity> a, std::shared_ptr<entity::Entity> b) {
                if (a->get(Characteristic::speed) == b->get(Characteristic::speed)) {
                    return (std::find(enemiesEntities.begin(), enemiesEntities.end(), a) == enemiesEntities.end());
                }
                return a->get(Characteristic::speed) > b->get(Characteristic::speed);
            });
            for (const auto& i: priority) {
                if (i && i->isAlive()) {
                    m_priority.push(i);
                }
            }
        }
    }

    void EnemyEncounter::turn(Player* player) {
        std::shared_ptr<BattleField> battleField = std::shared_ptr<BattleField>(new BattleField(player->getSquad(), m_enemies));
        m_battleField = battleField;
        _refreshPriority();
        do {
            std::vector<std::shared_ptr<entity::Entity>> enemiesEntities = m_enemies->getEntities();
            bool heroesAlive = _checkAlive(player->getSquad()->getEntities());
            bool enemiesAlive = _checkAlive(m_enemies->getEntities());
            if (!(heroesAlive && enemiesAlive)) {
                for (auto i: player->getSquad()->getEntities()) {
                    endBattleTurnEffects(i);
                }
                for (auto i: enemiesEntities) {
                    endBattleTurnEffects(i);
                }
                m_isInBattle = false;
                player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
                return;
            }
            _refreshPriority();
            std::shared_ptr<entity::Entity> entity = m_priority.front();
            m_priority.pop();
            if (entity && !entity->isAlive()) {
                m_lastToMove = entity;
                return;
            }
            turnEffects(entity);
            if (!entity->isTurnable()) {}
            else if (auto markedAsAutoTurn = std::dynamic_pointer_cast<entity::MarkedAsAutoTurn>(entity)) {
                markedAsAutoTurn->autoTurn(player, battleField, entity);
                player->getMonitor()->draw(player);
            } else if (battleField->areAllies(entity, enemiesEntities[0])) {
                _enemyMove(player, entity, std::distance(enemiesEntities.begin(),
                                                         std::find(enemiesEntities.begin(), enemiesEntities.end(),
                                                                   entity)) + 1, battleField);
                player->getMonitor()->draw(player);
            }

            m_lastToMove = entity;
            if (m_priority.empty()) {
                std::vector<std::shared_ptr<entity::Entity>> priority = battleField->getEntities();
                std::sort(priority.begin(), priority.end(),
                          [enemiesEntities](std::shared_ptr<entity::Entity> a, std::shared_ptr<entity::Entity> b) {
                              if (a->get(Characteristic::speed) == b->get(Characteristic::speed)) {
                                  return (std::find(enemiesEntities.begin(), enemiesEntities.end(), a) ==
                                          enemiesEntities.end()) ? true : false;
                              }
                              return a->get(Characteristic::speed) > b->get(Characteristic::speed);
                          });
                for (const auto &i: priority) {
                    if (i->isAlive()) {
                        m_priority.push(i);
                    }
                }
            }
            if (battleField->areAllies(getLastToMove(), enemiesEntities[0])) {
                returnToDefault(player);
                changers::ActionsChanger::addUniqueAction(player, std::make_shared<actions::TurnEvent>(
                        std::dynamic_pointer_cast<events::Event>(shared_from_this())));
            } else {
                returnToDefault(player);
                auto deselectAction = std::make_shared<actions::DeselectSkills>(getLastToMove(),
                                                                                battleField);
                deselectAction->act(player);
            }
        } while (m_lastToMove == nullptr);
   }

}