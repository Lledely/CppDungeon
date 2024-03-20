//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_MOVERIGHT_H
#define CPPDUNGEON_MOVERIGHT_H
#include "actions/Action.h"
#include "changers/ActionsChanger.h"
#include "changers/PositionChanger.h"
namespace actions {
    class MoveRight : public Action, public changers::ActionsChanger, public changers::PositionChanger {
    public:
        void act(Player *player) override;
        std::string getName() override;
        bool operator==(const MoveRight& moveRight) const;
    };

#endif //CPPDUNGEON_MOVERIGHT_H
} // namespace actions