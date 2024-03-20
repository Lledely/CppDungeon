//
// Created by kait on 3/19/24.
//
#include "items/Item.h"

namespace items {
    Item::Item(int size, std::string name, std::vector<int> availableRank, std::vector<int> availableAllyTarget,
               std::vector<int> availableEnemyTarget, int accuracy, int criticalDamageChance) : RangeSkill(size, name,
                                                                                                           availableRank,
                                                                                                           availableAllyTarget,
                                                                                                           availableEnemyTarget,
                                                                                                           accuracy,
                                                                                                           criticalDamageChance) {

    }
} //namespace items


