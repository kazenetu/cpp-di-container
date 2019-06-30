#pragma once

#ifndef TEST_FUGA_H
#define TEST_FUGA_H

#include<memory>
#include <iostream>

#include "../Domain/Fuga.h"

/*
  IFuga�C���^�[�t�F�[�X�̎����N���X
*/
class StubFuga :public Fuga
{
public:
    /*
      �C���X�^���X�쐬
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<StubFuga>();
    }

    void Initialize() {
        std::cout << "Initialize TestFuga:" << this << std::endl;
    }

    void FugaMethod() {
        std::cout << "TestFuga" << std::endl;
    }
};

#endif //TEST_FUGA_H
