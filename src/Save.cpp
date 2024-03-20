#include "Save.h"
#include "navigation/Cell.h"
#include "events/Event.h"
#include "events/Chest.h"
#include <fstream>
#include <nlohmann/json.hpp>

void Save::save(std::string fileName, std::shared_ptr<Player> player, std::shared_ptr<Map> map) {
    std::ofstream file(fileName);
    nlohmann::json jsn;

    int seed = map->getSeed();
    std::vector<std::vector<std::shared_ptr<Cell>>> cells = map->m_cells;
    int dimentionX = cells.size();
    int dimentionY = cells[0].size();

    jsn["Map"] = {
        {"seed", seed},
        {"dimentionX", dimentionX},
        {"dimentionY", dimentionY}
    };

    for (auto i: cells) {
        std::vector<events::Chest> chests;
        std::vector<events::Event> events;
        std::vector<events::Event> endedEvents;
        for (auto j: i) {
            for (auto event: j->m_events) {
                if (auto evt = std::dynamic_pointer_cast<events::Chest>(event))
                    events.push_back(*evt);
                else if (auto evt = std::dynamic_pointer_cast<events::EnemyEncounter>(event)) {
                    events.push_back(*evt);
                }
            }
            for (auto event: j->m_endedEvents) {
                endedEvents.push_back(*event);
            }
        }
    }

    file << jsn;
    file.close();
}