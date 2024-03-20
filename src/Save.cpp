#include "Save.h"
#include "navigation/Cell.h"
#include "events/Event.h"
#include "events/Chest.h"
#include "events/EnemyEncounter.h"
#include "events/EmplyCell.h"
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

std::string Save::save(std::string fileName, std::shared_ptr<Player> player, std::shared_ptr<Map> map) {
    if (fileName.size() < 5) {
        return "Incorrect file name";
    }
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
        std::vector<events::EnemyEncounter> eEncounters;
        std::vector<events::EmptyCell> emptyCell;
        std::vector<events::Chest> endedChest;
        std::vector<events::EnemyEncounter> endedEnemyEncounters;
        std::vector<events::EmptyCell> endedEmplyCell;
        for (auto j: i) {
            for (auto event: j->m_events) {
                if (auto evt = std::dynamic_pointer_cast<events::Chest>(event))
                    chests.push_back(*evt);
                else if (auto evt = std::dynamic_pointer_cast<events::EnemyEncounter>(event)) {
                    eEncounters.push_back(*evt);
                }
                else if (auto evt = std::dynamic_pointer_cast<events::EmptyCell>(event)) {
                    emptyCell.push_back(*evt);
                }
            }
            for (auto event: j->m_endedEvents) {
                if (auto evt = std::dynamic_pointer_cast<events::Chest>(event))
                    endedChest.push_back(*evt);
                else if (auto evt = std::dynamic_pointer_cast<events::EnemyEncounter>(event)) {
                    endedEnemyEncounters.push_back(*evt);
                }
                else if (auto evt = std::dynamic_pointer_cast<events::EmptyCell>(event)) {
                    endedEmplyCell.push_back(*evt);
                }
            }
        }
        jsn["Map"]["Cells"][] = {
            {"Events", {
                {"Chests", chests}, 
                {"EnemyEncounters", eEncounters}, 
                {"EmptyCells", emptyCell}
            }},
            {"EndedEvents", {
                {"Chests", endedChest}, 
                {"EnemyEncounters", endedEnemyEncounters}, 
                {"EmptyCells", endedEmplyCell}
            }}
        }
    }

    file << jsn;
    file.close();
    return "Saved successfully!";
}