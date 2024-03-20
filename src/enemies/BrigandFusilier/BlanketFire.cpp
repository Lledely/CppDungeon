#include "enemies/BrigandFusilier/BlanketFire.h"
#include "generators/EffectGenerator.h"
#include "effects/Debuff.h"
#include "effects/Damage.h"
namespace enemies {
    namespace BrigandFusilier {
        BlanketFire::BlanketFire() : RangeSkill(3, "Blanket Fire", {2, 3, 4}, {}, {1, 2, 3, 4}, 73, 0) {}

        void BlanketFire::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 1, 3), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::dodge),-2}}), battleField, crited, 100);
        }

        void BlanketFire::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                        std::shared_ptr<entity::Entity> object) {}
    } // namespace BrigandFusilier
} // namespace enemies