//
// Created by artem on 13.03.2024.
//
#include "effects/AutoAction.h"
#include "effects/MarkedAsTurnable.h"
#include "entity/Entity.h"
#include "changers/EntityChanger.h"
#include <stdexcept>

namespace effects {
    AutoAction::AutoAction(int numberOfTurns, const std::map<int, int>& turner):
 m_turner(turner), MarkedAsTurnable(numberOfTurns), MarkedAsEndBattle(-1) {}

    std::map<int, int> AutoAction::getTurner() {
        return m_turner;
    }
    std::function<int()> AutoAction::getTurnFunction() {
        throw std::logic_error("Adapter called unneeded function or function called without adapter");
    }
    std::function<int(const std::shared_ptr<entity::Entity>& )> AutoAction::getTurnFunctionEntity() {
        return [turn = this->MarkedAsTurnable::getTurnFunction(), &turner = this->m_turner]
        (const std::shared_ptr<entity::Entity>& object){
            for(auto &characteristic:turner){
                set(object, characteristic.first, object->getReal(characteristic.first) + characteristic.second);
            }
            return turn();
        };
    }

} // namespace effects