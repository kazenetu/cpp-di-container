#pragma once

#ifndef FUGA_H
#define FUGA_H

#include<memory>
#include <iostream>

#include "IFuga.h"

class Fuga :public IFuga
{
public:
    /*
      �C���X�^���X�쐬
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<Fuga>();
    }

    void Created() {

    }

    void FugaMethod() {
        std::cout << "Fuga!" << std::endl;
    }
};

#endif //FUGA_H
