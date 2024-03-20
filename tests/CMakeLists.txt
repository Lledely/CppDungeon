cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include ../src)
add_executable(test
        main.cpp
        ../include/Main.h
        ../src/Main.cpp
        ../include/eventfactory.h
        ../include/eventCreator.h
        ../include/abstractEventCreator.h
        ../include/events/Event.h
        ../include/events/ChooseRoomEvent.h
        ../include/events/Chest.h
        ../include/events/EmptyCell.h
        ../include/events/Trap.h
        ../src/events/ChooseRoomEvent.cpp
        ../src/events/Chest.cpp
        ../src/events/EmptyCell.cpp
        ../src/events/Trap.cpp
        ../src/player/Player.cpp
        ../src/changers/ActionsChanger.cpp
        ../src/generators/NumberGenerator.cpp
        ../src/navigation/Map.cpp
        ../src/Squad.cpp
        ../src/navigation/Room.cpp
        ../src/navigation/Hall.cpp
        ../src/navigation/Position.cpp
        ../src/effects/Damege.cpp
        ../src/effects/ImmediateCharacteristicEffect.cpp
        ../src/changers/EntityChanger.cpp
        ../src/entity/Entity.cpp
        ../src/actions/Use.cpp
        ../src/actions/DontUse.cpp
        ../src/effects/ImmediateEffect.cpp
        ../src/changers/EffectChanger.cpp
        ../src/effects/MarkedAsEndBattle.cpp
        ../src/effects/MarkedAsTurnable.cpp
        ../src/monitor/Monitor.cpp
        ../src/navigation/Cell.cpp
        ../src/effects/PermanentEffect.cpp
#        ../src/enemies/BrigandFusilier/BrigandFusilier.cpp
#        ../src/enemies/BrigandRaider/BrigandRaider.cpp
#        ../src/enemies/CultistAcolyte/CultistAcolyte.cpp
)