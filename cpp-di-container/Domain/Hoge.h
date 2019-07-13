#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>
#include <vector>

#include "../Repository/IObject.h"
#include "Domain/IFuga.h"
#include "ExclusionDI.h"

/*
  IObjectインターフェースの実装クラス
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
    Hoge() :str("aaaa"), exd_("a"){
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
    }

    void Initialize() {
        std::cout << "Initialize Hoge:" << this << std::endl;
    }
    void Initialize(int i) {
        std::cout << "Initialize Hoge:pram(int) " << i << std::endl;
    }
    void Initialize(std::shared_ptr<IFuga> fuga) {
        std::cout << "Initialize Hoge:pram(shared_ptr<IFuga>) " <<  std::endl;
        fuga->FugaMethod();
    }
    void Initialize(ExclusionDI &exd) {
        std::cout << "Initialize Hoge:pram(ExclusionDI) " << std::endl;
        exd_ = exd;
        exd_.DisplayName();
    }
    void Initialize(std::vector<int>&& vec) {
        // Initialization method is not used
        std::cout << "Initialize Hoge:pram(std::vector<int>) " << std::endl;
    }

    /*Method whose argument is vector*/
    void DisplayIntList(std::vector<int>&& vec)
    {
        std::cout << "DisplayIntList Hoge:pram(std::vector<int>) " << std::endl;
        vec_ = vec;

        std::cout << "std::vector<int> is [";
        for (int i = 0; i < vec_.size(); ++i) {
            std::cout << vec_[i] << ",";
        }
        std::cout << "]" << std::endl;
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
    ExclusionDI exd_;
    std::vector<int> vec_;
};

#endif //HOGE_H
