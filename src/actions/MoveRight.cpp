//
// Created by kait on 3/12/24.
//
#include "actions/MoveRight.h"
#include "navigation/Map.h"
#include "player/Player.h"

namespace actions {

    void MoveRight::act(Player *player) {
        setPosition(player, player -> getMap() -> moveRight(player->getPosition()));
        returnToDefault(player);
        std::shared_ptr<Cell> temp = player->getMap()->getCell(player->getPosition());
        temp->generateEvents();
        for(int i = 0; i < temp->getEvents().size(); i++) {
            if(auto event = temp->getEvents()[i]) {
                event->turn(player);
            }
        }
    }
    std::string MoveRight::getName() {
        return "Move Player right";
    }
    bool MoveRight::operator==(const actions::MoveRight &moveRight) const {
        return true;
    }
}//namespace actions