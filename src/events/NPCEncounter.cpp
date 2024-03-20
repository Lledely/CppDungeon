//
// Created by Амир Кашапов on 20.03.2024.
//

#include "events/NPCEncounter.h"
#include "heroes/PlagueDoctor/PlagueDoctor.h"
#include "Squad.h"
#include <memory>
#include <exception>
namespace events {
    void NPCEncounter::use(Player *player) {
        try {
            add(player->getSquad(), std::make_shared<NPC::PlagueDoctor::PlagueDoctor>());
        }
        catch (std::exception) {}
        removeAction(player, [this](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return comp(actionIterator);});
        m_used = true;
    }

    std::vector<std::vector<char>> NPCEncounter::draw() {
        if(!m_used){
            NPC::PlagueDoctor::PlagueDoctor doctor;
            return doctor.draw();
        }
        else{
            std::vector<std::string> strings =
                    {"                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   ",
                     "                   "};
            std::vector<std::vector<char>> toReturn;
            for(auto str:strings){
                toReturn.push_back(std::vector<char>());
                std::copy(str.begin(), str.end(), std::back_inserter(toReturn.back()));
            }
            return toReturn;
        }
    }

} // events