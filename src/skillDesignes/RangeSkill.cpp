#include "skillDesigns/RangeSkill.h"
#include "skillDesigns/Skill.h"
#include "BattleField.h"
#include "Squad.h"
#include <vector>
#include <memory>
#include <algorithm>
namespace skillDesigns {
    int RangeSkill::getSize() {
        return m_size;
    }
    RangeSkill::RangeSkill(int size, std::string name, std::vector<int> availableRank,
                           std::vector<int> availableAllyTarget,
                           std::vector<int> availableEnemyTarget, int accuracy, int criticalDamageChance) : m_size(
            size),
                                                                                                            Skill(name,
                                                                                                                  availableRank,
                                                                                                                  availableAllyTarget,
                                                                                                                  availableEnemyTarget,
                                                                                                                  accuracy,
                                                                                                                  criticalDamageChance) {}

    std::string
    RangeSkill::isDesignUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                               std::vector<std::shared_ptr<entity::Entity>> objects) {

        std::string parentRet = Skill::isDesignUsable(battleField, actor, objects);
        if (m_size == 1 && !parentRet.empty()) {
            return parentRet;
        }
        else {
            for (const auto &obj: objects) {
                if (obj && battleField->areAllies(actor, obj)) {
                    if (std::find(m_availableAllyTarget.begin(), m_availableAllyTarget.end(),
                                  battleField->getSquad(obj)->getIndex(obj)) == m_availableAllyTarget.end()) {
                        return "Can't act on some ally target";
                    }
                } else {
                    if (obj && std::find(m_availableEnemyTarget.begin(), m_availableEnemyTarget.end(),
                                  battleField->getSquad(obj)->getIndex(obj)) == m_availableEnemyTarget.end()) {
                        return "Can't act on some enemy target";
                    }
                }
            }
            return std::string();
        }
    }

    std::string
    RangeSkill::isImplementationUsable(std::shared_ptr<BattleField> battleField, std::shared_ptr<entity::Entity> actor,
                                       std::vector<std::shared_ptr<entity::Entity>> objects) {
        if(m_size==1) {
            return Skill::isImplementationUsable(battleField, actor, objects);
        }
        else {
            return "";
        }
    }
} // namespace skillDesigns