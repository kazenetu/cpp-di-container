#include "pch.h"

#include<memory>

#include "DIContainer.h"

//void DIContainer::AddMap(std::string name, std::function<IObject> function)
////void DIContainer::AddMap(std::string name, std::unique_ptr<IObject(*)()> function)
//{
//    //DIContainer::diMaps.emplace(name, function);
//    diMaps[name] = function;
//}

//template<typename T>
//std::unique_ptr<T> DIContainer::Create(std::string name)
//{
//    auto result = std::make_unique<T>(DIContainer::diMaps[name]())();
//    return (T)result;
//}
std::map<std::string, std::function<IObject*()>> DIContainer::diMaps = {};