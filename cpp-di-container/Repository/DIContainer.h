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
    static void AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function);

    /*
      インスタンスを返す
    */
    template<class T, class... Args>
    static std::shared_ptr<T> Create(std::string name, Args... args)
    {
        // 排他制御を実施
        static std::recursive_mutex mutex_;
        std::unique_lock<std::recursive_mutex> lock(mutex_);

        // 存在確認
        if (diMaps.find(name) == diMaps.end()) {
            throw DIContainerError::Create(DIContainerError::NOT_EXITS_NAME,name, "");
        }

        // インスタンスを作成
        auto instance = DIContainer::diMaps[name]();
        auto result = std::dynamic_pointer_cast<T>(instance);

        // インスタンスチェック
        if (result == nullptr) {
            throw DIContainerError::Create(DIContainerError::CANNOT_CONVERT_TYPE, name, typeid(T).name());
        }

        // 初期化メソッドを実行
        result->Initialize(args...);

        // インスタンスを返す
        return result;
    }

private:
    /*
      DIコンテナ情報
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;

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

