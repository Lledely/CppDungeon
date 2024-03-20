//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_EMPTYCELL_H
#define CPPDUNGEON_EMPTYCELL_H
#include "events/Event.h"
namespace events {
    class EmptyCell : public Event {
        void turn(Player *player) override;

        std::vector<std::vector<char>> draw() override;
    };
} // namespace events
#endif //CPPDUNGEON_EMPTYCELL_H
