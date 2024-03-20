//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_ITEM_H
#define CPPDUNGEON_ITEM_H
#include "skillDesigns/RangeSkill.h"

namespace items {
    class Item : public skillDesigns::RangeSkill {
    public:
        Item(int size, std::string name, std::vector<int> availableRank,
                   std::vector<int> availableAllyTarget = {},
                   std::vector<int> availableEnemyTarget = {},
                   int accuracy = 0, int criticalDamageChance = 0);
        virtual std::string drawItem() = 0;
    };
}
#endif //CPPDUNGEON_ITEM_H
