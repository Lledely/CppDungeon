//
// Created by artem on 08.03.2024.
//
#include "actions/Action.h"
#include "entity/Entity.h"
#include "player/Inventory.h"
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Position.h"
#include "navigation/Map.h"
#include "Squad.h"
#include <memory>

Player::Player(const std::shared_ptr<Map>& map, const std::shared_ptr<Monitor>& monitor, const std::shared_ptr<Squad>& squad) : m_map(map), m_monitor(monitor), m_squad(squad) {
    m_position = map->getStartPosition();
    if(map->getCell(m_position) == nullptr){
        throw std::logic_error("No such Cell");
    }
    map->getCell(m_position)->generateEvents();
    for(auto& event:map->getCell(m_position)->getEvents()){
        if(event!= nullptr) {
            event->turn(this);
        }
    }
}

std::shared_ptr<Monitor> Player::getMonitor() {
    return m_monitor;
}
Position Player::getPosition() {
    return m_position;
}

std::shared_ptr<Squad> Player::getSquad() {
    return m_squad;
}

Inventory Player::getInventory() {
    return m_inventory;
}

std::shared_ptr<Map> Player::getMap() {
    return m_map;
}

std::set<std::shared_ptr<actions::Action>> Player::getActions() {
    return m_actions;
}