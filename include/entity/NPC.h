//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_NPC_H
#define MONITORTEST_NPC_H
#include "entity/Hero.h"
#include "entity/MarkedAsAutoTurn.h"
#include "namespaces/skillDesigns.h"
#include <string>
namespace entity {
    class NPC : public Hero, public MarkedAsAutoTurn {
    public:
        NPC(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills);
        void autoTurn(Player*, std::shared_ptr<BattleField>, std::shared_ptr<entity::Entity>) override;
    };
} // namespace entity
#endif //MONITORTEST_NPC_H
