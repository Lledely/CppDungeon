//
// Created by kait on 3/19/24.
//
#include "actions/UseItem.h"
#include "items/Item.h"
#include "BattleField.h"
#include "Squad.h"
namespace actions{
    UseItem::UseItem(std::shared_ptr<items::Item> skill, std::shared_ptr<BattleField> battleField,
                       std::shared_ptr<entity::Entity> actor, std::vector<std::shared_ptr<entity::Entity>> objects):
            UseSkill(skill, battleField, actor, objects){}

    void UseItem::act(Player *player) {
        m_skill -> use(m_battleField, m_actor, m_objects);
        if(auto item = std::dynamic_pointer_cast<items::Item>(m_skill)) {
            removeItem(player, item);
        }
    }

    std::string UseItem::getName() {
        std::string positions;
        for(auto i:m_objects){
            positions+=std::to_string(m_battleField->getSquad(i)->getIndex(i))+" ";
        }
        return "Use item " + m_skill->getName() + " on " +
               (m_battleField->areAllies(m_actor, m_objects[0])?"allies":"enemies") + " on " + positions + "positions";
    }
} // namespace actions