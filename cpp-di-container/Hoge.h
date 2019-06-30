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
        return std::make_shared<Hoge>();
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

    void Created() {

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
