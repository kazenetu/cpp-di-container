#include "pch.h"

#include <typeinfo>

#include "DIContainer.h"

/*
  �ǉ�
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // TODO �ǉ��ς݊m�F

    // �ǉ�
    diMaps[name] = function;
}

// ���̉�
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
