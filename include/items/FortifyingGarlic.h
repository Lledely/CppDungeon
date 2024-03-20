//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_FORTIFYINGGARLIC_H
#define UGABUGA_FORTIFYINGGARLIC_H
#include "skillDesigns/Skill.h"
#include "items/Item.h"
namespace items{
    namespace FortifyingGarlic{
        class FortifyingGarlic :public Item{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            FortifyingGarlic();
            std::string drawItem() override;
        };
    }// namespace FortifyingGarlic
}//namespace items

#endif //UGABUGA_FORTIFYINGGARLIC_H
