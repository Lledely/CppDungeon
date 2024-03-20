cmake_minimum_required(VERSION 3.24)
set(CMAKE_C_COMPILER "C:\\msys64\\ucrt64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\msys64\\ucrt64\\bin\\gcc.exe")
project(EnemyEncounterTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../include)

add_executable(EnemyEncounterTest
        main.cpp
        ../../src/entity/Entity.cpp
        ../../src/events/EnemyEncounter.cpp
        ../../src/effects/ForceMove.cpp
        ../../src/effects/Move.cpp
        ../../src/BattleFieldChanger.cpp
        ../../src/BattleField.cpp
        ../../src/Squad.cpp
        ../../src/SquadChanger.cpp
        ../../src/effects/ImmediateEffect.cpp
        ../../src/effects/PermanentEffect.cpp
        ../../src/changers/EffectChanger.cpp
        ../../src/effects/MarkedAsTurnable.cpp
        ../../src/effects/MarkedAsEndBattle.cpp
        ../../src/enemies/CultistAcolyte/EldritchPush.cpp
        ../../src/skillDesignes/Skill.cpp
        ../../src/skillDesignes/RangeSkill.cpp
        ../../src/generators/NumberGenerator.cpp
        ../../src/effects/Damege.cpp
        ../../src/effects/ImmediateCharacteristicEffect.cpp
        ../../src/changers/EntityChanger.cpp
        ../../src/enemies/CultistAcolyte/StressfulIncantation.cpp
        ../../src/enemies/Webber/Web.cpp
        ../../src/effects/Mark.cpp
        ../../src/effects/Stun.cpp
        ../../src/effects/Debuff.cpp
        ../../src/effects/Buff.cpp
        ../../src/enemies/Webber/Bite.cpp
        ../../src/effects/Blight.cpp
        ../../src/effects/AutoAction.cpp
        ../../src/effects/Bleed.cpp
        ../../src/enemies/BrigandFusilier/BrigandFusilier.cpp
        ../../src/enemies/BrigandFusilier/RushedShot.cpp
        ../../src/entity/Enemy.cpp
        ../../src/enemies/CultistAcolyte/CultistAcolyte.cpp
        ../../src/enemies/CultistAcolyte/EldritchPull.cpp
        ../../src/enemies/BrigandFusilier/BlanketFire.cpp
        ../../src/enemies/BrigandRaider/BrigandRaider.cpp
        ../../src/enemies/BrigandRaider/Shank.cpp
        ../../src/enemies/BrigandRaider/SliceAndDice.cpp
        ../../src/enemies/BrigandRaider/UppercutSlice.cpp
        ../../src/enemies/BrigandRaider/HarmlessPoke.cpp
        ../../src/entity/Hero.cpp
        ../../src/navigation/Map.cpp
        ../../src/navigation/Room.cpp
        ../../src/navigation/Hall.cpp
        ../../src/navigation/Position.cpp
        ../../src/player/Player.cpp
        ../../src/navigation/Cell.cpp
        ../../src/monitor/Monitor.cpp
        ../../src/entity/MarkedAsAutoTurn.cpp
        ../../src/generators/SkillActionsGenerator.cpp
        ../../src/actions/UseSkill.cpp
)
