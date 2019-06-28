#pragma once

#include<memory>
#include<map>
#include <functional>
#include <iostream>

#include "IObject.h"

#ifndef DICONTAINER_H
#define DICONTAINER_H

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

    static void AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function);

    /*
      �C���X�^���X��Ԃ�
    */
    template<class T>
    static std::shared_ptr<T> Create(std::string name)
    {
        // TODO ���݊m�F

        // �C���X�^���X���쐬���A�Ԃ�
        return std::static_pointer_cast<T>(DIContainer::diMaps[name]());
    }

private:
    /*
      DI�R���e�i���
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;
};



#endif //DICONTAINER_H

