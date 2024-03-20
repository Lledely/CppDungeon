//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "EnemyType.h"
#include "entity/Entity.h"
#include "entity/MarkedAsAutoTurn.h"
#include "namespaces/skillDesigns.h"
namespace entity {
    class Enemy : public Entity, public MarkedAsAutoTurn {
    public:
        Enemy(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
        void autoTurn(Player*, std::shared_ptr<BattleField>, std::shared_ptr<entity::Entity>) override;
    };
} // namespace entity
#endif //UNTITLED_ENEMY_H
