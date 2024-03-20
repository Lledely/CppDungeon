//
// Created by Амир Кашапов on 18.03.2024.
//

#ifndef UGABUGA_RUSHEDSHOT_H
#define UGABUGA_RUSHEDSHOT_H
#include "skillDesigns/RangeSkill.h"
namespace enemies {
    namespace BrigandFusilier {
        class RushedShot : public skillDesigns::RangeSkill {
        public:
            RushedShot();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace BrigandFusilier
} // namespace enemies
#endif //UGABUGA_RUSHEDSHOT_H
