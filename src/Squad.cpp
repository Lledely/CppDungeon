//
// Created by Арсений Бородулин on 10.03.2024.
//
#include "Squad.h"
#include <stdexcept>
#include <algorithm>

Squad::Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad) : m_squad(new_squad) {}
Squad::Squad(std::vector<std::shared_ptr<entity::Entity>> new_squad, int size) : Squad(std::move(new_squad)) {
    if (size < 0) { throw std::invalid_argument("size have to be positive"); }
    m_squad.resize(std::max(m_squad.size(), static_cast<unsigned long>(size)), nullptr);
}
std::vector<std::shared_ptr<entity::Entity>> Squad::getEntities() const {
    return m_squad;
}
std::shared_ptr<entity::Entity> Squad::getEntity(int index) const {
    if (index < 0 || index >= m_squad.size()) { throw std::invalid_argument("index is out of range"); }
    return m_squad[index];
}

int Squad::getIndex(const std::shared_ptr<entity::Entity>& entity) const {
    for(int i = 0; i < getEntities().size(); i++){
        if(getEntities()[i] == entity){
            return i;
        }
    }
    throw std::invalid_argument("entity is not in Squad");
}


