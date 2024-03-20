//
// Created by kait on 3/11/24.
//
#include "navigation/Room.h"
#include "events/EmptyCell.h"
#include "events/ChooseRoomEvent.h"
#include "events/Chest.h"
#include "generators/NumberGenerator.h"
#include <vector>


void Room::generateEvents(){

    if(m_used){
        return;
    }
    m_used = true;
    /*if(generators::NumberGenerator::generate(0, 1) == 1) {
        m_events.push_back(std::shared_ptr<events::Event>(new events::EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<events::Event>(new events::Chest));
    }
    if(generators::NumberGenerator::generate(0, 1) == 1) {
        m_events.push_back(std::shared_ptr<events::Event>(new events::EmptyCell));
    }else{
        m_events.push_back(std::shared_ptr<events::Event>(new events::Chest));
    }*/

    m_events.push_back(std::make_shared<events::ChooseRoomEvent>());
}
