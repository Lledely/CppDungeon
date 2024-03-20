//
// Created by Амир Кашапов on 20.03.2024.
//
#include "actions/SelectSkill.h"
#include "actions/UserUseSkill.h"
#include "skillDesigns/RangeSkill.h"
#include "actions/SelectSkill.h"
#include "player/Player.h"
#include "generators/SkillActionsGenerator.h"
#include "actions/DeselectSkills.h"
namespace actions {
    SelectSkill::SelectSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<entity::Entity> entity, std::shared_ptr<BattleField> battleField):m_skill(skill), m_entity(entity), m_battleField(battleField) {}
    void SelectSkill::act(Player *player) {
        addAction(player, std::make_shared<actions::DeselectSkills>(m_entity, m_battleField));
        for(const auto& useSkill:generators::SkillActionsGenerator::generateAvailableUseSkills(m_skill, m_battleField, m_entity)){
            addAction(player, std::make_shared<UserUseSkill>(*useSkill));
        }
        removeAction(player, [](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return static_cast<bool>(std::dynamic_pointer_cast<SelectSkill>(*actionIterator));});
    }

    std::string SelectSkill::getName() {
        return "Select skill" + m_skill->draw();
    }

} // actions