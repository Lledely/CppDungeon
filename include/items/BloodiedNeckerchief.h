//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_BLOODIEDNECKERCHIEF_H
#define UGABUGA_BLOODIEDNECKERCHIEF_H
#include "skillDesigns/Skill.h"
#include "skillDesigns/RangeSkill.h"
#include "items/Item.h"
namespace items{
    namespace BloodiedNeckerchief{
        class BloodiedNeckerchief :public Item{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            BloodiedNeckerchief();
            std::string drawItem() override;
        };
    }// namespace BloodiedNeckerchief
}//namespace items
#endif //UGABUGA_BLOODIEDNECKERCHIEF_H
