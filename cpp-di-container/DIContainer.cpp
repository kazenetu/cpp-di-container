#include "pch.h"

#include <typeinfo>

#include "DIContainer.h"

// 定数名を返す
#define STR(var) #var 

/*
  追加
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // 追加済み確認
    if (diMaps.find(name) != diMaps.end()) {
        throw EXITS_NAME;
    }

    // 追加
    diMaps[name] = function;
}

/*
  エラー時の文字列を取得
*/
std::string DIContainer::GetErrorName(DIContainer::DI_ERROR errorCode)
{
    switch (errorCode) {
    case EXITS_NAME:
        return STR(EXITS_NAME);

    case NOT_EXITS_NAME:
        return STR(NOT_EXITS_NAME);

    default:
        return STR(UNKNOWN_ERROR);

    }

}

// 実体化
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
