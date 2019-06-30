#pragma once

#ifndef DICONTAINER_H
#define DICONTAINER_H

#include<memory>
#include<map>
#include <functional>
#include <iostream>

#include "IObject.h"

/*
  �Ȉ�DI�R���e�i
*/
class DIContainer
{
public:
    /*
      �G���[�p�񋓌^
    */
    enum DI_ERROR {
        EXITS_NAME = 1, 
        NOT_EXITS_NAME,
        UNKNOWN_ERROR,
    };

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
            throw NOT_EXITS_NAME;
        }

        // �C���X�^���X���쐬
        auto instance = DIContainer::diMaps[name]();
        auto result = std::dynamic_pointer_cast<T>(instance);

        // �C���X�^���X�`�F�b�N
        if (result == nullptr) {
            throw NOT_EXITS_NAME;
        }

        // ���������\�b�h�����s
        instance->Initialize();

        // �C���X�^���X��Ԃ�
        return result;
    }

    /*
      �G���[���̕�������擾
    */
    static std::string GetErrorName(DIContainer::DI_ERROR errorCode);

private:
    /*
      DI�R���e�i���
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;
};


#endif //DICONTAINER_H

