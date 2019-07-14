#pragma once

#ifndef HAGU_H
#define HAGU_H

#include<memory>
#include <iostream>

#include "IHagu.h"
#include "DIContainer.h"

/*
  IHaguインターフェースの実装クラス
*/
class Hagu :public IHagu
{
public:
    /*
      インスタンス作成
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
    void Initialize(std::vector<int>&& vec) {
        std::cout << "Param pram(std::vector<int>):";
        std::cout << "[";
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << ",";
        }
        std::cout << "]" << std::endl;
    }
    void SetParams(std::vector<int>&& vec) {
        Initialize(std::move(vec));
    }

    void HaguMethod() {
        std::cout << "Hagu!" << std::endl;
    }
private:
};

#endif //HAGU_H
