#include <iostream>
#include <ncurses.h> 
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "changers/PositionChanger.h"
#include "actions/MoveRight.h"
#include "actions/MoveLeft.h"
#include "actions/Use.h"
#include "actions/DontUse.h"
#include "actions/ChooseNextRoom.h"
#include "enemies/BrigandFusilier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "heroes/Hellion/Hellion.h"
#include "Squad.h"
class PositionChangerAdapter: public changers::PositionChanger{
public:
    using changers::PositionChanger::setPosition;
};
int main()
{	
    raw();
    keypad(stdscr, TRUE);
	initscr();
    noecho();
    int row, col;
    getmaxyx(stdscr, row, col);
    start_color();
    refresh();
    
    auto map = std::make_shared<Map>(12);
    auto monitor = std::make_shared<Monitor>();
    std::vector<std::shared_ptr<entity::Entity>> allies;
    allies.reserve(3);
    for(int i = 0;i<2;i++){
        allies.push_back(std::make_shared<Heroes::BountyHunter::BountyHunter>());
    }
    allies.push_back(std::make_shared<Heroes::Hellion::Hellion>());
    auto alliesSquad = std::make_shared<Squad>(allies);
    auto enemiesSquad = alliesSquad;
    auto player = std::make_shared<Player>(map, monitor, enemiesSquad);

    

    while (1) {
        monitor->draw(player.get());
        char key = getch();
        if(key == 'q'){
            break;
        }
        monitor->keyEvent(key, player.get());
    }
    endwin();
	return 0;
}