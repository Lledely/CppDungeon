//
// Created by Владимир Попов on 14.03.2024
//
#ifndef UNTITLED_BRIGANDFUSILIER_H
#define UNTITLED_BRIGANDFUSILIER_H
#include "entity/Enemy.h"
#include "enemies/BrigandFusilier/BlanketFire.h"
#include "enemies/BrigandFusilier/RushedShot.h"
namespace enemies {
    namespace BrigandFusilier {
        class BrigandFusilier : public entity::Enemy {
        public:
            std::vector<std::vector<char>> drawAlive() override;

            BrigandFusilier();
        };
    } // namespace BrigandFusilier
} // namespace enemies
#endif //BRIGANDFUSILIER_H