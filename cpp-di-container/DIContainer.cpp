#include "pch.h"

#include <typeinfo>

#include "DIContainer.h"

/*
  追加
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // TODO 追加済み確認

    // 追加
    diMaps[name] = function;
}

// 実体化
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
