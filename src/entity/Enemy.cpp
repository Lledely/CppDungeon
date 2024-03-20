#include "entity/Enemy.h"
#include "BattleField.h"
#include "changers/ActionsChanger.h"
#include "entity/Enemy.h"
#include "entity/MarkedAsAutoTurn.h"
#include "events/EnemyEncounter.h"
#include "entity/Hero.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/CultistAcolyte/CultistAcolyte.h"
#include "navigation/Map.h"
#include "player/Player.h"
#include "actions/UseSkill.h"
#include "actions/UseItem.h"
#include "generators/NumberGenerator.h"
#include "generators/SkillActionsGenerator.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
entity::Enemy::Enemy(std::string name, std::map<int, int> characteristics, std::set<std::shared_ptr<skillDesigns::Skill>> skills) : Entity(name, characteristics, skills) {}

void entity::Enemy::autoTurn(Player* player, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> self) {
    auto skills = self->getSkills();
    for (const auto& i: self->getSkills()) {
        if(auto rangeSkill = std::dynamic_pointer_cast<skillDesigns::RangeSkill>(i)){
            auto debug = i->isUsable(battleField, self, {battleField->getEnemySquad(self)->getEntity(0)});
            for(auto i :generators::SkillActionsGenerator::generateAvailableUseSkills(rangeSkill, battleField, self)){
                i->act(player);
                return;
            }
        }
    }
    throw std::logic_error("Skill not found");
}