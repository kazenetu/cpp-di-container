#include "DIContainer.h"

#include <typeinfo>

// �萔����Ԃ�
#define STR(var) #var 

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

/*
  �G���[���̕�������擾
*/
std::string DIContainer::GetErrorName(DIContainerError::DI_ERROR errorCode)
{
    switch (errorCode) {
    case DIContainerError::EXITS_NAME:
        return STR(EXITS_NAME);

    case DIContainerError::NOT_EXITS_NAME:
        return STR(NOT_EXITS_NAME);

    case DIContainerError::CANNOT_CONVERT_TYPE:
        return STR(CANNOT_CONVERT_TYPE);

    default:
        return STR(UNKNOWN_ERROR);

    }

}

// ���̉�
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
