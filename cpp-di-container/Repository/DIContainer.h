#pragma once

#ifndef DICONTAINER_H
#define DICONTAINER_H

#include<memory>
#include<map>
#include <functional>
#include <iostream>
#include <typeinfo>

#include "IObject.h"
#include "DIContainerError.h"

/*
  簡易DIコンテナ
*/
class DIContainer
{
public:

    /*
      追加
    */
    static void AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function);

    /*
      インスタンスを返す
    */
    template<class T>
    static std::shared_ptr<T> Create(std::string name)
    {
        // 存在確認
        if (diMaps.find(name) == diMaps.end()) {
            throw std::move(std::make_unique<DIContainerError>(DIContainerError::NOT_EXITS_NAME,name, ""));
        }

        // インスタンスを作成
        auto instance = DIContainer::diMaps[name]();
        auto result = std::dynamic_pointer_cast<T>(instance);

        // インスタンスチェック
        if (result == nullptr) {
            throw DIContainerError(DIContainerError::CANNOT_CONVERT_TYPE, name, typeid(T).name());
        }

        // 初期化メソッドを実行
        instance->Initialize();

        // インスタンスを返す
        return result;
    }

    /*
      エラー時の文字列を取得
    */
    static std::string GetErrorName(DIContainerError &errorCode);

private:
    /*
      DIコンテナ情報
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;
};


#endif //DICONTAINER_H

