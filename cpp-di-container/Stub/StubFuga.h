#pragma once

#ifndef TEST_FUGA_H
#define TEST_FUGA_H

#include<memory>
#include <iostream>

#include "../Domain/Fuga.h"

/*
  IFugaインターフェースの実装クラス
*/
class StubFuga :public Fuga
{
public:
    /*
      インスタンス作成
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
