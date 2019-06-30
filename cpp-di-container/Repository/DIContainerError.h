#pragma once

#include <iostream>

#ifndef DICONTAINER_ERROR_H
#define DICONTAINER_ERROR_H

/*
  簡易DIコンテナ用エラークラス
*/
class DIContainerError
{
public:
    /*
      コンストラクタ
    */
    DIContainerError(int errorCode, std::string name, std::string convertType)
        :errorCode(errorCode),name(name), convertType(convertType)
    {
    }

    /*
      エラーコード取得
    */
    int GetErrorCode() {
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
    int errorCode;
    std::string name;
    std::string convertType;
};

#endif //DICONTAINER_ERROR_H
