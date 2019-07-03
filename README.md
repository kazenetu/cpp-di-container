# cpp-di-container
C++用簡易DIコンテナ

## コンテナに登録できるクラスの条件
* 間接的にインターフェース「IObject」を継承していること
* shared_ptr\<IObject\>を返すクラスメソッド「Create」を必ず作成すること
* インスタンスメソッド「Initialize」を必ず作成すること  
  **パラメータが必要の場合はパラメータ付きメソッドを用意すること***

### 実装例  
```cpp
/*
  Fugaクラス用インターフェースクラス
*/
class IFuga :public IObject
{
    void virtual FugaMethod(){}
};

/*
  IFugaインターフェースの実装クラス
*/
class Fuga :public IFuga
{
public:
    /*
      インスタンス作成
    */
    static std::shared_ptr<IObject> Create()
    {
        return std::make_shared<Fuga>();
    }
 
    void Initialize() {
        std::cout << "Initialize Fuga param None" << std::endl;
    }

    void Initialize(int i) {
        std::cout << "Initialize Fuga param(int) " << i << std::endl;
    }

    void FugaMethod() {
        std::cout << "Fuga!" << std::endl;
    }
};
```

## 使用方法
### **コンテナにクラス名とクラス(IObject)生成メソッドを登録**
```cpp
// コンテナ登録
DIContainer::Register("Fuga", Fuga::Create);
```

### **クラスを指定し、そのインタンスを生成・取得**
```cpp
// インスタンス作成
auto fuga = DIContainer::Create<Fuga>("Fuga");

// インスタンス作成(パラメータを設定する場合は第二パラメータ以降に設定)
auto fuga = DIContainer::Create<Fuga>("Fuga", 1);

```
※shared_ptrが返る  

## エラーと例外インスタンス

### 例外発生条件
|機能|条件|エラーコード|
|:-----------------|:--------------------|:-------------------------------------|
|コンテナ登録時     |クラス名の重複         |DIContainerError::DI_ERROR::EXITS_NAME          |
|インスタンス作成時 |クラス名未登録         |DIContainerError::DI_ERROR::NOT_EXITS_NAME      |
|インスタンス作成時 |指定クラスへの変換不可  |DIContainerError::DI_ERROR::CANNOT_CONVERT_TYPE |

### 例外インスタンス(std::runtime_error)
|メソッド名|戻り値|詳細|
|:-------------------|:----------------------------|:-------------------------------------|
|error.what()        |const char*                  | エラー時の文字列を取得                 |
|*GetErrorCode()*※  |*DIContainerError::DI_ERROR* | *エラーコード取得*                    |
|*GetName()*※       |*std::string*                | *クラス名取得*                        |
|*GetConvertType()*※ |*std::string*                | *ダウンキャスト名を取得(インスタンス作成時のみ設定)*|

※DIContainerErrorにキャストすることで参照可能