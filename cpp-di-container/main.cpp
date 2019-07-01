// cpp-di-container.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <memory>

#include "Domain/Hoge.h"
#include "Domain/Fuga.h"
#include "Repository/DIContainer.h"
#include "Repository/DIContainerError.h"

#include "Stub/StubFuga.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try {
        // コンテナ登録
        DIContainer::AddMap("Hoge", Hoge::GetInfoName);
        //DIContainer::AddMap("Fuga", Fuga::GetInfoName);
        DIContainer::AddMap("Fuga", StubFuga::GetInfoName); //Test用Fugaを登録

        // インスタンス作成
        auto hoge = DIContainer::Create<Hoge>("Hoge",1);
        //hoge->Method();

        //// インスタンス作成(テスト用
        auto fuga = DIContainer::Create<Fuga>("Fuga");
        //fuga->FugaMethod();

        //// ダウンキャストできない組み合わせでインスタンス作成
        //auto er = DIContainer::Create<Fuga>("Hoge");
    }
    catch (DIContainerError error) {
        std::cout << "error:" << error.GetErrorString().c_str() << std::endl;
    }
    


    // 一時停止
    getchar();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
