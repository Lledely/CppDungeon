#include "heroes/Musketeer/Buckshot.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Bleed.h"
#include "effects/ForceMove.h"
namespace Heroes {
    namespace Musketeer {
        Buckshot::Buckshot() : RangeSkill(2, "Buckshot", {3, 4}, {}, {1, 2, 3, 4}, 95, 2) {}

        void Buckshot::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateHeroDamage<effects::Damage>
            (crited, actor, -50), battleField, crited, 100);

            Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::ForceMove>
            (crited, 1), battleField, crited, 75);
        }

        void Buckshot::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {

        }
    } // namespace Musketeer
} // namespace Heroes