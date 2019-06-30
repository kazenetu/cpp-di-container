#pragma once

#ifndef HOGE_H
#define HOGE_H

#include<memory>
#include <iostream>

#include "../Repository/IObject.h"

/*
  IObject�C���^�[�t�F�[�X�̎����N���X
*/
class Hoge:public IObject
{
public:

    /*
      �C���X�^���X�쐬
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<Hoge>();
    }

    /*
      ����m�F�p���\�b�h
    */
    void Method() {
        // ���\�b�h�Ăяo�����ɓ���m�F�p�t�B�[���h������������
        str = "abc";

        std::cout << "Hoge!" << str.c_str() << std::endl;
    }

    /*
      �R���X�g���N�^
    */
    Hoge() :str("aaaa") {
        std::cout << "create Hoge:" << this << str.c_str() << std::endl;
    }

    void Initialize() {
        std::cout << "Initialize Hoge:" << this << std::endl;
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
