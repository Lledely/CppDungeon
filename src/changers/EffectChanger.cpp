//
// Created by Амир Кашапов on 15.03.2024.
//
#include "changers/EffectChanger.h"
#include "effects/Effect.h"
#include "entity/Entity.h"
#include "effects/ImmediateEffect.h"
#include "effects/MarkedAsEndBattle.h"
#include "effects/MarkedAsEndBattleEntityNeeded.h"
#include "effects/MarkAsEndBattleBattleFieldNeeded.h"
#include "effects/MarkedAsTurnable.h"
#include "effects/MarkedAsEntityNeeded.h"
#include "effects/MarkedAsBattleFieldNeeded.h"
#include <stdexcept>
void changers::EffectChanger::turnEffects(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<BattleField>& battlefield) {
    if(entity == nullptr){
        return;
    }
    auto& effects = entity->m_effects;
    for (auto effectIterator = effects.begin(); effectIterator != effects.end();)
    {
        if (turnEffect(entity, *effectIterator, battlefield) < 0){
            effectIterator = effects.erase(effectIterator);
        }
        else {
            ++effectIterator;
        }
    }
}

void changers::EffectChanger::endBattleTurnEffects(const std::shared_ptr<entity::Entity>& entity, const std::shared_ptr<BattleField>& battlefield) {
    if(entity == nullptr){
        return;
    }
    auto& effects = entity->m_effects;
    for (auto effectIterator = effects.begin(); effectIterator != effects.end();)
    {
        if (endBattleTurnEffect(entity, *effectIterator, battlefield) < 0){
            effectIterator = effects.erase(effectIterator);
        }
        else {
            ++effectIterator;
        }
    }
}
int changers::EffectChanger::turnEffect(const std::shared_ptr<entity::Entity>& entity,
                                        const std::shared_ptr<effects::Effect>& effect, const std::shared_ptr<BattleField>& battlefield) {
    if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsBattleFieldNeeded>(effect) != nullptr) {
        if(battlefield == nullptr) {
            throw std::logic_error("Effect requires battleField, but not provided");
        }
        return std::dynamic_pointer_cast<effects::MarkedAsBattleFieldNeeded>(effect)->getTurnFunctionBattleField()(entity, battlefield);
    }
    else if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsEntityNeeded>(effect) != nullptr) {
        return std::dynamic_pointer_cast<effects::MarkedAsEntityNeeded>(effect)->getTurnFunctionEntity()(entity);
    }
    else if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsTurnable>(effect) != nullptr) {
        return std::dynamic_pointer_cast<effects::MarkedAsTurnable>(effect)->getTurnFunction()();
    }
    else {
        return 0;
    }
}
int changers::EffectChanger::endBattleTurnEffect(const std::shared_ptr<entity::Entity>& entity,
                                                  const std::shared_ptr<effects::Effect>& effect, const std::shared_ptr<BattleField>& battlefield) {
    if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsEndBattleBattleFieldNeeded>(effect) != nullptr) {
        if(battlefield == nullptr) {
            throw std::logic_error("Effect requires battleField, but not provided");
        }
        return std::dynamic_pointer_cast<effects::MarkedAsEndBattleBattleFieldNeeded>(effect)->getEndBattleTurnFunctionBattleField()(entity, battlefield);
    }
    else if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsEndBattleEntityNeeded>(effect) != nullptr) {
        return std::dynamic_pointer_cast<effects::MarkedAsEndBattleEntityNeeded>(effect)->getEndBattleTurnFunctionEntity()(entity);
    }
    else if (entity!= nullptr && std::dynamic_pointer_cast<effects::MarkedAsEndBattle>(effect) != nullptr) {
        return std::dynamic_pointer_cast<effects::MarkedAsEndBattle>(effect)->getEndBattleTurnFunction()();
    }
    else {
        return 0;
    }
}
void changers::EffectChanger::addEffect(const std::shared_ptr<entity::Entity>& entity,
                                        std::shared_ptr<effects::Effect> effect, const std::shared_ptr<BattleField>& battlefield) {
    if (entity != nullptr && std::dynamic_pointer_cast<effects::ImmediateEffect>(effect) != nullptr) {
        turnEffect(entity, effect, battlefield);
    }
    else if(entity != nullptr) {
        entity->m_effects.insert(effect);
    }
}

void changers::EffectChanger::removeEffect(const std::shared_ptr<entity::Entity>& entity,
                                           const std::shared_ptr<effects::Effect>& effect) {
    if(entity != nullptr) {
        entity->m_effects.erase(effect);
    }
}

void changers::EffectChanger::removeEffect(const std::shared_ptr<entity::Entity>& entity, std::function<bool(
        std::set<std::shared_ptr<effects::Effect>>::iterator)> actionIterator) {
    auto& actions = entity->m_effects;
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
