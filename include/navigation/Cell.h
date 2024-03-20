//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "events/Event.h"
#include "Save.h"
#include <vector>
class Cell: public changers::ActionsChanger{
public:
    void freeMoves(Player*, const std::shared_ptr<events::Event>&);
    virtual void generateEvents() = 0;
    std::vector<std::shared_ptr<events::Event>> getEvents();
    char getLevel();
    virtual ~Cell() = default;
    
    friend Save;
protected:
    std::vector<std::shared_ptr<events::Event>> m_events;
private:
    std::set<std::shared_ptr<events::Event>> m_endedEvents;
};
#endif //UNTITLED_CELL_H