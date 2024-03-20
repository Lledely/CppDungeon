//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "SquadChanger.h"
#include "Squad.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

void SquadChanger::move(const std::shared_ptr<Squad>& squad, int index1, int index2) {
    if (index1 < 0 || index1 >= squad->m_squad.size()) { throw std::invalid_argument("index is out of range"); }
    if (index2 >= squad->m_squad.size())  { index2 = static_cast<int>(squad->m_squad.size()) - 1;}
    if (index2 < 0)                     { index2 = 0; }
    if (index1 == index2) { return; }
    if (squad->m_squad[index2] == nullptr) {
        squad->m_squad[index2] = squad->m_squad[index1];
        squad->m_squad[index1] = nullptr;
        return;
    }
    int direction = (index2 -index1) / abs(index2 -index1);
    int closestNullptr = index2;
    const std::shared_ptr<entity::Entity> tempIndex1 = squad->getEntity(index1);
    squad->m_squad[index1] = nullptr;
    for(;squad->getEntity(closestNullptr) != nullptr; closestNullptr-=direction){
    };
    for(;closestNullptr!=index2;closestNullptr+=direction){
        squad->m_squad[closestNullptr] = squad->m_squad[closestNullptr + direction];
        squad->m_squad[closestNullptr + direction] = nullptr;
    }
    squad->m_squad[index2] = tempIndex1;
}


void SquadChanger::move(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>& entity, int index1) {
    for (int i = 0; i < squad->m_squad.size(); ++i) {
        if (squad->m_squad[i] == entity) {
            return SquadChanger::move(squad, i, index1);
        }
    }
    throw std::invalid_argument("entity is not in m_squad");
}
void SquadChanger::relativeMove(const std::shared_ptr<Squad>& squad, int index, int offset) {
    SquadChanger::move(squad, index, index + offset);
}
void SquadChanger::relativeMove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>& entity, int offset) {
    for (int i = 0; i < squad->m_squad.size(); ++i) {
        if (squad->m_squad[i] == entity) {
            return SquadChanger::relativeMove(squad, i, offset);
        }
    }
    throw std::invalid_argument("entity is not in m_squad");
}
void SquadChanger::remove(const std::shared_ptr<Squad>& squad, int index) {
    if (index < 0 || index >= squad->m_squad.size()) { throw std::invalid_argument("index is out of range"); }
    squad->m_squad[index] = nullptr;
}
void SquadChanger::remove(const std::shared_ptr<Squad>& squad, const std::shared_ptr<entity::Entity>& entity) {
    for (int i = 0; i < squad->m_squad.size(); ++i) {
        if (squad->m_squad[i] == entity) {
            squad->m_squad[i] = nullptr;
            return;
        }
    }
    throw std::invalid_argument("entity is not in m_squad");
}
void SquadChanger::add(const std::shared_ptr<Squad>& squad, std::shared_ptr<entity::Entity>entity, int index) {
    if (index < 0 || index >= squad->m_squad.size()) { throw std::invalid_argument("index is out of range"); }
    if (squad->m_squad[index] == nullptr) {
        squad->m_squad[index] = std::move(entity);
        return;
    }
    throw std::invalid_argument("index is not empty");
}
void SquadChanger::add(const std::shared_ptr<Squad>& squad, std::shared_ptr<entity::Entity> entity) {
    for (int i = 0; i < squad->m_squad.size(); ++i) {
        if (squad->m_squad[i] != nullptr) {
            squad->m_squad[i] = std::move(entity);
            return;
        }
    }
    throw std::length_error("m_squad is full!");
}