
#ifndef ENCRYPTED_H
#define ENCRYPTED_H

#include <iostream>
#include <string>

using namespace std;

class Encrypted
{
    protected:
        char* Encode; //動的にファイルの中身を入れる変数を作成
        int size; //ファイルの中身のサイズを求める
        string decodetxt; //デコードされたテキストを入れる変数
        static const char alphabet[26]; //メンバ変数の配列を初期化するために静的に作成
        static const char changealphabet[26]; //同上
    public:
        Encrypted(){};
        Encrypted(const string, const int); //コンストラクタ
        virtual ~Encrypted() = 0; //デストラクタ　動的に要素を定めたメモリを解放させる
        void getDecode() const; //decodeされたファイルを表示するメンバ関数
        virtual void decode() = 0;
};


#endif
