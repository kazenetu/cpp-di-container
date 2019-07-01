#pragma once

#ifndef DICONTAINER_ERROR_H
#define DICONTAINER_ERROR_H

#include <iostream>
#include "DIContainer.h"

// 定数名を返す
#define STR(var) #var 

/*
  簡易DIコンテナ用エラークラス
*/
class DIContainerError
{
public:
    /*
      エラー用列挙型
    */
    enum DI_ERROR {
        EXITS_NAME = 1,
        NOT_EXITS_NAME,
        CANNOT_CONVERT_TYPE,
        UNKNOWN_ERROR,
    };

    /*
      コンストラクタ
    */
    DIContainerError(DI_ERROR errorCode, std::string name, std::string convertType)
        :errorCode(errorCode),name(name), convertType(convertType)
    {
    }

    /*
      エラー時の文字列を取得
    */
    std::string GetErrorString()
    {
        std::string result;

        // エラーコード
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

        // 名称
        result += " name[" + name + "]";

        // 変換名
        if (convertType != "") {
            result += " convert miss[" + convertType + "]";
        }

        return result;
    }


    /*
      エラーコード取得
    */
    DI_ERROR GetErrorCode() {
        return errorCode;
    }

    /*
      指定した名前を取得
    */
    std::string GetName() {
        return name;
    }

    /*
      ダウンキャスト名を取得
      Createメソッド名のみ設定
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
