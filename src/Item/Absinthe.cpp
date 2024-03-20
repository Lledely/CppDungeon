//
// Created by kait on 3/19/24.
//
#include "generators/EffectGenerator.h"
#include "items/LickWounds.h"
#include "items/Absinthe.h"
#include "effects/PermanentEffect.h"
namespace items {
    namespace Absinthe{
        Absinthe::Absinthe() : Item(0, "Absinthe Effect", {1, 2, 3, 4},
                                    {1, 2, 3, 4}, {}, 100) {};
        std::string Absinthe::drawItem(){
            return "Absinthe - -2 speed , 10 damage";
        }
        void Absinthe::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                       std::shared_ptr<entity::Entity> actor,
                                       std::shared_ptr<entity::Entity> object) {}

        void Absinthe::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                     std::shared_ptr<entity::Entity> object) {
            skillDesigns::Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::PermanentEffect>
                    (crited, std::map<int, int>{{static_cast<int>(Characteristic::speed), -2},
                                                {static_cast<int>(Characteristic::minDamage), 10},
                                                {static_cast<int>(Characteristic::maxDamage), 10}}), battleField, crited, 100);
        }
    } // namespace Absinthe
} // namespace items