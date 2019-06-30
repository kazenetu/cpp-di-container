#pragma once

#include <iostream>
#include "DIContainer.h"

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
    DIContainerError(DIContainer::DI_ERROR errorCode, std::string name, std::string convertType)
        :errorCode(errorCode),name(name), convertType(convertType)
    {
    }

    /*
      エラーコード取得
    */
    DIContainer::DI_ERROR GetErrorCode() {
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
    DIContainer::DI_ERROR errorCode;
    std::string name;
    std::string convertType;
};

#endif //DICONTAINER_ERROR_H
