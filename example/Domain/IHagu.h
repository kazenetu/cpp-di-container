#pragma once

#ifndef IHAGU_H
#define IHAGU_H

#include <memory>
#include <iostream>
#include <vector>

#include "IObject.h"

/*
  Hagu�N���X�p�C���^�[�t�F�[�X�N���X
*/
class IHagu :public IObject
{
public:
    void virtual Initialize() {};
    void virtual Initialize(std::string paramString) {};
    void virtual HaguMethod() {};
    void virtual SetParams(std::vector<int>&&) {};
};

#endif //IHAGU_H
