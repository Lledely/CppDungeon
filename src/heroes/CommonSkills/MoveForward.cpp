#include "heroes/CommonSkills/MoveForward.h"
#include "generators/EffectGenerator.h"
#include "effects/Move.h"

namespace Heroes {
        MoveForward::MoveForward() : RangeSkill(0, "MoveForward", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100, 0) {}

        void MoveForward::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {

        }

        void MoveForward::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::Move>
                    (crited, -1), battleField, crited, 100);

        }

} // namespace enemies