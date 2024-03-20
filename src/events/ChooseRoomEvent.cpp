//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "events/ChooseRoomEvent.h"
#include "actions/ChooseNextRoom.h"
#include "navigation/Map.h"
#include "monitor/Monitor.h"
#include "player/Player.h"


void events::ChooseRoomEvent::turn(Player *player) {
    player->getMap()->getCell(player->getPosition())->freeMoves(player);
    player->getMonitor()->draw(player);
    player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
    for (Position coords : player->getMap()->getNextRooms(player->getPosition())) {
        addUniqueAction(player, std::make_shared<actions::ChooseNextRoom>(coords));
    }
}

std::vector<std::vector<char>> events::ChooseRoomEvent::draw() {
    std::vector<std::vector<char>> sprite;
    return sprite;
}