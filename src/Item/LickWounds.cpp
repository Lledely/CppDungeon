//
// Created by kait on 3/19/24.
//
#include "generators/EffectGenerator.h"
#include "items/LickWounds.h"
#include "skillDesigns/Skill.h"
#include "skillDesigns/RangeSkill.h"
#include "effects/Heal.h"
namespace items {
    namespace LickWounds{
        LickWounds::LickWounds() : Item(0, "Lick Wounds", {2, 3, 4},
                                                            {1, 2, 3, 4}, {}, 100) {}

        void LickWounds::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                          std::shared_ptr<entity::Entity> actor,
                                          std::shared_ptr<entity::Entity> object) {}

        void LickWounds::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                        std::shared_ptr<entity::Entity> object) {
            skillDesigns::Skill::addEffect(object, generators::EffectGenerator::generateImmediateCharacteristicEffect<effects::Heal>
                    (crited, 4, 4), battleField, crited, 100);
        }
        std::string LickWounds::drawItem(){
            return "Fortifying Garlic - Heal 4";
        }
    } // namespace LickWounds
} // namespace items