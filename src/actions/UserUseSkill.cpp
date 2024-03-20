//
// Created by Амир Кашапов on 20.03.2024.
//

#include "actions/UserUseSkill.h"
#include "events/EnemyEncounter.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "navigation/Cell.h"
namespace actions {
    UserUseSkill::UserUseSkill(std::shared_ptr<skillDesigns::RangeSkill> skill, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                               std::vector<std::shared_ptr<entity::Entity>> objects): UseSkill(skill, battleField, actor, objects) {};
    UserUseSkill::UserUseSkill(const actions::UseSkill &useSkill): UseSkill(useSkill) {};
    void UserUseSkill::act(Player *player) {
        UseSkill::act(player);
        for(auto event:player->getMap()->getCell(player->getPosition())->getEvents()){
            if(auto enemyEncounter = std::dynamic_pointer_cast<events::EnemyEncounter>(event)){
                enemyEncounter->turn(player);
            }
        }
    }
} // actions