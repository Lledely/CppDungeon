//
// Created by kait on 3/8/24.
//
#include "navigation/Cell.h"
#include "actions/MoveLeft.h"
#include "actions/MoveRight.h"

void Cell::freeMoves(Player * player, events::Event* event) {
    m_endedEvents.insert(event);
    if (m_endedEvents.size() == getEvents().size()) {
        addUniqueAction(player, std::make_shared<actions::MoveLeft>());
        addUniqueAction(player, std::make_shared<actions::MoveRight>());
    }
}

void Cell::freeMoves(Player * player) {
    if (m_endedEvents.size() == getEvents().size()) {
        addUniqueAction(player, std::make_shared<actions::MoveLeft>());
        addUniqueAction(player, std::make_shared<actions::MoveRight>());
    }
}

char Cell::getLevel() {
    char a = '5';
    return a;
}

std::vector<std::shared_ptr<events::Event>> Cell::getEvents(){
    return m_events;
}