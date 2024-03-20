//<<<<<<< HEAD
//<<<<<<< HEAD
//=======
//=======
//>>>>>>> afb5c972db0066d864aa419f6e024a147c3e8730
//#include <iostream>
//#include "include/BattleField.h"
//#include "include/BattleFieldChanger.h"
//#include "Squad.h"
//#include "entity/Entity.h"
//#include <random>
//class Entity1: public Entity{
//public:
//    Entity1(int i): Entity({}){
//        m_name = std::to_string(i);
//    }
//};
//<<<<<<< HEAD
//>>>>>>> dev
//=======
//>>>>>>> afb5c972db0066d864aa419f6e024a147c3e8730
//
//std::map<int, int> effects::Effect::getModifier() {
//    return {};
//}
//class BattleFieldChangerAdapter:public BattleFieldChanger{
//public:
//    using BattleFieldChanger::move;
//    using BattleFieldChanger::relativeMove;
//    using BattleFieldChanger::remove;
//};
//int main() {
//    std::vector<std::shared_ptr<Entity>> allies;
//    for(int i =0;i<4;i++){
//        allies.push_back(std::shared_ptr<Entity1>(new Entity1(i)));
//    }
//    std::vector<std::shared_ptr<Entity>> enemies;
//    for(int i =4;i<8;i++){
//        enemies.push_back(std::shared_ptr<Entity1>(new Entity1(i)));
//    }
//    std::shared_ptr<Squad> sq1 = std::shared_ptr<Squad>(new Squad(allies));
//    std::shared_ptr<Squad> sq2 = std::shared_ptr<Squad>(new Squad(enemies));
//    std::shared_ptr<BattleField> battle = std::shared_ptr<BattleField>(new BattleField(sq1, sq2));
//    for(int i = 0;i<battle->getEntities().size();i++){
//        std::cout<<battle->getEntities()[i]->getName()<<" ";
//    }
//    std::cout<<"\n";
//    BattleFieldChangerAdapter::move(battle, allies[0], 3);
//    for(int i = 0;i<battle->getEntities().size();i++){
//        std::cout<<battle->getEntities()[i]->getName()<<" ";
//    }
//    return 0;
//}