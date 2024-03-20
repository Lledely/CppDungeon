//
// Created by kait on 3/3/24.
//
#include "actions/DontUse.h"

#include <utility>
#include "events/Trap.h"

namespace actions {
    DontUse::DontUse(const std::shared_ptr<events::Trap>& trap) : m_trap(trap){}

    void DontUse::act(Player *player) {
        m_trap->dontUse(player);
    }

    std::shared_ptr<events::Trap> DontUse::getTrap() const {
        return m_trap;
    }

    std::string DontUse::getName() {
        return "Dont Use Trap(Known damage)";
    }

    bool DontUse::operator==(const actions::DontUse &dontUse) const {
        return m_trap == dontUse.m_trap;
    }
}//namespace actions