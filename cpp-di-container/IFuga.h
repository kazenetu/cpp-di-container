#pragma once

#ifndef IFUGA_H
#define IFUGA_H

#include<memory>
#include <iostream>

#include "IObject.h"

/*
  Fugaクラス用インターフェースクラス
*/
class IFuga :public IObject
{
    void virtual FugaMethod()=0;
};

#endif //IFUGA_H
