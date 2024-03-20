//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include "player/Inventory.h"
#include "navigation/Position.h"
#include <memory>
#include <set>
#include <vector>
#include "namespaces/entity.h"
class Map;
class Monitor;
#include "namespaces/actions.h"
#include "namespaces/changers.h"
#include "namespaces/battlefield.h"
class Player{
    Position m_position;
    Inventory m_inventory;
    std::shared_ptr<Squad> m_squad;
    std::set<std::shared_ptr<actions::Action>> m_actions;
    friend changers::ActionsChanger;
    friend changers::PositionChanger;
    friend changers::InventoryChanger;
    std::shared_ptr<Monitor> m_monitor;
    std::shared_ptr<Map> m_map;
public:
    explicit Player(const std::shared_ptr<Map>& map, const std::shared_ptr<Monitor>& monitor,const std::shared_ptr<Squad>& squad);
    std::shared_ptr<Monitor> getMonitor();
    Position getPosition();
    std::shared_ptr<Squad> getSquad();
    std::set<std::shared_ptr<actions::Action>> getActions();
    Inventory getInventory();
    std::shared_ptr<Map> getMap();
};
#endif //UNTITLED_PLAYER_H
