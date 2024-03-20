//
// Created by artem on 13.03.2024.
//

#ifndef CPPDUNGEON_FORCEMOVE_H
#define CPPDUNGEON_FORCEMOVE_H
#include "effects/ImmediateEffect.h"
#include "effects/Move.h"
#include "effects/MarkedAsResistable.h"
#include "namespaces/battlefield.h"
namespace effects {
    class ForceMove: public Move, public MarkedAsResistable {
    public:
        ~ForceMove() override = default;
        ForceMove(int offset);
        int resistanceHash() override;
    };
}
#endif //CPPDUNGEON_FORCEMOVE_H
