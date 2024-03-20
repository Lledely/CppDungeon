//
// Created by Арсений Бородулин on 10.03.2024.
//

#ifndef CPPDUNGEON_SQUADCHANGER_H
#define CPPDUNGEON_SQUADCHANGER_H
#include "memory"
#include "namespaces/entity.h"
#include "namespaces/battlefield.h"

class SquadChanger {
public:
    static void move(const std::shared_ptr<Squad>& squad, int index1, int index2);
    static void move(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>&entity, int index1);
    static void relativeMove(const std::shared_ptr<Squad>& squad, int index, int offset);
    static void relativeMove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>&entity, int offset);
    static void remove(const std::shared_ptr<Squad>& squad, int index);
    static void remove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>&entity);
    static void add(const std::shared_ptr<Squad>& squad, std::shared_ptr<entity::Entity>entity, int index);
    static void add(const std::shared_ptr<Squad>& squad, std::shared_ptr<entity::Entity>entity);
};

#endif //CPPDUNGEON_SQUADCHANGER_H
