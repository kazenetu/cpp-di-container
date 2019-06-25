#include "pch.h"
#include "DIContainer.h"

//void DIContainer::AddMap(std::string name, std::function<IObject> function)
////void DIContainer::AddMap(std::string name, std::unique_ptr<IObject(*)()> function)
//{
//    //DIContainer::diMaps.emplace(name, function);
//    diMaps[name] = function;
//}

template<typename T>
T DIContainer::Create(std::string name)
{
    /*
    auto result = DIContainer::diMaps[name]();
    return (T)result;
    */
    return T;
}
