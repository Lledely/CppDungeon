//
// Created by Arseniy Borodulin on 10.03.2024.
//
#ifndef CPPDUNGEON_SQUAD_H
#define CPPDUNGEON_SQUAD_H
#include <memory>
#include <vector>
#include "namespaces/entity.h"
#include <stdexcept>

class Squad {
private:
    std::vector<std::shared_ptr<entity::Entity>> m_squad;
public:
    explicit Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad);
    Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad, int size);
    std::vector<std::shared_ptr<entity::Entity>> getEntities() const;
    std::shared_ptr<entity::Entity> getEntity(int index) const;
    int getIndex(const std::shared_ptr<entity::Entity>& entity) const;
    friend class SquadChanger;
};
#endif //CPPDUNGEON_SQUAD_H
