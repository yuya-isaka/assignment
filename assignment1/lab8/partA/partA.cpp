#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//selectionArrayデータを選択ソートする関数
int selectionSort(vector<int> &selectionArray);

//bubbleArrayデータをバブルソートする関数
int bubbleSort(vector<int> &bubbleArray);

int main(){
    //２つの同一の動的配列を作成、初期化
    vector<int> selectionArray;
    vector<int> bubbleArray;

    //unsortedData.txtファイルからデータを配列に読み込む
    ifstream inputfile;
    inputfile.open("unsortedData.txt");
    if(!inputfile){
        cout << "ファイルを開くことができませんでした。" << endl;
        cout << "プログラムを終了します。" << endl;
        exit(1);
    }
    int numBox;
    while(inputfile >> numBox){
        selectionArray.push_back(numBox);
        bubbleArray.push_back(numBox);
    }
    inputfile.close();

    //ソート前のファイルに入っていたデータを出力
    cout << "ソート前のデータがこちらです。" << endl;
    for(int i = 0; i < selectionArray.size(); i++){
        cout << selectionArray[i] << endl;
    }

    //選択ソートの計算をして何回交換したかを出力
    cout << endl << "選択ソートをします。" << endl;
    int changeCounter = selectionSort(selectionArray);
    cout << "selectionArrayは" << changeCounter << "回の交換でソート完了しました。" << endl;

    //選択ソートされたデータを出力
    cout << "ソートが完了したデータがこちらです。" << endl;
    for(int i = 0; i < selectionArray.size(); i++){
        cout << selectionArray[i] << endl;
    }

    //選択ソートされたデータをファイルに読み込む
    ofstream outputfile;
    outputfile.open("sortedSelectionData.txt");
    if(!outputfile){
        cout << "ファイルを開くことができませんでした。" << endl;
        cout << "プログラムを終了します。" << endl;
        exit(1);
    }
    for(int i = 0; i < selectionArray.size(); i++){
        outputfile << selectionArray[i] << endl;
    }
    outputfile.close();
    outputfile.clear();

    //バブルソートの計算をして何回交換したかを出力
    cout << endl << "バブルソートします。" << endl;
    int changeCounter2 = bubbleSort(bubbleArray);
    cout << "bubbleArrayは" << changeCounter2 << "回の交換でソート完了しました。" << endl;

    //バブルソートされたデータを出力
    cout << "ソートが完了したデータがこちらです。" << endl;
    for(int i = 0; i < bubbleArray.size(); i++){
        cout << bubbleArray[i] << endl;
    }

    //バブルソートされたデータをファイルに読み込む
    outputfile.open("sortedBubbleData.txt");
    if(!outputfile){
        cout << "ファイルを開くことができませんでした。" << endl;
        cout << "プログラムを終了します。" << endl;
        exit(1);
    }
    for(int i = 0; i < bubbleArray.size(); i++){
        outputfile << bubbleArray[i] << endl;
    }
    outputfile.close();

}


//選択ソートの計算をする関数
int selectionSort(vector<int> &selectionArray){
    int changeNumber = 0; //返す値
    for(int i = 0; i < selectionArray.size(); i++){
        int min = selectionArray[i]; //仮の最小値を設定
        for(int j = i + 1; j < selectionArray.size(); j++){
            if(min > selectionArray[j]){    //最小値として選択した値が他の値より小さいか比較する。比較して小さければその値と入れ替える
                swap(selectionArray[i],selectionArray[j]);      //入れ替える
                min = selectionArray[i];    //仮最小値の変更
                changeNumber++;     //交換した数
            }
        }
    }
    return changeNumber;
}


//バブルソートの計算をする関数
int bubbleSort(vector<int> &bubbleArray){
    int changeNumber2 = 0;      //返す値
    int elementNumber = bubbleArray.size();     //bubbleArrayの要素数

    for(int i = 0; i < elementNumber; i++){
        int x = 0;      //最初の要素から比較するために0の入った変数を宣言
        for(int j = x + 1; j < elementNumber; j++){
            if(bubbleArray[j-1] > bubbleArray[j]){      //配列の前後の数を比較して手前の値の方が大きかったら奥の値と入れ替える
                swap(bubbleArray[j-1],bubbleArray[j]);
                changeNumber2++;    //交換した数
            }
        }
    }
    return changeNumber2;
}
