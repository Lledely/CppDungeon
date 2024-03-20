//
// Created by Амир Кашапов on 26.02.2024.
//

#ifndef CPPDUNGEON_DONTUSE_H
#define CPPDUNGEON_DONTUSE_H

#include "actions/Action.h"
#include <memory>
#include "namespaces/events.h"
namespace actions {
    class DontUse : public Action {
    public:
        explicit DontUse(const std::shared_ptr<events::Trap>& trap);
        void act(Player *player) override;
        std::string getName() override;
        std::shared_ptr<events::Trap> getTrap() const;
        bool operator==(const actions::DontUse &moveRight) const;
    private:
        std::shared_ptr<events::Trap> m_trap;
    };
}//namespace actions
#endif //CPPDUNGEON_DONTUSE_H