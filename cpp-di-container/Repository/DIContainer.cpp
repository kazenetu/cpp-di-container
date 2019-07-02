#include "DIContainer.h"

#include <typeinfo>


/*
  追加
*/
void DIContainer::Register(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // 追加済み確認
    if (container.find(name) != container.end()) {
        throw DIContainerError::Create(DIContainerError::EXITS_NAME, name, "");
    }

    // 追加
    container[name] = function;
}

// 実体化
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::container{};
