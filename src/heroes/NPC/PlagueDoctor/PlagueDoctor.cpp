#include "heroes/PlagueDoctor/PlagueDoctor.h"
#include "changers/EntityChanger.h"
#include "entity/EnemyType.h"
#include "heroes/PlagueDoctor/BattlefieldMedicine.h"
NPC::PlagueDoctor::PlagueDoctor::PlagueDoctor():
    NPC::NPC("PlagueDoctor",
    {{static_cast<int>(Characteristic::accuracyModifier), 1}, 
    {static_cast<int>(Characteristic::dodge), 0},
    {static_cast<int>(Characteristic::defence), 1},
    {static_cast<int>(Characteristic::speed), 7},
    {static_cast<int>(Characteristic::HP), 22},
    {static_cast<int>(Characteristic::maxHP), 22},
    {static_cast<int>(Characteristic::marked), 0},
    {static_cast<int>(Characteristic::turnable), 0},
    {static_cast<int>(Characteristic::movable), 0},
    {static_cast<int>(Characteristic::enemyType), static_cast<int>(EnemyType::Human)},
    {static_cast<int>(Characteristic::minDamage), 4},
    {static_cast<int>(Characteristic::maxDamage), 7},
    {static_cast<int>(Characteristic::criticalDamageChance), 2},
    {static_cast<int>(Resistances::Stun), 20},
    {static_cast<int>(Resistances::Blight), 60},
    {static_cast<int>(Resistances::Bleed), 20},
    {static_cast<int>(Resistances::Debuff), 50},
    {static_cast<int>(Resistances::Move), 20}},

    {std::make_shared<BattlefieldMedicine>()}){}


std::vector<std::vector<char>> NPC::PlagueDoctor::PlagueDoctor::drawAlive(){
    return {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '-', '-', ':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ':', '%', '%', '%', '@', '@', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '#', '%', '%', '#', '*', '*', '+', ':', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '=', '*', '@', '@', '@', '%', '@', '@', '=', ' ', '.', ' ', ' ', '-', '*', '-'},
        {' ', ' ', '.', '%', '@', '%', '@', '@', '@', '@', '@', '@', '*', ' ', ' ', ' ', '=', '=', '*', '='},
        {' ', ' ', '+', '%', '%', '@', '@', '@', '%', '%', '%', '%', '%', '#', ' ', ' ', '.', '%', '@', '='},
        {':', '%', '%', '%', '%', '%', '@', '@', '@', '%', '@', '@', '%', '@', '#', '-', '#', '@', '%', ' '},
        {'.', '@', '@', '+', ':', ' ', '@', '@', '@', '@', '@', '%', '%', '@', '@', '@', '@', '+', ' ', ' '},
        {'.', '@', '%', '.', ' ', '*', '@', '@', '@', '@', '@', '@', '@', '%', '#', '+', ' ', ' ', ' ', ' '},
        {' ', '%', '@', '#', '*', '@', '@', '@', '@', '@', '%', '%', '@', '@', '@', '%', ':', ' ', ' ', ' '},
        {' ', '.', '*', '@', '@', '@', '@', '@', '@', '%', '@', '@', '@', '@', '@', '*', '.', ' ', ' ', ' '}
    };
};

//        .--:         
//       :%%%@@-       
//       #%%#**+:      
//     =*@@@%@@= .  -*-
//   .%@%@@@@@@*   ==*=
//   +%%@@@%%%%%#  .%@=
// :%%%%%@@@%@@%@#-#@% 
// .@@+: @@@@@%%@@@@+  
// .@%. *@@@@@@@%#+    
//  %@#*@@@@@%%@@@%:   
//  .*@@@@@@%@@@@@*.   
