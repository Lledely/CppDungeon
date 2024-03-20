//
// Created by Амир Кашапов on 15.03.2024.
//
#include <iostream>
#include "effects/Effect.h"
#include "effects/Buff.h"
#include "effects/PassiveBuff.h"
#include "effects/AutoAction.h"
#include "effects/Damage.h"
#include "entity/Entity.h"
#include "EffectTest.h"
#include "effects/Heal.h"
using namespace entity;
using namespace effects;
#include "eventfactory.h"
#include "events/Event.h"
#include "Main.h"
#include <memory>
#include "events/Chest.h"
#include "events/EmptyCell.h"
#include "events/ChooseRoomEvent.h"
#include "events/Trap.h"
#include <random>
std::mt19937 rnd(time(0));
int main(){
    Main main1 = {};
    main1.setSeed(rnd() % 100);
    events::Event* event = main1.getEvent();
    events::Chest* obj = dynamic_cast<events::Chest*>(event);
    if (obj) {
        std::cout << "Chest";
    }
    events::ChooseRoomEvent* obj1 = dynamic_cast<events::ChooseRoomEvent*>(event);
    if (obj1) {
        std::cout << "ChooseRoomEvent";
    }
    events::EmptyCell* obj2 = dynamic_cast<events::EmptyCell*>(event);
    if (obj2) {
        std::cout << "EmptyCell";
    }
    events::Trap* obj3 = dynamic_cast<events::Trap*>(event);
    if (obj3) {
        std::cout << "Trap";
    }
//    auto objectPtr = std::shared_ptr<Entity>(new Entity({{long(Characteristic::maxHP), 100}, {long(Characteristic::HP), 100}}));
//    auto effectPtr = std::shared_ptr<Effect>(new Damage(10));
//    EffectTest::addEffect(objectPtr, effectPtr);
//    std::cout << objectPtr->get(long(Characteristic::HP)) << "\n";
//    EffectTest::addEffect(objectPtr, std::shared_ptr<Effect>(new Heal(20)));
//    for(int i = 0;i<10;i++) {
//        std::cout << objectPtr->get(long(Characteristic::HP)) << "\n";
//        EffectTest::turnEffects(objectPtr);
//    }
}
