#pragma once

#ifndef IHAGU_H
#define IHAGU_H

#include<memory>
#include <iostream>

#include "../Repository/IObject.h"

/*
  Hagu�N���X�p�C���^�[�t�F�[�X�N���X
*/
class IHagu :public IObject
{
    void virtual HaguMethod() {};
};

#endif //IHAGU_H