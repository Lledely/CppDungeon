#include "heroes/ManAtArms/Command.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
namespace Heroes {
    namespace ManAtArms {
        Command::Command() : RangeSkill(3, "Command", {1, 2, 3, 4}, {1, 2, 3, 4}, {}, 100) {}

        void Command::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(actor, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 4, std::map<int, int>{{static_cast<int>(Characteristic::criticalDamageChance), 4},
            {static_cast<int>(Characteristic::accuracyModifier), 5},
            {static_cast<int>(Characteristic::minDamage), 5}, {static_cast<int>(Characteristic::maxDamage), 5}
            }), battleField, crited, 100);
        }

        void Command::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace ManAtArms
} // namespace Heroes