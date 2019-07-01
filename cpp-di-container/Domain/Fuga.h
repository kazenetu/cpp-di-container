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
      クラス名を返す
    */
    static std::string GetInfoName()
    {
        return typeid(Fuga).name();
    }

    void Initialize() {
        std::cout << "Initialize Fuga:" << this << std::endl;
    }

    void FugaMethod() {
        std::cout << "Fuga!" << std::endl;
    }
};

#endif //FUGA_H
