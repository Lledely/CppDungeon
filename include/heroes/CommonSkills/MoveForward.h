#include "skillDesigns/RangeSkill.h"

namespace Heroes {

        class MoveForward: public skillDesigns::RangeSkill {
        public:
            MoveForward(); 
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

} // namespace Heroes