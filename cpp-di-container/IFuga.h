#pragma once

#ifndef IFUGA_H
#define IFUGA_H

#include<memory>
#include <iostream>

#include "IObject.h"

/*
  Fuga�N���X�p�C���^�[�t�F�[�X�N���X
*/
class IFuga :public IObject
{
    void virtual FugaMethod()=0;
};

#endif //IFUGA_H
