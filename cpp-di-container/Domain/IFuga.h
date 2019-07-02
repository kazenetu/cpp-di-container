#pragma once

#ifndef IFUGA_H
#define IFUGA_H

#include<memory>
#include <iostream>

#include "../Repository/IObject.h"

/*
  Fugaクラス用インターフェースクラス
*/
class IFuga :public IObject
{
    void virtual FugaMethod() {};
};

#endif //IFUGA_H
