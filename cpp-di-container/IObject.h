#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include<memory>

/*
  �X�[�p�[�N���X
*/
class IObject
{
public:
    /*
      �C���X�^���X�쐬
    */
    static std::unique_ptr<IObject> Create() { return nullptr;}
};

#endif //IOBJECT_H
