//
// Created by Амир Кашапов on 16.03.2024.
//
#include "changers/ActionsChanger.h"
#include "player/Player.h"
void changers::ActionsChanger::addAction(Player *player, const std::shared_ptr<actions::Action>& action) {
    player->m_actions.insert(action);
}
std::set<std::shared_ptr<actions::Action>>& changers::ActionsChanger::getActions(Player *player) {
    return player->m_actions;
}

void changers::ActionsChanger::removeAction(Player *player, std::shared_ptr<actions::Action>& action) {
    player->m_actions.erase(action);
}

void changers::ActionsChanger::removeAction(Player *player, std::function<bool(
        std::set<std::shared_ptr<actions::Action>>::iterator)> actionIterator) {
    auto& actions = player->m_actions;
    for (auto actionsIterator = actions.begin(); actionsIterator != actions.end();)
    {
        if (actionIterator(actionsIterator)){
            actionsIterator = actions.erase(actionsIterator);
        }
        else {
            ++actionsIterator;
        }
    }
}

void changers::ActionsChanger::returnToDefault(Player *player) {
    player->m_actions = std::set<std::shared_ptr<actions::Action>>();
}