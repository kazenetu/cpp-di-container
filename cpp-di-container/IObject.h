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
    /*
      インスタンス作成
    */
    static std::unique_ptr<IObject> Create() { return nullptr;}
};

#endif //IOBJECT_H
