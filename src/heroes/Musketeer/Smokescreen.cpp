#include "heroes/Musketeer/Smokescreen.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace Musketeer {
        Smokescreen::Smokescreen() : RangeSkill(2, "Smokescreen", {3, 4}, {}, {3, 4}, 95, -10) {}

        void Smokescreen::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -80), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Debuff>
            (crited, 2, std::map<int, int> {{static_cast<int>(Characteristic::accuracyModifier), -15},
            {static_cast<int>(Characteristic::criticalDamageChance), -15}}), battleField, crited, 100);
        }

        void Smokescreen::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Musketeer
} // namespace Heroes