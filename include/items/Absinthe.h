//
// Created by kait on 3/19/24.
//
#ifndef UGABUGA_ABSINTHE_H
#define UGABUGA_ABSINTHE_H
#include "skillDesigns/Skill.h"
#include "items/Item.h"
namespace items{
    namespace Absinthe{
        class Absinthe :public Item{
        public:
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
            Absinthe();
            std::string drawItem() override;
        };
    }// namespace Absinthe
}//namespace items
#endif //UGABUGA_ABSINTHE_H
