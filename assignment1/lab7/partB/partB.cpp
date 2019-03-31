#include <iostream>
#include <string>
using namespace std;

int main(){

    //宝くじの当選番号の配列を作る
    string luckyNumber[10] = {"13579", "26791", "26792", "33445", "55555", "62483", "77777", "79422", "85647", "93121"};
    //ユーザーに入力してもらう変数
    string userNumber;
    //ユーザーに番号を聞くループを抜けるための変数
    bool check = true;

    while(check){
        //ユーザに番号を入力してもらう。
        cout << "宝くじの当選を確認します。あなたの番号を入力してください。" << endl;
        cout << " :";
        cin >> userNumber;
        //入力のチェック
        while(cin.fail()){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "入力してください。 :";
            cin >> userNumber;
        }

        //ユーザが当選していたかどうかを確認する変数と計算
        bool confirm = false;
        int elementCount = sizeof(luckyNumber)/sizeof(luckyNumber[0]);
        for(int i = 0; i < elementCount; i++){
            if(userNumber == luckyNumber[i]){
                confirm = true;
            }
        }

        //ユーザが当選していたかを画面に出力
        if(confirm){
            cout << "おめでとうございます。当選しました。" << endl;
        }
        else{
            cout << "残念ながらあなたの番号は外れていました。" << endl;
        }

        //再び当選を確かめるかユーザに確認
        char confirm2;
        cout << "もう一度あなたの番号を確認しますか？　Y or N で答えてください。 :";
        cin >> confirm2;
        //入力のチェック
        while(cin.fail() || !(confirm2 == 'Y' || confirm2 == 'y' || confirm2 == 'N' || confirm2 == 'n')){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> confirm2;
        }

        //入力がyesの場合の処理
        if(confirm2 == 'Y' || confirm2 == 'y'){
            cout << "それではもう一度";
        }
        //入力がnoの場合の処理
        else if(confirm2 == 'N' || confirm2 == 'n'){
            cout << "それではプログラムを終了します。" << endl;
            check = false;
        }

    }

    return 0;

}
