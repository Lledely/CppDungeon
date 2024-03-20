#ifndef CPPDUNGEON_SAVE_H
#define CPPDUNGEON_SAVE_H
#include <string>
#include <memory>

class Player;
class Map;

class Save {
public:
    static void save(std::string, std::shared_ptr<Player>, std::shared_ptr<Map>);
}; 

#endif CPPDUNGEON_SAVE_H