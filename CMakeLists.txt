cmake_minimum_required(VERSION 3.24)
project(ugabuga)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests/MapTest)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)


add_executable(CppDungeon
        main.cpp
        src/events/Chest.cpp
        src/events/EmptyCell.cpp
        src/events/ChooseRoomEvent.cpp
        include/actions/Action.h
        include/navigation/Cell.h
        include/events/Chest.h
        include/enemies/Enemy.h
        include/namespaces/Entity.h
        include/events/Event.h
        include/navigation/Hall.h
        include/heroes/Hero.h
        include/items/Item.h
        include/navigation/Map.h
        include/monitor/Monitor.h
        include/player/Player.h
        include/navigation/Room.h
        include/skillDesigns/Skill.h
        include/actions/MoveLeft.h
        include/actions/MoveRight.h
        include/actions/ChooseNextRoom.h
        include/events/ChooseRoomEvent.h
        include/events/EmptyCell.h
        include/actions/Use.h
        include/events/Trap.h
        include/actions/DontUse.h
        include/navigation/Position.h
        include/actions/UseSkill.h
        include/actions/UseItem.h
        include/enemies/Boss.h
        include/heroes/NPC.h
        include/changers/ActionsChanger.h
        include/changers/PositionChanger.h
        src/actions/Use.cpp
        src/actions/DontUse.cpp
        src/player/Player.cpp
        include/effects/Effect.h
        src/effects/Effect.cpp
        include/effects/Buff.h
        src/effects/Buff.cpp
        include/effects/Guard.h
        src/effects/Guard.cpp
        include/effects/Debuff.h
        src/effects/Debuff.cpp
        include/effects/Stun.h
        src/effects/Stun.cpp
        include/effects/PassiveBuff.h
        include/entity/trick.h
        src/effects/PassiveBuff.cpp
        include/effects/PassiveDebuff.h
        src/effects/PassiveDebuff.cpp
        include/effects/Disease.h
        src/effects/Disease.cpp
        include/effects/AutoAction.h
        src/effects/AutoAction.cpp
        include/effects/Bleed.h
        src/effects/Bleed.cpp
        include/effects/Blight.h
        src/effects/Blight.cpp
        include/effects/Damage.h
        src/effects/Damege.cpp
        include/effects/Heal.h
        src/effects/Heal.cpp
        src/entity/Entity.cpp)

