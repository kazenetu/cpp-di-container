#pragma once

#include<memory>
#include<map>
#include <functional>

#include <typeinfo>
#include <iostream>

#include "IObject.h"

#ifndef DICONTAINER_H
#define DICONTAINER_H

class DIContainer
{
public:

    //static void AddMap(std::string name, std::function<std::unique_ptr<IObject>()> function)
        //static void AddMap(std::string name, std::function<IObject()> function)
    //static void AddMap(std::pair<std::string , IObject*(*)()> addValue)
        static void AddMap(std::string name, std::function<IObject*()> function)
        //static void AddMap(std::string name, std::function<IObject()> function)
    {
        //diMaps.insert(addValue);
        //diMaps[addValue.first] = addValue.second;
        diMaps[name] = function;
    }

    static void AddMapA(std::string name, std::function<std::unique_ptr<IObject>()> function)
    {
        diMapsA[name] = function;
    }

    static void AddMapC(std::string name, std::function<std::shared_ptr<IObject>()> function)
    {
        diMapsC[name] = function;
    }

    template<class T>
    static std::unique_ptr<T> Create(std::string name)
    {
        auto instance = reinterpret_cast<T*>(DIContainer::diMaps[name]());
        auto result = std::make_unique<T>(*instance);
        //delete instance;
        return std::move(result);
    }

    template<class T>
    static std::unique_ptr<T> CreateA(std::string name)
    {
        auto u = DIContainer::diMapsA[name]();
        auto instance = reinterpret_cast<T*>(u.get());
        auto result = std::make_unique<T>(*instance);

        u.reset();

        return std::move(result);
    }

    template<class T>
    static std::unique_ptr<T> CreateB(std::string name)
    {
        //auto instance = reinterpret_cast<T*>(DIContainer::diMaps[name]());

        auto result = std::make_unique<T>();
        //delete instance;

        std::cout << "[" << typeid(T).name() << "]" << std::endl;

        return std::move(result);
    }

    template<class T>
    static std::shared_ptr<T> CreateC(std::string name)
    {
        return std::static_pointer_cast<T>(DIContainer::diMapsC[name]());
    }


private:
    static std::map<std::string, std::function<std::unique_ptr<IObject>()>> diMapsA;
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMapsC;
    //static std::map<std::string, std::function<IObject*()>, std::less<>> diMaps;
    static std::map<std::string, std::function<IObject*()>> diMaps;
    //static std::map<std::string, std::function<IObject()>> diMaps;
    //static std::map<std::string, IObject(void)> diMaps;
};



#endif //DICONTAINER_H

