#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>
#include <type_traits>

#include "IObject.h"

class Hoge:public IObject
{
public:
    static std::unique_ptr<IObject> Create()
    {
        auto result = std::make_unique<Hoge>();
        return std::move(result);
    }

    static IObject* CreateA()
    {
        IObject* result = new Hoge();
        return result;
    }

    Hoge() {
        std::cout << "create Hoge\n" << std::endl;
    }
    ~Hoge() {
        std::cout << "remove Hoge\n" << std::endl;
    }
};

IObject* CreateHoge()
{
    IObject* result = new Hoge();
    return result;
}
#endif //HOGE_H
