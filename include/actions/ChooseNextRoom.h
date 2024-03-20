//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_CHOOSENEXTROOM_H
#define CPPDUNGEON_CHOOSENEXTROOM_H
#include "actions/Action.h"
#include "changers/PositionChanger.h"
#include "navigation/Position.h"
#include <utility>

namespace actions {
    class ChooseNextRoom : public Action, public changers::PositionChanger {
    public:
        explicit ChooseNextRoom(Position);
        void act(Player *player) override;
        virtual std::string getName() override;
        Position getPostion();
        bool operator==(const ChooseNextRoom&) const;
    private:
        Position m_room;
    };
} // namespace actions
#endif //CPPDUNGEON_CHOOSENEXTROOM_H