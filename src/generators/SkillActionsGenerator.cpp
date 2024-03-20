//
// Created by kait on 3/19/24.
//
#include "generators/SkillActionsGenerator.h"
#include "BattleField.h"

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    std::vector<T> vec(first, last);
    return vec;
}

std::set<std::shared_ptr<actions::UseSkill>>
generators::SkillActionsGenerator::generateAvailableUseSkills(std::shared_ptr<skillDesigns::RangeSkill> skill,
                                                              std::shared_ptr<BattleField> battleField,
                                                              std::shared_ptr<entity::Entity> actor) {
    std::set<std::shared_ptr<actions::UseSkill>> answer;
    std::vector<std::shared_ptr<entity::Entity>> temp = battleField -> getEntities();
    if(skill->getSize()==0){
        if(skill->isUsable(battleField, actor, {}).empty()){
            answer.insert(std::make_shared<actions::UseSkill>(skill, battleField, actor,
                                                              std::vector<std::shared_ptr<entity::Entity>>{}));
        }
    }
    for(int i = 0; i < temp.size() - skill->getSize() + 1; i++){
        std::vector<std::shared_ptr<entity::Entity>> objects = slice(temp, i, i+skill->getSize());
        if(skill->isUsable(battleField, actor, objects).empty()){
            answer.insert(std::make_shared<actions::UseSkill>(skill, battleField, actor, objects));
        }
    }
    return answer;
}