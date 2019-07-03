#pragma once

#ifndef HAGU_H
#define HAGU_H

#include<memory>
#include <iostream>

#include "IHagu.h"
#include "DIContainer.h"

/*
  IHagu�C���^�[�t�F�[�X�̎����N���X
*/
class Hagu :public IHagu
{
public:
    /*
      �C���X�^���X�쐬
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<Hagu>();
    }

    void Initialize() {
        std::cout << "Param None" << std::endl;
    }
    void Initialize(std::string paramString) {
        std::cout << "Param String:" << paramString.c_str() << std::endl;
    }

    void HaguMethod() {
        std::cout << "Hagu!" << std::endl;
    }
private:
};

#endif //HAGU_H
