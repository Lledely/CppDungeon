//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef CPPDUNGEON_SKILL_H
#define CPPDUNGEON_SKILL_H
#include <vector>
#include <string>
#include <memory>
#include "BattleFieldChanger.h"
#include "changers/EffectChanger.h"
#include "namespaces/entity.h"
#include "namespaces/effects.h"
#include "namespaces/battlefield.h"
namespace skillDesigns {
    class Skill : public BattleFieldChanger, public changers::EffectChanger {
    public:
        virtual ~Skill() = default;

        Skill(std::string name, std::vector<int> availableRank,
        std::vector<int> availableAllyTarget = {},
        std::vector<int> availableEnemyTarget = {},
        int accuracy = 0, int criticalDamageChance = 0);

        virtual std::vector<int> getAvaibleRank();

        virtual std::vector<int> getAvaibleAllyTarget();

        virtual std::vector<int> getAvaibleEnemyTarget();

        virtual std::string use(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                         std::vector<std::shared_ptr<entity::Entity>> objects) final;

        virtual std::string isUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                     std::vector<std::shared_ptr<entity::Entity>> objects) final;

        virtual std::string getName() final;

        std::string draw();

    protected:
        virtual void
        unsafeUse(int crited, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                  std::vector<std::shared_ptr<entity::Entity>> objects) final;

        virtual void
        unsafeSelfUse(int crited, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> object) = 0;

        virtual void
        unsafeTargetUse(int crited, std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                        std::shared_ptr<entity::Entity> object) = 0;

        virtual std::string
        isImplementationUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                               std::vector<std::shared_ptr<entity::Entity>> objects);

        virtual int missed(std::shared_ptr<entity::Entity> actor) final;

        virtual int dodged(std::shared_ptr<entity::Entity> actor) final;

        virtual int resisted(std::shared_ptr<entity::Entity> object, size_t effectHash, int crited) final;

        virtual int crited(std::shared_ptr<entity::Entity> actor) final;

        virtual void
        addEffect(std::shared_ptr<entity::Entity> object, std::shared_ptr<effects::Effect> effect,
                  std::shared_ptr<BattleField> battleField, int crited, int accuracyModifier = 100) final;

        int m_accuracy;
        int m_criticalDamageChance;
        std::vector<int> m_availableRank;
        std::vector<int> m_availableAllyTarget;
        std::vector<int> m_availableEnemyTarget;
        std::string m_name;

        virtual std::string
        isDesignUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                       std::vector<std::shared_ptr<entity::Entity>> objects);
    };
} // namespace skillDesigns
#endif //CPPDUNGEON_SKILL_H
