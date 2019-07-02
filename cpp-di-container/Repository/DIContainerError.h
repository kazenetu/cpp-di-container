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
class DIContainerError :public std::runtime_error
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
     インスタンス作成メソッド
    */
    static DIContainerError Create(DI_ERROR errorCode, std::string name, std::string convertType) {
        auto message = GetErrorString(errorCode, name, convertType);
        return DIContainerError(message, errorCode, name, convertType);
    }


    /*
      コンストラクタ
    */
    DIContainerError(const std::string&_Message, DI_ERROR errorCode, std::string name, std::string convertType)
        :runtime_error(_Message), errorCode(errorCode), name(name), convertType(convertType)
    {
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

    /*
      エラー時の文字列を取得
    */
    static std::string GetErrorString(DI_ERROR errorCode, std::string name, std::string convertType)
    {
        std::string result;

        // エラーコード
        switch (errorCode) {
        case DIContainerError::EXITS_NAME:
            result += STR(EXITS_NAME);
            break;

        case DIContainerError::NOT_EXITS_NAME:
            result += STR(NOT_EXITS_NAME);
            break;

        case DIContainerError::CANNOT_CONVERT_TYPE:
            result += STR(CANNOT_CONVERT_TYPE);
            break;

        default:
            result += STR(UNKNOWN_ERROR);
            break;
        }

        // 名称
        result += " name[" + name + "]";

        // 変換名
        if (convertType != "") {
            result += " convert miss[" + convertType + "]";
        }

        return result;
    }
};

#endif //DICONTAINER_ERROR_H
