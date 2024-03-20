//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_ACTION_H
#define CPPDUNGEON_ACTION_H
#include <string>
class Player;

namespace actions {
    class Action {
    public:
        virtual void act(Player *) = 0;
        virtual std::string getName() = 0;
        virtual ~Action() = default;
    };
} // namespace actions
#endif //CPPDUNGEON_ACTION_H