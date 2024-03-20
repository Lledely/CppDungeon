#include "heroes/ManAtArms/Bellow.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace ManAtArms {
        Bellow::Bellow() : RangeSkill(3, "Bellow", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 90) {}

        void Bellow::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -100), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::minDamage), -10},
            {static_cast<int>(Characteristic::dodge), -5},
            {static_cast<int>(Characteristic::speed), -5}}), battleField, crited, 100);
        }

        void Bellow::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace ManAtArms
} // namespace Heroes