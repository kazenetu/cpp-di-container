#pragma once

#include<memory>
#include<map>
#include <functional>
#include <type_traits>

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
    {
        //diMaps.insert(addValue);
        //diMaps[addValue.first] = addValue.second;
        diMaps[name] = function;
    }

    template<class T>
    static std::unique_ptr<T> Create(std::string name)
    {
        auto instance = reinterpret_cast<T*>(DIContainer::diMaps[name]());
        auto result = std::make_unique<T>(*instance);
        //delete instance;
        return std::move(result);
    }

    static std::unique_ptr<IObject> CreateA(std::string name)
    {
        auto instance = DIContainer::diMaps[name]();
        auto result = std::make_unique<IObject>(*instance);
        return result;
    }


private:
    //static std::map<std::string, std::function<std::unique_ptr<IObject>()>> diMaps;
    //static std::map<std::string, std::function<IObject*()>, std::less<>> diMaps;
    static std::map<std::string, std::function<IObject*()>> diMaps;
    //static std::map<std::string, std::function<IObject*()>> diMaps;
    //static std::map<std::string, IObject(void)> diMaps;
};



#endif //DICONTAINER_H

