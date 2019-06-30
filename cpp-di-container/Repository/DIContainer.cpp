#include "DIContainer.h"

#include <typeinfo>

// 定数名を返す
#define STR(var) #var 

/*
  追加
*/
void DIContainer::AddMap(std::string name, std::function<std::shared_ptr<IObject>()> function)
{
    // 追加済み確認
    if (diMaps.find(name) != diMaps.end()) {
        throw std::move(std::make_unique<DIContainerError>(DIContainerError::EXITS_NAME, name, ""));
    }

    // 追加
    diMaps[name] = function;
}

/*
  エラー時の文字列を取得
*/
std::string DIContainer::GetErrorName(DIContainerError &error)
{
    std::string result;

    // エラーコード
    switch (error.GetErrorCode()) {
    case DIContainerError::EXITS_NAME:
        result += STR(EXITS_NAME);

    case DIContainerError::NOT_EXITS_NAME:
        result += STR(NOT_EXITS_NAME);

    case DIContainerError::CANNOT_CONVERT_TYPE:
        result += STR(CANNOT_CONVERT_TYPE);

    default:
        result += STR(UNKNOWN_ERROR);

    }

    // 名称取得
    result += " name[" + error.GetName() + "]";

    // 変換名確認と取得
    auto convertType = error.GetConvertType();
    if (convertType != "") {
        result += " convert miss[" + convertType + "]";
    }

    return result;
}

// 実体化
std::map<std::string, std::function<std::shared_ptr<IObject>()>> DIContainer::diMaps{};
