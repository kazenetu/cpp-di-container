#pragma once

#ifndef DICONTAINER_H
#define DICONTAINER_H

#include<memory>
#include<map>
#include <functional>
#include <iostream>
#include <typeinfo>

#include "IObject.h"
#include "DIContainerError.h"

/*
  �Ȉ�DI�R���e�i
*/
class DIContainer
{
public:

    /*
      �ǉ�
    */
    static void AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function);

    /*
      �C���X�^���X��Ԃ�
    */
    template<class T>
    static std::shared_ptr<T> Create(std::string name)
    {
        // ���݊m�F
        if (diMaps.find(name) == diMaps.end()) {
            throw std::move(std::make_unique<DIContainerError>(DIContainerError::NOT_EXITS_NAME,name, ""));
        }

        // �C���X�^���X���쐬
        auto instance = DIContainer::diMaps[name]();
        auto result = std::dynamic_pointer_cast<T>(instance);

        // �C���X�^���X�`�F�b�N
        if (result == nullptr) {
            throw DIContainerError(DIContainerError::CANNOT_CONVERT_TYPE, name, typeid(T).name());
        }

        // ���������\�b�h�����s
        instance->Initialize();

        // �C���X�^���X��Ԃ�
        return result;
    }

    /*
      �G���[���̕�������擾
    */
    static std::string GetErrorName(DIContainerError &errorCode);

private:
    /*
      DI�R���e�i���
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;
};


#endif //DICONTAINER_H

