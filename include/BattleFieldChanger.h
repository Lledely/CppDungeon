//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_BATTLEFIELDCHANGER_H
#define CPPDUNGEON_BATTLEFIELDCHANGER_H
#include <memory>
#include "namespaces/entity.h"
#include "namespaces/battlefield.h"
#include <stdexcept>

class BattleFieldChanger {
protected:
    static void move(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity> entity, int index1);
    static void relativeMove(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity> entity, int offset);
    static void remove(const std::shared_ptr<BattleField>& field, std::shared_ptr<entity::Entity> entity);
};

#endif //CPPDUNGEON_BATTLEFIELDCHANGER_H