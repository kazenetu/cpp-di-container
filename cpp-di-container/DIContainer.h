#pragma once

#include<memory>
#include<map>
#include <functional>

#include "IObject.h"

#ifndef DICONTAINER_H
#define DICONTAINER_H

class DIContainer
{
public:

    static void AddMap(std::string name, std::function<std::unique_ptr<IObject>()> function)
        //static void AddMap(std::string name, std::function<IObject()> function)
        //static void AddMap(std::pair<std::string , IObject(void)> addValue)
    {
        //diMaps.insert(addValue);
        //diMaps[addValue.first] = addValue.second;
        diMaps[name] = function;
    }

    template<class T>
    static T Create(std::string name);

private:
    static std::map<std::string, std::function<std::unique_ptr<IObject>()>> diMaps;
    //static std::map<std::string, std::function<IObject()>> diMaps;
    //static std::map<std::string, IObject(void)> diMaps;
};

#endif //DICONTAINER_H

