//
// Created by Амир Кашапов on 25.02.2024.
//

#ifndef CPPDUNGEON_USESKILL_H
#define CPPDUNGEON_USESKILL_H
#include "actions/Action.h"
#include <vector>
#include <memory>
#include "namespaces/entity.h"
#include "skillDesigns/RangeSkill.h"

namespace actions {
    class UseSkill : public Action {
    public:
        UseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                 std::vector<std::shared_ptr<entity::Entity>> objects);
        void act(Player *) override;
        std::string getName() override;
    private:
        std::shared_ptr<skillDesigns::RangeSkill> m_skill;
        std::shared_ptr<BattleField> m_battleField;
        std::shared_ptr<entity::Entity> m_actor;
        std::vector<std::shared_ptr<entity::Entity>> m_objects;
    };
} // namespace actions
#endif //CPPDUNGEON_USESKILL_H
