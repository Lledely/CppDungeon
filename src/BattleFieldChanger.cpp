//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "BattleFieldChanger.h"
#include "BattleField.h"
#include "SquadChanger.h"
#include <stdexcept>

void BattleFieldChanger::move(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity> entity, int index1) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::move(squad, entity, index1);
}
void BattleFieldChanger::relativeMove(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity> entity, int offset) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::relativeMove(squad, entity, offset);
}

void BattleFieldChanger::remove(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity>entity) {
    std::shared_ptr<Squad> const squad = field->getSquad(entity);
    if (squad == nullptr) { throw std::logic_error("entity is not on the field"); }
    SquadChanger::remove(squad, entity);
}
