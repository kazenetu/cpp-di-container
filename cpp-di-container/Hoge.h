#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>

#include "IObject.h"

/*
  サブクラス
*/
class Hoge:public IObject
{
public:

    /*
      インスタンス作成
    */
    static std::shared_ptr<IObject> Create()
    {
        auto result = std::make_shared<Hoge>();

        // 生成時に動作確認用フィールドを書きかえる
        result->str = "abc";

        return result;
    }

    /*
      動作確認用メソッド
    */
    void Method() {
        std::cout << "Hoge!" << str.c_str() << std::endl;
    }

    /*
      コンストラクタ
    */
    Hoge() :str("aaaa") {
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
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
