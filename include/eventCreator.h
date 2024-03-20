//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_CREATIR_H
#define CPPDUNGEON_CREATIR_H
#include "abstractEventCreator.h"
template <class Object, class Base>
class Creator: public AbstractCreator<Base>
{
public:
    Creator() { }
    virtual ~Creator()	{}
    Base * create() const { return new Object(); }
};
#endif //CPPDUNGEON_CREATIR_H
