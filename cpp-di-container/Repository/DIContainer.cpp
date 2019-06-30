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
std::string DIContainer::GetErrorName(DIContainerError &error)
{
    std::string result;

    // �G���[�R�[�h
    switch (error.GetErrorCode()) {
    case DIContainerError::EXITS_NAME:
        result += STR(EXITS_NAME);

    case DIContainerError::NOT_EXITS_NAME:
        result += STR(NOT_EXITS_NAME);

    case DIContainerError::CANNOT_CONVERT_TYPE:
        result += STR(CANNOT_CONVERT_TYPE);

    default:
        result += STR(UNKNOWN_ERROR);

    }

    // ���̎擾
    result += " name[" + error.GetName() + "]";

    // �ϊ����m�F�Ǝ擾
    auto convertType = error.GetConvertType();
    if (convertType != "") {
        result += " convert miss[" + convertType + "]";
    }

    return result;
}

// ���̉�
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
