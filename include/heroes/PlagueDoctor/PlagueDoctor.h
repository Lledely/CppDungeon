//
// Created by Амир Кашапов on 20.03.2024.
//

#ifndef MONITORTEST_PLAGUEDOCTOR_H
#define MONITORTEST_PLAGUEDOCTOR_H
#include "entity/NPC.h"
namespace NPC {
    namespace PlagueDoctor{
        class PlagueDoctor:public entity::NPC{
        public:
            std::vector<std::vector<char>> drawAlive() override;
            PlagueDoctor();
        };
    }
}
#endif //MONITORTEST_PLAGUEDOCTOR_H
