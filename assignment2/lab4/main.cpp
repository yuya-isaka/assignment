#include "Encrypted.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string userfile; //ユーザーに入力してもらうファイル名
    int maxsize = 2000; //ファイルの中身の最大のサイズ
    cout << "エンコードされたファイル名を入力してください。" << endl; //ユーザーに入力してもらう
    cout << " >>>";
    cin >> userfile;
    while(cin.fail()){ //入力を間違えていた時の処理
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> userfile;
    }

    Encrypted Object(userfile, maxsize); //Encryptedのオブジェクトを作成　引数を渡す

    Object.getEncode(); //encodeのファイルを表示

    cout << "デコードします。" << endl;

    Object.decode(); //デコードする

    Object.getDecode(); //デコードした内容を表示

    return 0;
}
