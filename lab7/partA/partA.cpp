#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(){
    //WorldSeriesWinnersのファイルをユーザに入力してもらう。
    fstream inputfile;
    //1903年から2012年までの期間に優勝したチーム名が入った動的配列の初期化
    vector<string> WorldSeriesWinners;
    cout << "WorldSeriesWinnersのファイルを入力してください。 :";
    string filename;
    cin >> filename;
    //入力のチェック
    while(cin.fail() || !(filename== "WorldSeriesWinners.txt")){
        cout << "入力を間違えています。もう一度入力してください。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "入力してください。 :";
        cin >> filename;
    }

    inputfile.open(filename);

    //ファイルから配列に1行ずつ読み込む、この際動的配列に読み込むのでvectorのpush_backを使って配列に組み込む
    string box;
    while(getline(inputfile, box)){
        WorldSeriesWinners.push_back(box);
    }

    inputfile.close();

    //歴代の優勝者リスト
    cout << endl << "以下は1903年から2012年までの期間に優勝したチーム名です。" << endl;
    for(int i = 0; i < WorldSeriesWinners.size(); i++){
        cout << WorldSeriesWinners[i] << endl;
    }

    //優勝したことのあるチーム名をユーザに見せる計算と出力
    cout << "以下は優勝したことのあるチーム名です。" << endl;
    vector<string> teamArray;
    string confirm, //優勝したことがあるかどうか確認するために一旦格納するための変数
           box2;    //動的配列に格納する際の変数
    for(int i = 0; i < WorldSeriesWinners.size(); i++){
        bool test = true;
        confirm = WorldSeriesWinners[i];
        int num = i + 1;
        for(int j = num; j < WorldSeriesWinners.size(); j++){
            if(confirm == WorldSeriesWinners[j]){
                test = false;
            }
        }
        if(test){
            box2 = WorldSeriesWinners[i];
            teamArray.push_back(box2);
        }
    }

    //画面に表示
    for(int i = 0; i < teamArray.size(); i++){
        cout << teamArray[i] << endl;
    }

    //ユーザが知りたいチーム名を入力してもらい調べる
    cout << "どのチームの1903年から2012年までの優勝回数を知りたいですか？ :";
    string teamName;
    //getlineを使う際に、前回に使ったcinの改行文字がバッファに残っているからそれを綺麗にする
    cin.clear();
    cin.ignore(1024, '\n');
    //getlineを使い空白文字も文字列として受け取る
    getline(cin, teamName);
    //入力の確認
    while(cin.fail()){
        cout << "入力を間違えています。もう一度入力してください。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "入力してください。 :";
        getline(cin, teamName);
    }

    //ユーザの入力が優勝したことのあるチームか確認している。
    bool confirm2 = false;
    for(int i = 0; i < teamArray.size(); i++){
        if(teamName == teamArray[i]){
            confirm2 = true;
        }
    }

    //優勝したことのあるチームを入力した時の処理
    if(confirm2){
        int winnerNumber = 0;
        for(int j = 0; j < WorldSeriesWinners.size(); j++){
            if(teamName == WorldSeriesWinners[j]){
                winnerNumber++;
            }
        }
        cout << teamName << "の優勝回数は" << winnerNumber << "回です。" << endl;
    }
    //優勝したことのないチームを入力した時の処理
    else{
        cout << "そのチームは優勝したことがありません。" << endl;
    }
   
    return 0;

}
