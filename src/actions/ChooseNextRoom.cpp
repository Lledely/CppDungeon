//
// Created by kait on 3/12/24.
//
#include "actions/ChooseNextRoom.h"
#include "navigation/Map.h"
#include "player/Player.h"

namespace actions{
    ChooseNextRoom::ChooseNextRoom(Position room):m_room(room) {}
    void ChooseNextRoom::act(Player * player) {
        setPosition(player, player -> getMap() -> chooseNextRoom(player ->getPosition(), m_room));
    }

    Position ChooseNextRoom::getPostion() {
        return m_room;
    }

    std::string ChooseNextRoom::getName() {
        return "ChooseNextRoom" + std::to_string(m_room.getLine()) + " " +  std::to_string(m_room.getColumn());
    }

    bool ChooseNextRoom::operator==(const actions::ChooseNextRoom &other) const {
        return static_cast<const Position>(m_room) == other.m_room;
    }
} // namespace actions