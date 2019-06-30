#pragma once

#include <iostream>

#ifndef DICONTAINER_ERROR_H
#define DICONTAINER_ERROR_H

/*
  �Ȉ�DI�R���e�i�p�G���[�N���X
*/
class DIContainerError
{
public:
    /*
      �R���X�g���N�^
    */
    DIContainerError(int errorCode, std::string name, std::string convertType)
        :errorCode(errorCode),name(name), convertType(convertType)
    {
    }

    /*
      �G���[�R�[�h�擾
    */
    int GetErrorCode() {
        return errorCode;
    }

    /*
      �w�肵�����O���擾
    */
    std::string GetName() {
        return name;
    }

    /*
      �_�E���L���X�g�����擾
      Create���\�b�h���̂ݐݒ�
    */
    std::string GetConvertType() {
        return convertType;
    }

private:
    int errorCode;
    std::string name;
    std::string convertType;
};

#endif //DICONTAINER_ERROR_H