//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_ABSTRACTEVENTCREATOR_H
#define CPPDUNGEON_ABSTRACTEVENTCREATOR_H

template <class Base>
class AbstractCreator
{
public:
    AbstractCreator() {}
    virtual ~AbstractCreator(){}
    virtual Base* create() const = 0;
};
#endif //CPPDUNGEON_ABSTRACTEVENTCREATOR_H
