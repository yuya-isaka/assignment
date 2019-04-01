#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


//構造体 生徒の名前と生徒のスコアを持つ
struct Score{
    string studentName,
           averageScore;
};

//bool関数 比較関数 sortする際に用いる
bool asc( const Score& left, const Score& right ) {
    return /*もしスコアが同じ場合は名前のアルファベット順で比較するという作業が書かれている。でも原理を理解してない、ここでは意味ないからコメントアウト。left.averageScore == right.averageScore ? left.studentName < right.studentName :*/ left.averageScore < right.averageScore;
}

int main(){
    int test; //テストの個数

    //テストの個数を聞き、変数testに代入する。
    cout << "テストの数は何個ですか？ :";
    cin >> test;
    //入力の確認
    while(cin.fail()){
        cout << "入力を間違えています。もう一度入力してください。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> test;
    }

    //変数の宣言or定義
    const int SIZE = test; //テストの数を変数SIZEに代入する。
    int counter = 0, //ファイルから読み込んだ値のチェック
        counter2 = 0, //同上
        totalScore = 0, //それぞれの生徒の合計スコア
        averageTestScore = 0; //それぞれの生徒の平均スコア
    string box; //ファイルから一時的に格納する箱
    int student; //生徒の数

    //生徒の数を聞き、変数studentに代入する。
    cout << "何人の生徒のテストですか？　:";
    cin.clear();
    cin.ignore(1024, '\n');
    cin >> student;
    //入力の確認
    while(cin.fail()){
        cout << "入力を間違えています。もう一度入力してください。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> test;
    }

    //vector配列を生徒の数の要素数を持ったものを作る。
    vector<Score> scoreArray(student);

    //ファイルを読み込む作業
    ifstream inputfile;
    inputfile.open("lab2.txt");
    //ファイルの入力確認
    if(!inputfile){
        cout << "ファイルを開けませんでした。" << endl;
        exit(1);
    }

    //ファイルからvector配列に書き込む作業
    while(inputfile >> box){
        if(counter == SIZE+1){
            averageTestScore = totalScore/SIZE;
            scoreArray[counter2].averageScore = to_string(averageTestScore);
            counter = 0;
            counter2++;
            totalScore = 0;
        }
        if(counter == 0){
            scoreArray[counter2].studentName = box;
        }
        else{
            totalScore += stoi(box);
        }
        counter++;
    }
    averageTestScore = totalScore/SIZE;
    scoreArray[counter2].averageScore = to_string(averageTestScore);

    inputfile.close();

    //配列をsortする。
    sort(scoreArray.begin(), scoreArray.end(), asc);

    //結果を表示
    cout << "結果を表示します。" << endl;
    for(int i = 0; i < student; i++){
        cout << "name :" << setw(10) << scoreArray[i].studentName << "  ";
        cout << "score :" << setw(10) << scoreArray[i].averageScore << endl;
    }


    return 0;
}

