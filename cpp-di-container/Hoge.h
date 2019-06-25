#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>

#include "IObject.h"

class Hoge:public IObject
{
public:
    static std::unique_ptr<IObject> Create() 
    {
        auto result = std::make_unique<Hoge>();
        return std::move(result);
    }

    Hoge() {
        std::cout << "create Hoge\n";
    }
    ~Hoge() {
        std::cout << "remove Hoge\n";
    }
};

#endif //HOGE_H
