//
// Created by Владимир Попов on 08.03.2024
//
#include "changers/InventoryChanger.h"
#include "player/Player.h"

Inventory& changers::InventoryChanger::getInventory(Player *player){
    return player->m_inventory;
}

void changers::InventoryChanger::addItem(Player* player,const std::shared_ptr<items::Item>& item) {
    player->m_inventory.addItem(item);
}

void changers::InventoryChanger::removeItem(Player* player,const std::shared_ptr<items::Item>& item) {
    player->m_inventory.removeItem(item);
}