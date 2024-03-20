//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H
#include "navigation/Cell.h"
class Room:public Cell{
    bool m_used = false;
public:
    void generateEvents() override;
};
#endif //UNTITLED_ROOM_H
