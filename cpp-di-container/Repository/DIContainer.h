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
    static void Register(std::string name, std::function<std::shared_ptr<IObject>()> function) 
    {
        // 追加済み確認
        if (container.find(name) != container.end()) {
            throw DIContainerError::Create(DIContainerError::EXITS_NAME, name, "");
        }

        // 追加
        container[name] = function;
    }

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
        if (container.find(name) == container.end()) {
            throw DIContainerError::Create(DIContainerError::NOT_EXITS_NAME,name, "");
        }

        // インスタンスを作成
        auto instance = DIContainer::container[name]();
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
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> container;
};

#ifdef DI_INIT
// 実体化
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::container{};
#endif

#endif //DICONTAINER_H

