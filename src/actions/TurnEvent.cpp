//
// Created by Амир Кашапов on 20.03.2024.
//
#include "actions/TurnEvent.h"
actions::TurnEvent::TurnEvent(std::shared_ptr<events::Event> event):m_event(event) {
}

void actions::TurnEvent::act(Player *player) {
    m_event->turn(player);
}

std::string actions::TurnEvent::getName() {
    return "Continue battle";
}

bool actions::TurnEvent::operator==(const actions::TurnEvent &) const {
    return true;
}