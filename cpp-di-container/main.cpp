// cpp-di-container.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <memory>

#define DI_INIT

#include "Domain/Hoge.h"
#include "Domain/Fuga.h"
#include "Domain/ExclusionDI.h"
#include "Repository/DIContainer.h"

#include "Stub/StubFuga.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try {
        std::cout << "---[IContainer::Register]---" << std::endl;

        // コンテナ登録
        DIContainer::Register("Hoge", Hoge::Create);
        //DIContainer::Register("Fuga", Fuga::Create);
        DIContainer::Register("Fuga", StubFuga::Create); //Test用Fugaを登録

        std::cout << std::endl;
        std::cout << "---[IContainer::Create Hoge(int)]---" << std::endl;

        // インスタンス作成
        auto hoge = DIContainer::Create<Hoge>("Hoge",10);
        hoge->Method();

        std::cout << std::endl;
        std::cout << "---[IContainer::Create Hoge(IFuga)]---" << std::endl;

        // インスタンス作成：パラメータにFugaインスタンス
        auto hoge2 = DIContainer::Create<Hoge>("Hoge", DIContainer::Create<IFuga>("Fuga"));
        hoge2->Method();

        std::cout << std::endl;
        std::cout << "---[IContainer::Create Hoge(ExclusionDI)]---" << std::endl;

        // インスタンス作成：パラメータにExclusionDIインスタンス
        ExclusionDI exd("text");
        auto hoge3 = DIContainer::Create<Hoge>("Hoge", std::move(exd));
        hoge3->Method();

        std::cout << std::endl;
        std::cout << "---[IContainer::Create Hoge(vector<int>)]---" << std::endl;

        // インスタンス作成：パラメータにlist<int>インスタンス 左辺値参照
        std::vector<int> vec{ 1,2,3 };
        //auto hoge4 = DIContainer::Create<Hoge>("Hoge", std::move(vec)); // Compile Error
        auto hoge4 = DIContainer::Create<Hoge>("Hoge");
        hoge4->DisplayIntList(std::move(vec)); // Need to call another method
        hoge4->Method();

        std::cout << std::endl;
        std::cout << "---[IContainer::Create IFuga]---" << std::endl;

        // インスタンス作成(テスト用
        auto fuga = DIContainer::Create<IFuga>("Fuga");
        fuga->FugaMethod();

        std::cout << std::endl;
        std::cout << "---[IContainer::Create Exception]---" << std::endl;

        // ダウンキャストできない組み合わせでインスタンス作成
        auto er = DIContainer::Create<Fuga>("Hoge");
    }
    catch (std::runtime_error error) {
        std::cout << "error:" << error.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "---[end]---" << std::endl;


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
