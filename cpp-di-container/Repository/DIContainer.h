#pragma once

#ifndef DICONTAINER_H
#define DICONTAINER_H

#include<memory>
#include<map>
#include <functional>
#include <iostream>
#include <typeinfo>
#include <mutex>

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
    static void AddMap(std::string name, std::function<std::string()> function);

    /*
      インスタンスを返す
    */
    template<class T,class... Args>
    static std::shared_ptr<T> Create(std::string name, Args... args)
    {
        // 排他制御を実施
        static std::recursive_mutex mutex_;
        std::unique_lock<std::recursive_mutex> lock(mutex_);

        // 存在確認
        if (diMaps.find(name) == diMaps.end()) {
            throw std::move(std::make_unique<DIContainerError>(DIContainerError::NOT_EXITS_NAME,name, ""));
        }

        // クラス名を取得
        auto className = DIContainer::diMaps[name]();
        auto convertTypeName = typeid(T).name();

        // クラス名の一致確認
        if (className != convertTypeName) {
            throw DIContainerError(DIContainerError::CANNOT_CONVERT_TYPE, name, convertTypeName);
        }

        auto result = std::make_shared<T>(args...);

        // インスタンスチェック
        if (result == nullptr) {
            throw DIContainerError(DIContainerError::CANNOT_CONVERT_TYPE, name, convertTypeName);
        }

        // 初期化メソッドを実行
        result->Initialize();

        // インスタンスを返す
        return result;
    }

private:
    /*
      DIコンテナ情報
    */
    static std::map<std::string, std::function<std::string()>> diMaps;

    /*
　　  排他制御用mutexインスタンス
    */
    std::recursive_mutex mutex_;

    /*
      排他制御インスタンス取得
    */
    std::unique_lock<std::recursive_mutex> locker(){
        return std::unique_lock<std::recursive_mutex>(mutex_);
    };
};


#endif //DICONTAINER_H

