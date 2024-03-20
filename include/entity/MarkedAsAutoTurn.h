#ifndef UNTITLED_MARKEDASAUTOTURN_H
#define UNTITLED_MARKEDASAUTOTURN_H
#include <memory>
#include "entity/Entity.h"
class Player;
class BattleField;
namespace entity {
    class MarkedAsAutoTurn{
    public:
        virtual void autoTurn(Player*, std::shared_ptr<BattleField>, std::shared_ptr<entity::Entity>) = 0;
    };
};

#endif //UNTITLED_MARKEDASAUTOTURN_H