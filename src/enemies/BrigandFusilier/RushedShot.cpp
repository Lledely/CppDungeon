//
// Created by Амир Кашапов on 18.03.2024.
//
#include "enemies/BrigandFusilier/RushedShot.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Move.h"
namespace enemies {
    namespace BrigandFusilier {
        RushedShot::RushedShot(): RangeSkill(1, "Rushed Shoot", {1}, {}, {1, 2, 3}, 63, 6) {}

        void RushedShot::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 2, 4), battleField, crited, 100);

        }
        void RushedShot::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::Move>
            (crited, 1), battleField, crited, 100);
        }
    } // namespace BrigandFusilier
} // namespace enemies