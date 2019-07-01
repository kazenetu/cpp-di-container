#include "DIContainer.h"

#include <typeinfo>


/*
  追加
*/
void DIContainer::AddMap(std::string name, std::function<std::string()> function)
{
    // 追加済み確認
    if (diMaps.find(name) != diMaps.end()) {
        throw std::move(std::make_unique<DIContainerError>(DIContainerError::EXITS_NAME, name, ""));
    }

    // 追加
    diMaps[name] = function;
}

// 実体化
std::map<std::string, std::function<std::string()>> DIContainer::diMaps{};
