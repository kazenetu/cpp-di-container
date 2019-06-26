#pragma once

#include<memory>
#include<map>
#include <functional>
#include <iostream>

#include "IObject.h"

#ifndef DICONTAINER_H
#define DICONTAINER_H

/*
  簡易DIコンテナ
*/
class DIContainer
{
public:

    static void AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function);

    /*
      インスタンスを返す
    */
    template<class T>
    static std::shared_ptr<T> Create(std::string name)
    {
        // TODO 存在確認

        // インスタンスを作成し、返す
        return std::static_pointer_cast<T>(DIContainer::diMaps[name]());
    }

private:
    /*
      DIコンテナ情報
    */
    static std::map<std::string, std::function<std::shared_ptr<IObject>()>> diMaps;
};



#endif //DICONTAINER_H

