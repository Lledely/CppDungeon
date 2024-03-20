//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_USEITEM_H
#define CPPDUNGEON_USEITEM_H
#include "actions/Action.h"
#include <vector>
#include <memory>
#include "namespaces/entity.h"
#include "namespaces/items.h"
#include "actions/Action.h"
#include <vector>
#include <memory>
#include "namespaces/entity.h"
#include "skillDesigns/RangeSkill.h"
#include "actions/UseSkill.h"
#include "changers/InventoryChanger.h"
namespace actions {
    class UseItem : public UseSkill, public changers::InventoryChanger {
    public:
        UseItem(std::shared_ptr<items::Item> skill, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                 std::vector<std::shared_ptr<entity::Entity>> objects);
        void act(Player *) override;
        std::string getName() override;
    private:
        std::shared_ptr<skillDesigns::RangeSkill> m_skill;
        std::shared_ptr<BattleField> m_battleField;
        std::shared_ptr<entity::Entity> m_actor;
        std::vector<std::shared_ptr<entity::Entity>> m_objects;
    };
} // namespace actions
#endif //CPPDUNGEON_USEITEM_H
