#ifndef Encrypted_h
#define Encrypted_h

#include <iostream>
#include <string>

using namespace std;

class Encrypted
{
    private:
        char* Encode; //動的にファイルの中身を入れる変数を作成
        static const char alphabet[26]; //メンバ変数の配列を初期化するために静的に作成
        static const char changealphabet[26]; //同上
        int size; //ファイルの中身のサイズを求める
        string decodetxt; //デコードされたテキストを入れる変数
    public:
        Encrypted(const string, const int); //コンストラクタ
        ~Encrypted(); //デストラクタ　動的に要素を定めたメモリを解放させる
        void decode(); //デコードするメンバ関数
        void getEncode() const; //暗号化されたファイルを表示するメンバ関数
        void getDecode() const; //decodeされたファイルを表示するメンバ関数
};





#endif
