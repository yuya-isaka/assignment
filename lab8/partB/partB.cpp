#include <iostream>
#include <fstream>
#include <tuple>
using namespace std;

//線形検索の関数
tuple<int, bool> linearSearch(int (&searchArray)[20], int data);

//二分検索の関数
tuple<int, bool> binarySearch(int (&searchArray)[20], int data);

int main(){
    int userNum, //ユーザー入力を格納する変数
        searchArray[20], //ファイルのデータを入れる変数
        stepNum; //ステップ数を入れる変数
    bool confirm;

    //ファイルから変数にデータを格納
    cout << endl << "sortedBubbleData.txtからsearchArrayにデータを読み込む" << endl;
    ifstream inputfile;
    inputfile.open("sortedBubbleData.txt");
    //ファイルを開くことができなかったら終了
    if(!inputfile){
        cout << "ファイルを開くことができませんでした。" << endl;
        exit(1);
    }
    for(int i = 0; i < 20; i++){
        inputfile >> searchArray[i];
    }

    //画面に読み込んだデータを出力
    cout << "読み混んだデータを以下に出力します。" << endl << endl;
    for(int i = 0; i < 20; i++){
        cout << searchArray[i] << endl;
    }

    //ユーザーに調べたい値を入力してもらう
    cout << endl << "この名から調べたい数字を入力してください。:";
    cin >> userNum;
    //入力の確認
    while(cin.fail()){
        cout << "入力間違えています。もう一度入力してください。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "入力してください。 :";
        cin >> userNum;
    }

    //線形検索する
    cout << endl << userNum << "がsearchArrayのデータにあるか線形検索で調べます。" << endl;
    tie(stepNum, confirm) = linearSearch(searchArray, userNum);

    //ユーザーが入力した値が存在した時の出力
    if(confirm){
        cout << "調べるのにかかったステップ数は「" << stepNum << "」回, " << userNum << "はデータに存在します。" << endl;
    }
    //ユーザーが入力した値が存在しなかった時の出力
    else{
        cout << "調べるのにかかったステップ数は「" << stepNum << "」回, " << userNum << "はデータに存在しません。" << endl;
    }

    //二分検索する
    cout << endl << userNum << "がsearchArrayのデータにあるか二分検索で調べます。" << endl;
    tie(stepNum, confirm) = binarySearch(searchArray, userNum);

    //ユーザーが入力した値が存在した時の出力
    if(confirm){
        cout << "調べるのにかかったステップ数は「" << stepNum << "」回, " << userNum << "はデータに存在します。" << endl;
    }
    //ユーザーが入力した値が存在しなかった時の出力
    else{
        cout << "調べるのにかかったステップ数は「" << stepNum << "」回, " << userNum << "はデータに存在しません。" << endl;
    }

}

//線形検索
tuple<int, bool> linearSearch(int (&searchArray)[20], int data){
    int stepCounter = 0, //ステップ数をカウントする変数
        elementNumber = sizeof(searchArray)/sizeof(searchArray[0]); //searchArrayの要素数
    bool existence = false; //ユーザーの調べたい値が存在するか確認する変数
    //先頭から順番に値を調べていく
    for(int i = 0; i < elementNumber; i++){
        //値が見つかったら存在をtrueにしてステップをカウントして調べるのをやめる
        if (data == searchArray[i]){
            existence = true;
            stepCounter++;
            break;
        }
        stepCounter++;
    }
    //ステップ数と存在するかどうかを返す
    return forward_as_tuple(stepCounter, existence);
}

//二分検索
tuple<int, bool> binarySearch(int (&searchArray)[20], int data){
    int stepCounter = 0, // ステップ数をカウントする変数
        left = 0, //配列の左端の要素を格納する変数
        right = sizeof(searchArray)/sizeof(searchArray[0]) - 1; //配列の右端の要素を格納する変数
    bool existence = false; //ユーザーの調べたい値が存在するか確認する変数

    //配列の中央の値を調べて、それより調べたい値が大きかったら、中央より右側の配列の中央の値を調べる、小さかったら、中央より左側の配列の中央の値を調べる　ことを繰り返す
    while(right > left){
        //中央の値を代入する
        int mid = left + (int)((right - left)/2);
        //中央の値と同じになれば調べることをやめる
        if(searchArray[mid] == data){
            existence = true;
            stepCounter++;
            break;
        }
        //中央の値よりdataが小さかったら、右端の変数に中央の値から１減らした値を代入する
        else if(searchArray[mid] > data){
            right = mid - 1;
            stepCounter++;
        }
        //中央の値よりdataが大きかったら、左側の変数に中央の値から１増やした値を代入する
        else if(searchArray[mid] < data){
            left = mid + 1;
            stepCounter++;
        }
    }

    //ステップ数と存在するかどうかを返す
    return forward_as_tuple(stepCounter, existence);
}
