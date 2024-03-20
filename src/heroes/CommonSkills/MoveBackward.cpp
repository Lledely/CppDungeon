#include "heroes/CommonSkills/MoveBackward.h"
#include "generators/EffectGenerator.h"
#include "effects/Move.h"

namespace Heroes {
        MoveBackward::MoveBackward() : RangeSkill(0, "MoveBackward", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void MoveBackward::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

        }

        void MoveBackward::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::Move>
                    (crited, 1), battleField, crited, 100);

        }

} // namespace enemies