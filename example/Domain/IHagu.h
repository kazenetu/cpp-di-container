#pragma once

#ifndef IHAGU_H
#define IHAGU_H

#include <memory>
#include <iostream>
#include <vector>

#include "IObject.h"

/*
  Haguクラス用インターフェースクラス
*/
class IHagu :public IObject
{
    void virtual HaguMethod() {};
    void virtual SetParams(std::vector<int>&&) {};
};

#endif //IHAGU_H
