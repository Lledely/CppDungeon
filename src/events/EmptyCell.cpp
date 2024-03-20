//
// Created by Арсений Бородулин on 03.03.2024.
//
#include "events/EmptyCell.h"
#include "navigation/Map.h"
#include "monitor/Monitor.h"
#include "player/Player.h"

void events::EmptyCell::turn(Player* player) {
    player->getMap()->getCell(player->getPosition())->freeMoves(player);
    player->getMonitor()->draw(player);
    player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
}

std::vector<std::vector<char>> events::EmptyCell::draw() {
    std::vector<std::vector<char>> sprite;
    sprite.push_back(std::vector<char>{'/',  '-', '-', '-', '-', '-', '\\'});
    sprite.push_back(std::vector<char>{'|',  'E', 'M', 'P', 'T', 'Y', '|' });
    sprite.push_back(std::vector<char>{'|',  'C', 'E', 'L', 'L', '-', '|' });
    sprite.push_back(std::vector<char>{'\\', '-', '-', '-', '-', '-', '/' });
    return sprite;
}