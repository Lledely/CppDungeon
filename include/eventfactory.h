//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_EVENTFACTORY_H
#define CPPDUNGEON_EVENTFACTORY_H
#include <map>
#include <set>
#include <string>
#include "eventCreator.h"
#include <vector>
template <class Base, class IdType>
class ObjectFactory
{
protected:
    std::map<IdType, AbstractCreator<Base>*> m_factory;

public:
    ObjectFactory() {}
    virtual ~ObjectFactory() = default;
    std::map<IdType, AbstractCreator<Base>*> getFactoryMap() {
        return m_factory;
    }
    template <class Object>
    void add(const IdType & id)
    {
        registerClass(id, new Creator<Object, Base>());
    }

    Base * create(const IdType   & id)
    {
        typename std::map<IdType, AbstractCreator<Base>*>::iterator it = m_factory.find(id);
        if (it != m_factory.end())
            return it->second->create();
        return 0;
    }

protected:
    void registerClass(const IdType & id, AbstractCreator<Base> * p)
    {
        typename std::map<IdType, AbstractCreator<Base>*>::iterator it = m_factory.find(id);
        if (it == m_factory.end())
            m_factory[id] = p;
        else
            delete p;
    }
};
#endif //CPPDUNGEON_EVENTFACTORY_H
