#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include<memory>

/*
  インターフェースクラス
*/
class IObject
{
public:
    virtual ~IObject() = default;
    virtual void Initialize() {};
};

#endif //IOBJECT_H
