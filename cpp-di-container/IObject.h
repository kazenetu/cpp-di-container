#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include<memory>

/*
  スーパークラス
*/
class IObject
{
public:
    virtual void Created()=0;
};

#endif //IOBJECT_H
