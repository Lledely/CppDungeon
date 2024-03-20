//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_BATTLEFIELDMEDICINE_H
#define MONITORTEST_BATTLEFIELDMEDICINE_H
#include "skillDesigns/RangeSkill.h"
#include "changers/EffectChanger.h"
namespace NPC {
    namespace PlagueDoctor{
        class BattlefieldMedicine:public skillDesigns::RangeSkill{
        public:
            BattlefieldMedicine();
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor, std::shared_ptr<entity::Entity> object) override;
            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };
    }
}
#endif //MONITORTEST_BATTLEFIELDMEDICINE_H
