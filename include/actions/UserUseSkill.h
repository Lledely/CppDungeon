//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_USERUSESKILL_H
#define MONITORTEST_USERUSESKILL_H
#include "actions/UseSkill.h"
namespace actions {

    class UserUseSkill: public UseSkill{
    public:
        UserUseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                     std::vector<std::shared_ptr<entity::Entity>> objects);
        UserUseSkill(const UseSkill&);
        void act(Player *) override;
    };

} // actions

#endif //MONITORTEST_USERUSESKILL_H
