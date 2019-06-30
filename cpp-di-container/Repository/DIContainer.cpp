#include "DIContainer.h"

#include <typeinfo>


/*
  �ǉ�
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // �ǉ��ς݊m�F
    if (diMaps.find(name) != diMaps.end()) {
        throw std::move(std::make_unique<DIContainerError>(DIContainerError::EXITS_NAME, name, ""));
    }

    // �ǉ�
    diMaps[name] = function;
}

// ���̉�
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
