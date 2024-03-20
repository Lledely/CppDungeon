//
// Created by Амир Кашапов on 15.03.2024.
//
#include "generators/NumberGenerator.h"
#include "events/Trap.h"
#include "player/Player.h"
#include "events/Chest.h"
#include "actions/Use.h"
#include "navigation/Cell.h"
#include "navigation/Map.h"
#include <memory>
#include "monitor/Monitor.h"
#include "actions/Use.h"
#include "actions/DontUse.h"
#include "Squad.h"
#include "effects/Damage.h"

bool events::Trap::comp(std::set<std::shared_ptr<actions::Action>>::iterator actionIterator) {
    auto use = std::dynamic_pointer_cast<actions::Use>((*actionIterator));
    return static_cast<bool>(use && (use->getUsableEvent()).get() == this);
}

void events::Trap::turn(Player * player) {
    player->getMap()->getCell(player->getPosition())->freeMoves(player);
    player -> getMonitor() -> draw(player);
    if(!m_used) {
        addUniqueAction(player, std::make_shared<actions::Use>(Trap::shared_from_this()));
    }
    addUniqueAction(player, std::make_shared<actions::DontUse>(shared_from_this()));
}

void events::Trap::dontUse(Player *player) {
    static int random = generators::NumberGenerator::generate(m_range_dontUse_start, m_range_dontUse_finish);
    std::vector<std::shared_ptr<entity::Entity>> entities = player -> getSquad() -> getEntities();
    for(int i = 0; i < entities.size(); i++){
        addEffect(entities[i], std::make_shared<effects::Damage>(random));
    }
    player -> getMap() -> getCell(player->getPosition())->freeMoves(player, this);
}

void events::Trap::use(Player *player) {
    if(!m_used) {
        static int random = generators::NumberGenerator::generate(m_range_use_start, m_range_use_finish);
        std::vector<std::shared_ptr<entity::Entity>> entities = player->getSquad()->getEntities();
        for (int i = 0; i < entities.size(); i++) {
            addEffect(entities[i], std::make_shared<effects::Damage>(random));
        }
        removeAction(player, [this](std::set<std::shared_ptr<actions::Action>>::iterator actionIterator){return comp(actionIterator);});
//    |      __0__      |
//    |     /     \     |
//    |    / 0 0 0 \    |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   |  0 0 0  |   |
//    |    \-------/    |
//
//
//    |      __x__      |
//    |     /     \     |
//    |    / x   x \    |
//    |   |   x x   |   |
//    |   |    x    |   |
//    |   |   x x   |   |
//    |   |  x   x  |   |
//    |    \-------/    |
        m_drawing[6]  = {'|',' ',' ',' ',' ',' ',' ','_','_','x','_','_',' ',' ',' ',' ',' ',' ','|',' '};
        m_drawing[8]  = {'|',' ',' ',' ',' ','/',' ','x',' ',' ',' ','x',' ','\\',' ',' ',' ',' ','|',' '};
        m_drawing[9]  = {'|',' ',' ',' ','|',' ',' ',' ','x',' ','x',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[10] = {'|',' ',' ',' ','|',' ',' ',' ',' ','x',' ',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[11] = {'|',' ',' ',' ','|',' ',' ',' ','x',' ','x',' ',' ',' ','|',' ',' ',' ','|',' '};
        m_drawing[12] = {'|',' ',' ',' ','|',' ',' ','x',' ',' ',' ','x',' ',' ','|',' ',' ',' ','|',' '};
        player->getMap()->getCell(player->getPosition())->freeMoves(player, this);
        m_used = true;
    }
}

std::vector<std::vector<char>> events::Trap::draw() {
    return m_drawing;
}