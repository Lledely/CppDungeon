#include "skillDesigns/RangeSkill.h"

namespace Heroes {

        class MoveBackward: public skillDesigns::RangeSkill {
        public:
            MoveBackward(); 
            
            void unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField,
                                 std::shared_ptr<entity::Entity> actor,
                                 std::shared_ptr<entity::Entity> object) override;

            void unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField,
                               std::shared_ptr<entity::Entity> object) override;
        };

} // namespace Heroes