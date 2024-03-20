//
// Created by Амир Кашапов on 20.03.2024.
//

#include "actions/DeselectSkills.h"
#include "actions/UseSkill.h"
#include "actions/SelectSkill.h"
#include "player/Player.h"
#include "entity/Entity.h"
namespace actions {
    DeselectSkills::DeselectSkills(std::shared_ptr<entity::Entity> entity, std::shared_ptr<BattleField> battleField):m_entity(entity), m_battleField(battleField) {}
    void DeselectSkills::act(Player *player) {
        removeAction(player, [](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return static_cast<bool>(std::dynamic_pointer_cast<UseSkill>(*actionIterator));});
        for(auto skill:m_entity->getSkills()){
            if(auto rangeSkill = std::dynamic_pointer_cast<skillDesigns::RangeSkill>(skill)) {
                addAction(player, std::make_shared<SelectSkill>(rangeSkill, m_entity, m_battleField));
            }
        }
        removeAction(player, [](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return static_cast<bool>(std::dynamic_pointer_cast<DeselectSkills>(*actionIterator));});
    }
    std::string DeselectSkills::getName() {
        return "Return to selecting skills";
    }

    bool DeselectSkills::operator==(const actions::DeselectSkills &) const {
        return true;
    }
} // actions