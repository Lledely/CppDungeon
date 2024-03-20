#ifndef UGABUGA_EFFECTGENERATOR_H
#define UGABUGA_EFFECTGENERATOR_H
#include "effects/Effect.h"
#include "generators/NumberGenerator.h"
#include "entity/Entity.h"
#include <memory>
namespace generators {
    class EffectGenerator {
    public:
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args);
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateHeroDamage(int crited, std::shared_ptr<entity::Entity> entity, int damageModifier, Args... args);
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args);
        template<class effectType, typename ...Args>
        static std::shared_ptr<effectType> generateUncritedEffect(int crited, Args... args);
    };
    template<class effectType, typename ...Args>
    std::shared_ptr<effectType> EffectGenerator::generateImmediateCharacteristicEffect(int crited, int minCharacteristics, int maxCharacteristics, Args... args) {
        if(crited>=0){
            return std::make_shared<effectType>(maxCharacteristics * 150.0 / 100.0, args...);
        }
        else{
            int caracteristics = generators::NumberGenerator::generate(minCharacteristics, maxCharacteristics);
            return std::make_shared<effectType>(caracteristics);
        }
    }

    template<class effectType, typename ...Args>
    std::shared_ptr<effectType>
    EffectGenerator::generateHeroDamage(int crited, std::shared_ptr<entity::Entity> entity, int damageModifier, Args ...args) {
        if(crited>=0){
            return std::make_shared<effectType>(static_cast<double>(entity->get(Characteristic::maxDamage)) * 150.0 / 100.0 * (100.0 + damageModifier) / 100.0, args...);
        }
        else{
            int caracteristics = generators::NumberGenerator::generate(entity->get(Characteristic::minDamage), entity->get(Characteristic::maxDamage));
            return std::make_shared<effectType>(static_cast<double>(caracteristics) * (100.0 + damageModifier) / 100.0);
        }
    }
    template<class effectType, typename ...Args>
    std::shared_ptr<effectType>
    EffectGenerator::generateNumberOfTurnsEffect(int crited, int numberOfTurns, Args... args) {
        if(crited>=0){
            return std::make_shared<effectType>(numberOfTurns * 150.0 / 100.0, args...);
        }
        else{
            return std::make_shared<effectType>(numberOfTurns, args...);
        }
    }

    template<class effectType, typename ...Args>
    std::shared_ptr<effectType>
    EffectGenerator::generateUncritedEffect(int crited, Args ...args) {
        if(crited>=0){
            return std::make_shared<effectType>(args...);
        }
        else{
            return std::make_shared<effectType>(args...);
        }
    }
} // namespace generators
#endif //UGABUGA_EFFECTGENERATOR_H