#include "heroes/Hellion/BarbaricYAWP.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Hellion {
        BarbaricYAWP::BarbaricYAWP() : RangeSkill(2, "BarbaricYAWP", {1, 2}, {}, {1, 2}, 95, 0) {}

        void BarbaricYAWP::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -100), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff> // TODO smth with stun
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::turnable), -1}}), battleField, crited, 110);

            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::minDamage), -20},
            {static_cast<int>(Characteristic::maxDamage), -20},
            {static_cast<int>(Characteristic::speed), -3}}), battleField, crited, 100);
        }

        void BarbaricYAWP::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Hellion
} // namespace Heroes