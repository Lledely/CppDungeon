#ifndef CPPDUNGEON_RANGESKILL_H
#define CPPDUNGEON_RANGESKILL_H
#include "skillDesigns/Skill.h"
namespace skillDesigns {
    class RangeSkill : public Skill {
    public:
        virtual int getSize() final;
        RangeSkill(int size, std::string name, std::vector<int> availableRank,
                   std::vector<int> availableAllyTarget = {},
                   std::vector<int> availableEnemyTarget = {},
                   int accuracy = 0, int criticalDamageChance = 0);

    protected:
        std::string isDesignUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                   std::vector<std::shared_ptr<entity::Entity>> objects) override;
        std::string isImplementationUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor, std::vector<std::shared_ptr<entity::Entity>> objects) override;

    private:
        int m_size;

    };
} // namespace skillDesigns
#endif //CPPDUNGEON_RANGESKILL_H