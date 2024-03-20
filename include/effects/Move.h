//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_MOVE_H
#define CPPDUNGEON_MOVE_H
#include "effects/ImmediateEffect.h"
#include "effects/MarkedAsBattleFieldNeeded.h"
#include "namespaces/battlefield.h"
namespace effects {
    class Move: public ImmediateEffect, public MarkedAsBattleFieldNeeded {
        int m_offset;
    protected:
        std::function<int (const std::shared_ptr<entity::Entity>&, const std::shared_ptr<BattleField>&)> getTurnFunctionBattleField() override;
    public:
        Move(int offset);
    };
}
#endif //CPPDUNGEON_MOVE_H
