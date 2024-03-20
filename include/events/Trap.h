//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_TRAP_H
#define CPPDUNGEON_TRAP_H
#include "events/UsableEvent.h"
#include "changers/EffectChanger.h"
class Player;
namespace events {
class Trap : public events::UsableEvent, public changers::EffectChanger, public std::enable_shared_from_this<Trap>{
    public:
        void turn(Player *player) override;
        void use(Player *player) override;
        void dontUse(Player *player);
        std::vector<std::vector<char>> draw() override;
        ~Trap() override = default;
    private:
        bool comp(std::set<std::shared_ptr<actions::Action>>::iterator actionIterator);
        int m_range_use_start = 0;
        int m_range_use_finish = 3;
        int m_range_dontUse_start = 0;
        int m_range_dontUse_finish = 2;
        bool m_used = false;
//    /-----------------\
//    |                 |
//    |                 |
//    |                 |
//    |                 |
//    |                 |
//    |      __0__      |
//    |     /     \     |
//    |    / 0 0 0 \    |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   | 0     0 |   |
//    |   |  0 0 0  |   |
//    |    \-------/    |
//    |                 |
//    |                 |
//    |                 |
//    |                 |
//    |                 |
//    \-----------------/
        std::vector<std::vector<char>> m_drawing = {{'/','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\\',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ','_','_','0','_','_',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ','\\',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ','/',' ','0',' ','0',' ','0',' ','\\',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ','|',' ','0',' ',' ',' ',' ',' ','0',' ','|',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ','|',' ','0',' ',' ',' ',' ',' ','0',' ','|',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ','|',' ','0',' ',' ',' ',' ',' ','0',' ','|',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ','|',' ',' ','0',' ','0',' ','0',' ',' ','|',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ','\\','-','-','-','-','-','-','-','/',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' '},
                                                    {'\\','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','/',' '}};
    };
} // namespace events
#endif //CPPDUNGEON_TRAP_H
