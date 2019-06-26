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
        result->str = "abc";
        return std::move(result);
    }

    static IObject* CreateA()
    {
        IObject* result = new Hoge();
        return result;
    }

    static IObject* CreateB()
    {
        return &Hoge();
    }

    static std::shared_ptr<IObject> CreateC()
    {
        auto result = std::make_shared<Hoge>();
        result->str = "abc";
        return std::move(result);
    }

    void Func() {
        std::cout << "Hoge!" << str.c_str() << std::endl;
    }

    Hoge() :str("aaaa") {
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
    }
    ~Hoge() {
        std::cout << "remove Hoge:" << this << str.c_str() << std::endl;
    }

    std::string str;
private:
};

IObject* CreateHoge()
{
    IObject* result = new Hoge();
    return result;
}
#endif //HOGE_H
