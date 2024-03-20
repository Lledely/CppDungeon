//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_DESELECTSKILLS_H
#define MONITORTEST_DESELECTSKILLS_H
#include "actions/Action.h"
#include "namespaces/entity.h"
#include "namespaces/battlefield.h"
#include "changers/ActionsChanger.h"
class Player;
namespace actions {

    class DeselectSkills: public Action, public changers::ActionsChanger{
    public:
        DeselectSkills(std::shared_ptr<entity::Entity> entity, std::shared_ptr<BattleField> battleField);
        void act(Player *) override;
        std::string getName() override;
        bool operator==(const DeselectSkills&) const;
    private:
        std::shared_ptr<entity::Entity> m_entity;
        std::shared_ptr<BattleField> m_battleField;
    };

} // actions

#endif //MONITORTEST_DESELECTSKILLS_H
