//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_ACTIONSCHANGER_H
#define CPPDUNGEON_ACTIONSCHANGER_H
#include <functional>
#include <memory>
#include <set>
#include "player/Player.h"
#include "namespaces/actions.h"
namespace changers {
    class ActionsChanger {
    protected:
        void addAction(Player *player, const std::shared_ptr<actions::Action>& action);

        template<class ActionType>
        void addUniqueAction(Player *player, const std::shared_ptr<ActionType> &action);
        void removeAction(Player *player, std::shared_ptr<actions::Action>& action);
        void removeAction(Player *player, std::function<bool(std::set<std::shared_ptr<actions::Action>>::iterator)> actionIterator);

        void returnToDefault(Player *player);

        std::set<std::shared_ptr<actions::Action> > &getActions(Player *player);

    };
} // namespace changers

template<class ActionType>
void changers::ActionsChanger::addUniqueAction(Player *player, const std::shared_ptr<ActionType>& action) {
    for(auto existAction:player->m_actions){
        if(auto actionType = std::dynamic_pointer_cast<ActionType>(existAction)){
            if(*actionType == *action){
                return;
            }
        }
    }
    addAction(player, action);
    return;
}
#endif //CPPDUNGEON_ACTIONSCHANGER_H
