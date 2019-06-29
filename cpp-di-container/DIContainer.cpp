#include "pch.h"

#include <typeinfo>

#include "DIContainer.h"

// �萔����Ԃ�
#define STR(var) #var 

/*
  �ǉ�
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // �ǉ��ς݊m�F
    if (diMaps.find(name) != diMaps.end()) {
        throw EXITS_NAME;
    }

    // �ǉ�
    diMaps[name] = function;
}

/*
  �G���[���̕�������擾
*/
std::string DIContainer::GetErrorName(DIContainer::DI_ERROR errorCode)
{
    switch (errorCode) {
    case EXITS_NAME:
        return STR(EXITS_NAME);

    case NOT_EXITS_NAME:
        return STR(NOT_EXITS_NAME);

    default:
        return STR(UNKNOWN_ERROR);

    }

}

// ���̉�
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
