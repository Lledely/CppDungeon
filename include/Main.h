//
// Created by artem on 15.03.2024.
//

#ifndef CPPDUNGEON_MAIN_H
#define CPPDUNGEON_MAIN_H
#include "memory"
#include "random"
#include <map>
#include <string>
class Monitor;
namespace events{class Event;};
namespace entity {class Entity;};
namespace items {class Item;};
namespace entity {class Boss;};
namespace entity {class Hero;};
namespace entity {class NPC;};
#include "eventfactory.h"
class Player;
class Main {
    size_t m_seed = 1;
    std::map<size_t, std::string> m_map;
    ObjectFactory<events::Event, size_t> m_eventFactory;
    ObjectFactory<entity::Entity, size_t> m_enemiesFactory;
    ObjectFactory<items::Item, size_t> m_itemsFactory;
    ObjectFactory<entity::Boss, size_t> m_bossesFactory;
    ObjectFactory<entity::Hero, size_t> m_heroesFactory;
    ObjectFactory<entity::NPC, size_t> m_npcFactory;
public:
    Main();

    template<class C>
    int my_rand(size_t, ObjectFactory<C, size_t> objectFactory);

    int my_rand_entity(size_t);
    int my_rand_item(size_t);
    void setSeed(std::size_t);
    std::size_t getSeed();
    Player* getGame();
    events::Event* getEvent();
    entity::Entity* getEnemy();
    items::Item* getItem();
    entity::Boss* getBoss();
    entity::Hero* getHero();
    entity::NPC* getNPC();


};
#endif //CPPDUNGEON_MAIN_H
