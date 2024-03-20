#include <stdexcept>
#include <algorithm>
#include "BattleField.h"
#include "skillDesigns/Skill.h"
#include "Squad.h"
#include "entity/Entity.h"
#include "generators/NumberGenerator.h"
#include "effects/MarkedAsResistable.h"
namespace skillDesigns {
    Skill::Skill(std::string name, std::vector<int> availableRank, std::vector<int> availableAllyTarget,
                 std::vector<int> availableEnemyTarget, int accuracy, int criticalDamageChance) :
            m_name(name), m_availableRank(availableRank), m_availableAllyTarget(availableAllyTarget),
            m_availableEnemyTarget(availableEnemyTarget), m_accuracy(accuracy),
            m_criticalDamageChance(criticalDamageChance) {
        for(auto& i:m_availableRank){
            i--;
        }
        for(auto& i:m_availableAllyTarget){
            i--;
        }
        for(auto& i:m_availableEnemyTarget){
            i--;
        }
    }

    std::vector<int> Skill::getAvaibleRank() {
        return m_availableRank;
    }

    std::vector<int> Skill::getAvaibleAllyTarget() {
        return m_availableAllyTarget;
    }

    std::vector<int> Skill::getAvaibleEnemyTarget() {
        return m_availableEnemyTarget;
    }

    std::string Skill::getName() {
        return m_name;
    }

    std::string Skill::use(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                    std::vector<std::shared_ptr<entity::Entity>> objects) {
        std::string tryUse = isUsable(battleField, actor, objects);
        if (tryUse.empty()) {

            if (missed(actor) <= 0) {
                unsafeUse(crited(actor), battleField, actor, objects);
                return "passed";
            }
            else{
                return "missed";
            }
        }
        return tryUse;
    }

    std::string Skill::isUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                std::vector<std::shared_ptr<entity::Entity>> objects) {
        std::string firstToRet = isDesignUsable(battleField, actor, objects);
        if (firstToRet.empty()) {
            if(isImplementationUsable(battleField, actor, objects).empty()){
                return "";
            }
            else {
                return isImplementationUsable(battleField, actor, objects);
            }
        }
        return firstToRet;
    }

    int Skill::missed(std::shared_ptr<entity::Entity> actor) {
        return -actor->get(Characteristic::accuracyModifier) - m_accuracy + generators::NumberGenerator::generate(0, 100);
    }

    int Skill::dodged(std::shared_ptr<entity::Entity> actor) {
        return actor->dodged();
    }

    int Skill::resisted(std::shared_ptr<entity::Entity> object, size_t effectHash, int crited) {
        if (crited < 0) {
            return object->resisted(effectHash);
        }
        return object->resisted(effectHash) - 20;
    }

    int Skill::crited(std::shared_ptr<entity::Entity> actor) {
        return actor->get(Characteristic::criticalDamageChance) + m_criticalDamageChance -
               generators::NumberGenerator::generate(0, 100);
    }

    void Skill::unsafeUse(int crited, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                          std::vector<std::shared_ptr<entity::Entity>> objects) {
        unsafeSelfUse(crited, battleField, actor);
        for (const auto &obj: objects) {
            if(obj!= nullptr) {
                unsafeTargetUse(crited, battleField, actor, obj);
            }
        }
    }

    std::string Skill::isDesignUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                      std::vector<std::shared_ptr<entity::Entity>> objects) {
        try {
            battleField->getSquad(actor);
        }
        catch (const std::exception &e) {
            return "Some entity not on battleField";
        }
        for (const auto &obj: objects) {
                try {
                    battleField->getSquad(obj);
                }
                catch (const std::exception &e) {
                    return "Some entity not on battleField";
                }
        }

        auto actorSquadVector = battleField->getSquad(actor)->getEntities(); // std::vector<std::shared_ptr<Entity>>
        if (std::find(m_availableRank.begin(), m_availableRank.end(),
                      battleField->getSquad(actor)->getIndex(actor)) == m_availableRank.end()) {
            return "Can't act from this rank";
        }

        for (const auto &obj: objects) {
            if (battleField->areAllies(actor, obj)) {
                if (std::find(m_availableAllyTarget.begin(), m_availableAllyTarget.end(),
                              battleField->getSquad(obj)->getIndex(obj)) == m_availableAllyTarget.end()) {
                    return "Can't act on some ally target";
                }
            } else {
                if (std::find(m_availableEnemyTarget.begin(), m_availableEnemyTarget.end(),
                              battleField->getSquad(obj)->getIndex(obj)) == m_availableEnemyTarget.end()) {
                    return "Can't act on some enemy target";
                }
            }
        }

        return std::string();
    }

    std::string
    Skill::isImplementationUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                  std::vector<std::shared_ptr<entity::Entity>> objects) {
        for (const auto &obj: objects) {
            if(!obj || !obj->isAlive()){
                return "all objects must be alive";
            }
        }
        return "";
    }

    void Skill::addEffect(std::shared_ptr<entity::Entity> object, std::shared_ptr<effects::Effect> effect, std::shared_ptr<BattleField> battleField, int crited,
                          int accuracyModifier) {
        std::shared_ptr<effects::MarkedAsResistable> markedAsResistable = std::dynamic_pointer_cast<effects::MarkedAsResistable>(effect);
        if (object!= nullptr && (markedAsResistable == nullptr ||
            resisted(object, markedAsResistable->resistanceHash(), crited) - (accuracyModifier - 100) < 0)) {
            changers::EffectChanger::addEffect(object, effect, battleField);
        }
    }

    std::string Skill::draw() {
        return getName();
    }
} // namespace skillDesigns