//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef CPPDUNGEON_USABLEEVENT_H
#define CPPDUNGEON_USABLEEVENT_H
#include "events/Event.h"
#include <memory>
namespace events {
    class UsableEvent: public Event{
    public:
        ~UsableEvent() override = default;
        virtual void use(Player*) = 0;
    };
} // namespace events

#endif //CPPDUNGEON_USABLEEVENT_H
