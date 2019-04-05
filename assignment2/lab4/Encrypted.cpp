#include "Encrypted.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Encrypted::Encrypted(const string user, const int max){
    Encode = new char[max]; //maxサイズの配列のメモリを動的に作成
    ifstream inputfile; //inputfileというファイルを作成
    inputfile.open(user); //userに入力してもらったファイル開く
    if(!inputfile){ //ファイルが間違っていたら異常終了させる。
        cout << "ファイルが開けませんでした。" << endl;
        inputfile.close();
        exit(1);
    }
    else{ //ファイルの中身をEncode配列に1行ずつ入れていく
        inputfile.getline(Encode, max);
        if(Encode[max - 1] != '\0'){ //終端がnull文字で終わってなかったらnull文字を入れる処理。警告はする。
            Encode[max - 1] = '\0';
            cout << "警告" << endl;
        }
    }
    inputfile.close(); //ファイルを閉じる

    size = strlen(Encode); //文字列のサイズを調べる
    decodetxt = ""; //デコードされたテキストを何も入れずに初期化する
}

const char Encrypted::alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //アルファベットの初期化
const char Encrypted::changealphabet[26] = {'i','z','t','o','h','n','d','b','e','q','r','k','g','l','m','a','c','s','v','w','f','u','y','p','j','x'}; //デコードするためのアルファベットを初期化


Encrypted::~Encrypted(){ //デストラクタの初期化
    delete [] Encode; //newをdeleteする
}


void Encrypted::decode(){ //デコードの処理のメンバ関数
    for(int i = 0; i < size; i++){ //ファイルの終わりまで調べる
        for(int j = 0; j < 26; j++){ //アルファベットを全て調べる
            if(Encode[i] == alphabet[j]){ //アルファベットが同じものがあったら、そのアルファベットの配列部分にはデコードした文字を代入する
                Encode[i] = changealphabet[j];
                break; //ループを抜ける
            }
        }

    }
    decodetxt = Encode; //デコードされたファイルをdecodetxtに代入する
}

void Encrypted::getEncode() const{ //encodeの文字列を表示する
    cout << Encode << endl;
}

void Encrypted::getDecode() const{ //decodeの文字列を表示する
    cout << decodetxt << endl;
}
