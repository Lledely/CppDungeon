//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_TURNEVENT_H
#define MONITORTEST_TURNEVENT_H
#include "Action.h"
#include "events/Event.h"
namespace actions {
    class TurnEvent : public Action {
    public:
        explicit TurnEvent(std::shared_ptr<events::Event>);
        void act(Player *player) override;
        virtual std::string getName() override;
        bool operator==(const TurnEvent&) const;
    private:
        std::shared_ptr<events::Event> m_event;
    };
} // namespace actions
#endif //MONITORTEST_TURNEVENT_H
