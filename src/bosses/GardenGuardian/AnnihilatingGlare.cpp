#include "bosses/GardenGuardian/AnnihilatingGlare.h"
#include "generators/EffectGenerator.h"
#include "effects/Damage.h"
#include "effects/Mark.h"
#include "effects/Heal.h"
#include "effects/Bleed.h"
#include "effects/Blight.h"
namespace Bosses {
    namespace GardenGuardian {
        AnnihilatingGlare::AnnihilatingGlare() : RangeSkill(3, "AnnihilatingGlare", {1, 2, 3, 4}, {}, {1, 2, 3, 4}, 103, 12) {}

        void AnnihilatingGlare::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                    std::shared_ptr<entity::Entity> actor,
                                    std::shared_ptr<entity::Entity> object) {
            Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Damage>
            (crited, 10, 14), battleField, crited, 100);
        }

        void AnnihilatingGlare::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                  std::shared_ptr<entity::Entity> object) {
            
        }
    } // namespace GardenGuardian
} // namespace Boss