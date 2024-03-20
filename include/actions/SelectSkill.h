//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_SELECTSKILL_H
#define MONITORTEST_SELECTSKILL_H
#include "actions/Action.h"
#include "namespaces/entity.h"
#include "namespaces/battlefield.h"
#include "changers/ActionsChanger.h"
#include "namespaces/skillDesigns.h"
class Player;
namespace actions {

    class SelectSkill: public Action, public changers::ActionsChanger{
    public:
        SelectSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<entity::Entity> actor, std::shared_ptr<BattleField> battleField);
        void act(Player *) override;
        std::string getName() override;
    private:
        std::shared_ptr<skillDesigns::RangeSkill> m_skill;
        std::shared_ptr<entity::Entity> m_entity;
        std::shared_ptr<BattleField> m_battleField;
    };

} // actions
#endif //MONITORTEST_SELECTSKILL_H
