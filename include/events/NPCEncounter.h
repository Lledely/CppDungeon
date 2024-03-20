// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_NPCENCOUNTER_H
#define MONITORTEST_NPCENCOUNTER_H
#include "events/Chest.h"
#include "SquadChanger.h"
namespace events {

    class NPCEncounter: public Chest, public SquadChanger {
        void use(Player *player) override;

        std::vector<std::vector<char>> draw() override;
    };

} // events

#endif //MONITORTEST_NPCENCOUNTER_H
