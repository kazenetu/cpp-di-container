#include "DIContainer.h"

#include <typeinfo>


/*
  í«â¡
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // í«â¡çœÇ›ämîF
    if (diMaps.find(name) != diMaps.end()) {
        throw std::move(std::make_unique<DIContainerError>(DIContainerError::EXITS_NAME, name, ""));
    }

    // í«â¡
    diMaps[name] = function;
}

// é¿ëÃâª
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
