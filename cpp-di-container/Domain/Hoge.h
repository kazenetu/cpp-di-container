#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>
#include <typeinfo>

#include "../Repository/IObject.h"

/*
  IObjectインターフェースの実装クラス
*/
class Hoge:public IObject
{
public:

    /*
      クラス名を返す
    */
    static std::string GetInfoName()
    {
        return typeid(Hoge).name();
    }

    /*
      動作確認用メソッド
    */
    void Method() {
        // メソッド呼び出し時に動作確認用フィールドを書きかえる
        str = "abc";

        std::cout << "Hoge!" << str.c_str() << std::endl;
    }

    /*
      コンストラクタ
    */
    Hoge() :str("aaaa") {
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
    }

    Hoge(int i) :str("aaaa") {
        std::cout << "create Hoge_i:" << this << str.c_str() << std::endl;
    }

    void Initialize() {
        std::cout << "Initialize Hoge:" << this << std::endl;
    }

    /*
      デストラクタ
    */
    ~Hoge() {
        std::cout << "remove Hoge:" << this << str.c_str() << std::endl;
    }

private:

    /*
      動作確認用フィールド
    */
    std::string str;
};

#endif //HOGE_H
