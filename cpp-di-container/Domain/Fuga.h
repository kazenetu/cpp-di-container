#pragma once

#ifndef FUGA_H
#define FUGA_H

#include<memory>
#include <iostream>

#include "IFuga.h"

/*
  IFugaインターフェースの実装クラス
*/
class Fuga :public IFuga
{
public:
    /*
      インスタンス作成
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<Fuga>();
    }

    void Initialize() {
        std::cout << "Initialize Fuga:" << this << std::endl;
    }

    void FugaMethod() {
        std::cout << "Fuga!" << std::endl;
    }
};

#endif //FUGA_H
