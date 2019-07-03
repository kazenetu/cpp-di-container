#pragma once

#ifndef IHAGU_H
#define IHAGU_H

#include<memory>
#include <iostream>

#include "../Repository/IObject.h"

/*
  Haguクラス用インターフェースクラス
*/
class IHagu :public IObject
{
    void virtual HaguMethod() {};
};

#endif //IHAGU_H
