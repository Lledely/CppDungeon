//
// Created by artem on 16.03.2024.
//
#include "Main.h"
#include "events/Event.h"
#include "events/Chest.h"
#include "events/ChooseRoomEvent.h"
#include "events/EmptyCell.h"
#include "events/Chest.h"
#include "events/Trap.h"
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "entity/Entity.h"
#include "entity/Enemy.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "bosses/GardenGuardian/BloodFount.h"
#include "bosses/GardenGuardian/GardenGuardian.h"
#include "bosses/GardenGuardian/StoneShield.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "items/Absinthe.h"
#include "items/BloodiedNeckerchief.h"
#include "items/FortifyingGarlic.h"
#include "items/LickWounds.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "heroes/Hellion/Hellion.h"
#include "heroes/ManAtArms/ManAtArms.h"
#include "heroes/Musketeer/Musketeer.h"
#include "heroes/PlagueDoctor/PlagueDoctor.h"
//#include "events/EnemyEncounter.h"
#include <random>

template <class C>
int Main::my_rand(size_t seed, ObjectFactory<C, size_t> objectFactory) {
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % objectFactory.getFactoryMap().size();
}
//int Main::my_rand_entity(size_t seed) { //TODO change on norm random function
//    seed = seed * 1103515245 + 12345;
//    return (seed / 65536) % m_entityFactory.getFactoryMap().size();
//}
//int Main::my_rand_item(size_t seed) { //TODO change on norm random function
//    seed = seed * 1103515245 + 12345;
//    return (seed / 65536) % m_itemsFactory.getFactoryMap().size();
//}

Main::Main() {
    m_eventFactory.add<events::Chest>(0);
    //m_eventFactory.add<events::ChooseRoomEvent>(1);
    m_eventFactory.add<events::EmptyCell>(1);
    m_eventFactory.add<events::Trap>(2);

    m_enemiesFactory.add<enemies::BrigandFusilier::BrigandFusilier>(0);
    m_enemiesFactory.add<enemies::BrigandRaider::BrigandRaider>(1);
    m_enemiesFactory.add<enemies::CultistAcolyte::CultistAcolyte>(2);

    m_bossesFactory.add<Bosses::BloodFount::BloodFount>(0);
    m_bossesFactory.add<Bosses::GardenGuardian::GardenGuardian>(1);
    m_bossesFactory.add<Bosses::StoneShield::StoneShield>(2);

    m_heroesFactory.add<Heroes::BountyHunter::BountyHunter>(0);

    m_itemsFactory.add<items::Absinthe::Absinthe>(0);
    m_itemsFactory.add<items::BloodiedNeckerchief::BloodiedNeckerchief>(1);
    m_itemsFactory.add<items::FortifyingGarlic::FortifyingGarlic>(2);
    m_itemsFactory.add<items::LickWounds::LickWounds>(3);

    m_heroesFactory.add<Heroes::BountyHunter::BountyHunter>(0);
    m_heroesFactory.add<Heroes::Hellion::Hellion>(1);
    m_heroesFactory.add<Heroes::ManAtArms::ManAtArms>(2);
    m_heroesFactory.add<Heroes::Musketeer::Musketeer>(3);

    m_npcFactory.add<NPC::PlagueDoctor::PlagueDoctor>(0);
}

//void Main::Init() {
//    m_eventFactory.add<events::Chest>(0);
//    m_eventFactory.add<events::ChooseRoomEvent>(1);
//    m_eventFactory.add<events::EmptyCell>(2);
//    m_eventFactory.add<events::Trap>(3);
//    //m_eventFactory.add<events::EnemyEncounter>(4);
//}

void Main::setSeed(std::size_t needSeed) {
    m_seed = needSeed;
}

size_t Main::getSeed() {
    return m_seed;
}

events::Event* Main::getEvent() {
    int id = my_rand<events::Event>(getSeed(), m_eventFactory);
    return m_eventFactory.create(id);
}

entity::Entity* Main::getEnemy() {
    int id = my_rand<entity::Entity>(getSeed(), m_enemiesFactory);
    return m_enemiesFactory.create(id);
}
items::Item* Main::getItem() {
    int id = my_rand<items::Item>(getSeed(), m_itemsFactory);
    return m_itemsFactory.create(id);
}

entity::Boss* Main::getBoss() {
    int id = my_rand<entity::Boss>(getSeed(), m_bossesFactory);
    return m_bossesFactory.create(id);
}

entity::Hero* Main::getHero() {
    int id = my_rand<entity::Hero>(getSeed(), m_heroesFactory);
    return m_heroesFactory.create(id);
}

entity::NPC* Main::getNPC() {
    int id = my_rand<entity::NPC>(getSeed(), m_npcFactory);
    return m_npcFactory.create(id);
}

//Player *Main::getGame() {
//    auto map = std::make_shared<Map>(12);
//    auto monitor = std::make_shared<Monitor>();
//    Player* player = new Player(map, monitor);
//    return player;
//}