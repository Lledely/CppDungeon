//
// Created by Амир Кашапов on 18.03.2024.
//
#include "entity/Hero.h"
#include "heroes/CommonSkills/MoveForward.h"
#include "heroes/CommonSkills/MoveBackward.h"
entity::Hero::Hero(std::string name, std::map<int, int> characteristics,
                   std::set<std::shared_ptr<skillDesigns::Skill>> skills): Entity(name, characteristics, skills) {
                        skills.insert(std::make_shared<Heroes::MoveForward>());
    skills.insert(std::make_shared<Heroes::MoveBackward>());
                   }