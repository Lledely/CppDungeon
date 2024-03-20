//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ENEMYENCOUNTER_H
#define UNTITLED_ENEMYENCOUNTER_H
#include "entity/Entity.h"
#include "events/Event.h"
#include "changers/SquadChanger.h"
#include "changers/EffectChanger.h"
#include "Squad.h"
#include "BattleField.h"
#include <vector>
#include "namespaces/entity.h"
#include <queue>
class Player;
namespace events {
class EnemyEncounter : public Event, public SquadChanger, public changers::EffectChanger, public std::enable_shared_from_this<EnemyEncounter> {
    public:
        EnemyEncounter();
        void turn(Player* player) override;
        bool getIsInBattle();
        std::shared_ptr<entity::Entity> getLastToMove();
        std::shared_ptr<Squad> getEnemies();
        std::vector<std::vector<char>> draw() override;
        std::shared_ptr<BattleField> getBattleField();
    private:
        void _refreshPriority();
        void _enemyMove(Player *, std::shared_ptr<entity::Entity>, int rank, std::shared_ptr<BattleField> battleField);
        bool _checkAlive(std::vector<std::shared_ptr<entity::Entity>>);
        bool m_isInBattle;
        std::shared_ptr<Squad> m_enemies;
        std::queue<std::shared_ptr<entity::Entity>> m_priority;
        std::shared_ptr<BattleField> m_battleField;
        std::shared_ptr<entity::Entity> m_lastToMove;
    };
} // namespace events
#endif //UNTITLED_ENEMYENCOUNTER_H
