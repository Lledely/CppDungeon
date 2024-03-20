//
// Created by Арсений Бородулин on 10.03.2024.
//

#include "BattleField.h"
#include "Squad.h"
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <algorithm>

BattleField::BattleField(
    std::shared_ptr<Squad> ally,
    std::shared_ptr<Squad> enemy
) : m_ally(ally), m_enemy(enemy) {}

std::vector<std::shared_ptr<entity::Entity>> BattleField::getEntities() const {
    std::vector<std::shared_ptr<entity::Entity>> allies = m_ally->getEntities();
    std::vector<std::shared_ptr<entity::Entity>> const enemies = m_enemy->getEntities();
    std::reverse(allies.begin(), allies.end());
    allies.reserve(allies.size() + enemies.size());
    for (const auto& entity : enemies) {allies.push_back(entity);}
    return allies;
}

std::shared_ptr<Squad> BattleField::getSquad(const std::shared_ptr<entity::Entity>& target) const {
    std::shared_ptr<Squad> ans = nullptr;
    for (const auto& entity : m_ally->getEntities()) {
        if (entity == target) {
            ans = m_ally;
            break;
        }
    }
    for (const auto& entity : m_enemy->getEntities()) {
        if (entity == target && ans != nullptr) {
            throw std::logic_error("squads are corrupted, they have similar entity");
        }
        if (entity == target) {
            return m_enemy;
        }
    }

    if(!ans){
        throw std::logic_error("No such entity on this squad");
    }
    return ans;
}

std::shared_ptr<Squad> BattleField::getEnemySquad(const std::shared_ptr<entity::Entity>& target) const {
    std::shared_ptr<Squad> const allySquad = getSquad(target);
    if (allySquad == m_ally) { return m_enemy;}
    else { return m_ally;}
}

bool BattleField::areAllies(const std::shared_ptr<entity::Entity>& ent1, const std::shared_ptr<entity::Entity>& ent2) const {
    std::shared_ptr<Squad> const ent1_squad = getSquad(ent1);
    std::shared_ptr<Squad> const ent2_squad = getSquad(ent2);
    if (ent1 == nullptr || ent2 == nullptr) { throw std::logic_error("one of entities is not in the m_squad"); }
    return ent1_squad == ent2_squad;
}

