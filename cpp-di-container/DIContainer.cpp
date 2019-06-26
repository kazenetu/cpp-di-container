#include "pch.h"

#include <typeinfo>

#include "DIContainer.h"

/*
  ’Ç‰Á
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // TODO ’Ç‰ÁÏ‚İŠm”F

    // ’Ç‰Á
    diMaps[name] = function;
}

// À‘Ì‰»
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
