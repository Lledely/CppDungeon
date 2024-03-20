#include "heroes/PlagueDoctor/BattlefieldMedicine.h"
#include "generators/EffectGenerator.h"
#include "effects/Blight.h"
#include "effects/Bleed.h"
#include "effects/Heal.h"
#include "effects/Buff.h"
#include "skillDesigns/RangeSkill.h"
#include "changers/EffectChanger.h"
namespace NPC {
    namespace PlagueDoctor {
        BattlefieldMedicine::BattlefieldMedicine(): skillDesigns::RangeSkill(1, "BattlefieldMedicine", {1, 2, 3}, {1, 2, 3}, {}, 100, 0) {}

        void BattlefieldMedicine::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                        std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object){
            addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::Heal>
            (crited, 1), battleField, crited, 100);
            addEffect(object, generators::EffectGenerator::generateNumberOfTurnsEffect<effects::Buff>
            (crited, 2,std::map<int, int> {{static_cast<int> (Characteristic::speed), 3}, {static_cast<int> (Characteristic::minDamage), 20}, 
            {static_cast<int> (Characteristic::maxDamage), 20}}), battleField, crited, 100);
        }

        void BattlefieldMedicine::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                                std::shared_ptr<entity::Entity> object) {

        }

    }
}
