//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_HALL_H
#define UNTITLED_HALL_H
#include "navigation/Cell.h"
class Hall:public Cell{
    bool m_used = false;
public:
    void generateEvents() override;
};
#endif //UNTITLED_HALL_H
