#include "heroes/Musketeer/SkeetShot.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Buff.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Musketeer {
        SkeetShot::SkeetShot() : RangeSkill(2, "SkeetShot", {3, 4}, {}, {1, 2, 3, 4}, 95, 2) {}

        void SkeetShot::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -80), battleField, crited, 100);
            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Bleed>
            (crited, 3, 1), battleField, crited, 100);
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 3, std::map<int, int>{{static_cast<int>(Characteristic::speed), 2}}), battleField, crited, 100);
        }

        void SkeetShot::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Musketeer
} // namespace Heroes