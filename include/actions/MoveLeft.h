//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_MOVELEFT_H
#define CPPDUNGEON_MOVELEFT_H
#include "actions/Action.h"
#include "changers/ActionsChanger.h"
#include "changers/PositionChanger.h"
namespace actions {
    class MoveLeft : public Action, public changers::ActionsChanger, public changers::PositionChanger {
    public:
        void act(Player *player) override;
        std::string getName() override;
        bool operator==(const MoveLeft& moveLeft) const;
    };

#endif //CPPDUNGEON_MOVELEFT_H
} // namespace actions