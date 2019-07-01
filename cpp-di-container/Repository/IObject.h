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
    virtual void Initialize()=0;
};

#endif //IOBJECT_H
