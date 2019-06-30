#pragma once

#ifndef DICONTAINER_ERROR_H
#define DICONTAINER_ERROR_H

#include <iostream>
#include "DIContainer.h"

// �萔����Ԃ�
#define STR(var) #var 

/*
  �Ȉ�DI�R���e�i�p�G���[�N���X
*/
class DIContainerError
{
public:
    /*
      �G���[�p�񋓌^
    */
    enum DI_ERROR {
        EXITS_NAME = 1,
        NOT_EXITS_NAME,
        CANNOT_CONVERT_TYPE,
        UNKNOWN_ERROR,
    };

    /*
      �R���X�g���N�^
    */
    DIContainerError(DI_ERROR errorCode, std::string name, std::string convertType)
        :errorCode(errorCode),name(name), convertType(convertType)
    {
    }

    /*
      �G���[���̕�������擾
    */
    std::string GetErrorString()
    {
        std::string result;

        // �G���[�R�[�h
        switch (errorCode) {
        case DIContainerError::EXITS_NAME:
            result += STR(EXITS_NAME);

        case DIContainerError::NOT_EXITS_NAME:
            result += STR(NOT_EXITS_NAME);

        case DIContainerError::CANNOT_CONVERT_TYPE:
            result += STR(CANNOT_CONVERT_TYPE);

        default:
            result += STR(UNKNOWN_ERROR);

        }

        // ����
        result += " name[" + name + "]";

        // �ϊ���
        if (convertType != "") {
            result += " convert miss[" + convertType + "]";
        }

        return result;
    }


    /*
      �G���[�R�[�h�擾
    */
    DI_ERROR GetErrorCode() {
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
    DI_ERROR errorCode;
    std::string name;
    std::string convertType;
};

#endif //DICONTAINER_ERROR_H
