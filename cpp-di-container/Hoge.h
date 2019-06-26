#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>

#include "IObject.h"

/*
  �T�u�N���X
*/
class Hoge:public IObject
{
public:

    /*
      �C���X�^���X�쐬
    */
    static std::shared_ptr<IObject> Create()
    {
        auto result = std::make_shared<Hoge>();

        // �������ɓ���m�F�p�t�B�[���h������������
        result->str = "abc";

        return std::move(result);
    }

    /*
      ����m�F�p���\�b�h
    */
    void Method() {
        std::cout << "Hoge!" << str.c_str() << std::endl;
    }

    /*
      �R���X�g���N�^
    */
    Hoge() :str("aaaa") {
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
    }

    /*
      �f�X�g���N�^
    */
    ~Hoge() {
        std::cout << "remove Hoge:" << this << str.c_str() << std::endl;
    }

private:

    /*
      ����m�F�p�t�B�[���h
    */
    std::string str;
};

#endif //HOGE_H
