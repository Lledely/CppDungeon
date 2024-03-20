#include "actions/Use.h"
#include "events/UsableEvent.h"
namespace actions {
    Use::Use(const std::shared_ptr<events::UsableEvent>& usableEvent) : m_usableEvent(usableEvent) {}

    void Use::act(Player *player) {
        m_usableEvent->use(player);
    }
    std::shared_ptr<events::UsableEvent> Use::getUsableEvent() {
        return m_usableEvent;
    }
    std::string Use::getName() {
        return "Interact with Chest or Trap";
    }
    bool Use::operator==(const actions::Use &use) const {
        return m_usableEvent == use.m_usableEvent;
    }
}//namespace actions