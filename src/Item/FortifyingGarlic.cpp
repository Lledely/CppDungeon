//
// Created by kait on 3/19/24.
//
#include "generators/EffectGenerator.h"
#include "items/FortifyingGarlic.h"
#include "effects/PermanentEffect.h"
namespace items {
    namespace FortifyingGarlic{
        FortifyingGarlic::FortifyingGarlic() : Item(0, "Fortifying Garlic", {1, 2, 3, 4},
                                                    {1, 2, 3, 4}, {}, 100) {}

        void FortifyingGarlic::unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                               std::shared_ptr<entity::Entity> actor,
                                               std::shared_ptr<entity::Entity> object) {}

        void FortifyingGarlic::unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                                             std::shared_ptr<entity::Entity> object) {
            skillDesigns::Skill::addEffect(object, generators::EffectGenerator::generateUncritedEffect<effects::PermanentEffect>
                    (crited, std::map<int, int>{{static_cast<int>(Resistances::Bleed), 33},
                                                {static_cast<int>(Resistances::Blight), 33}}), battleField, crited, 100);
        }
        std::string FortifyingGarlic::drawItem(){
            return "Fortifying Garlic - Bleed, Blight 33%";
        }
    } // namespace FortifyingGarlic
} // namespace items