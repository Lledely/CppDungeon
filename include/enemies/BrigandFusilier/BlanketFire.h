#ifndef CPPDUNGEON_BLANKETFIRE_H
#define CPPDUNGEON_BLANKETFIRE_H
#include "skillDesigns/RangeSkill.h"
namespace enemies {
    namespace BrigandFusilier {
        class BlanketFire : public skillDesigns::RangeSkill {
        public:
            BlanketFire();

            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    } // namespace BrigandFusilier
} // namespace enemies
#endif //CPPDUNGEON_BLANKETFIRE_H