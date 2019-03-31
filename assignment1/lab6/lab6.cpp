//isaka yuya lab6 again

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;


//TestTableの表に計算した結果を入れる関数
void calculate(string (&TestTable) [6][6]);


int main(){

    //表の配列を作成初期化
    string TestTable[6][6] {
        {"Name","Exam1","Exam2","Exam3","TotalOfScore","AverageScore"},
            {"John"},
            {"Jane"},
            {"Bill"},
            {"Susan"},
            {"AverageTestScore"},
    };


    //ユーザーにファイルから数値を読み込むか自分で入力するか聞く
    char confirm;
    cout << "あなたが入力するかファイルの数値を読み込むかの二択です。ファイルの数値を読みこみますか？　Y or N :";
    cin >> confirm;
    //入力を間違えていた時の処理
    while(cin.fail() || !(confirm == 'Y' || confirm == 'y' || confirm == 'N' || confirm == 'n' )){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024,'\n');
        cin >> confirm;
    }
    //ファイルから読み込む場合の処理
    if(confirm == 'Y' || confirm == 'y' ){
        string failname;
        cout << "ファイルの名前はなんですか？　:";
        cin >> failname;
        while(cin.fail()){
            cout << "入力を間違えています。" << endl;
            cin.clear();
            cin.ignore(1024,'\n');
            cin >> failname;
        }
        ifstream inputfile;
        inputfile.open(failname);
        //ファイルが開けなかった時の処理
        while(!inputfile){
            cout << "ファイルを開けませんでした" << endl;
            cin.clear();
            cin.ignore(1024,'\n');
            char confirm2;
            cout << "もう一度試しますか？　Y or N :";
            cin >> confirm2;
            while(cin.fail() || !(confirm2 == 'Y' || confirm2 == 'y' || confirm2 == 'n' || confirm2 == 'N')){
                cout << "入力を間違えています。" << endl;
                cin.clear();
                cin.ignore(1024,'\n');
                cin >> confirm2;
            }
            if(confirm2 == 'N' || confirm == 'n'){
                exit(1);
            }
            if(confirm2 == 'Y' || confirm2 == 'y'){
                cout << "もう一度入力してください :";
                cin >> failname;
                inputfile.close();
                inputfile.open(failname);
            }
        }

        //ファイルに読み込む処理
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 4; j++){
                inputfile >> TestTable[i][j];
            }
        }
        inputfile.close();
    }

    //入力がnoだった時の処理
    else{
        cout << "それでは4人のテスト結果を入力してください。" << endl;
        for(int i = 1; i < 5; i++){
            for(int j = 1; j < 4; j++){
                cout << TestTable[i][0] << "のテスト" << j << "の結果は :";
                cin >> TestTable[i][j];
                while(cin.fail()){
                    cout << "入力を間違えています。" << endl;
                    cin.clear();
                    cin.ignore(1024,'\n');
                    cout << "もう一度入力してください　:";
                    cin >> TestTable[i][j];
                }
                cout << endl;
            }
        }
    }

    //現時点での表を画面に出力
    cout << "数値の表が完成しました。" << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cout << setw(8) << TestTable[i][j];
        }
        cout << endl;
    }

    //表の二次元配列に新しい配列を組み込む


    //TotalOfScoreの配列とAverageScoreの配列を作る
    cout << "次にそれぞれのTotalOfScoreとAverageScoreを入力します。" << endl;
    cout << endl;



    //関数を利用して計算
    calculate(TestTable);
    /*
    //TotalOfScoreとAverageScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 5; i++){
    double TotalOfScore,
    AverageScore;
    TotalOfScore = stod(TestTable[i][1]) + stod(TestTable[i][2]) + stod(TestTable[i][3]);
    TotalOfScore = round(TotalOfScore*10)/10;
    AverageScore = TotalOfScore/3.0;
    AverageScore = round(AverageScore*10)/10;
    TestTable[i][4] = to_string(TotalOfScore);
    TestTable[i][5] = to_string(AverageScore);
    }

    //TotalTestScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 6; i++){
    double AverageTestScore;
    AverageTestScore = (stod(TestTable[1][i]) + stod(TestTable[2][i]) + stod(TestTable[3][i]) + stod(TestTable[4][i]))/4.0;
    AverageTestScore = round(AverageTestScore*10)/10;
    TestTable[5][i] = to_string(AverageTestScore);
    }
    */

    /*
    //TotalOfScoreとAverageScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 5; i++){
    double TotalOfScore;
    for(int j = 1; j < 4; j++){
    TotalOfScore += stod(TestTable[i][j]);
    }
    double AverageScore;
    TotalOfScore = round(TotalOfScore*10)/10;
    AverageScore = TotalOfScore/3.0;
    AverageScore = round(AverageScore*10)/10;
    stringstream sout1,
    sout2;
    sout1 << fixed << setprecision(1) << TotalOfScore;
    sout2 << fixed << setprecision(1) << AverageScore;
    TestTable[i][4] = sout1.str();
    TestTable[i][5] = sout2.str();
    }

    //TotalTestScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 6; i++){
    double TotalTestScore;
    for(int j = 1; j < 5; j++){
    TotalTestScore += stod(TestTable[j][i]);
    }
    double AverageTestScore;
    AverageTestScore = TotalTestScore/4.0;
    AverageTestScore = round(AverageTestScore*10)/10;
    stringstream sout;
    sout << fixed << setprecision(1) << AverageTestScore;
    TestTable[5][i] = sout.str();
    }
    */



    cout << "出来上がった表がこちらです。" << endl;
    cout << endl;

    //結果の表を出力
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << setw(17) << TestTable[i][j];
        }
        cout << endl;
    }

    //ファイル名を聞きファイルを開く
    cout << "次にそれぞれのTotalOfScoreとAverageScoreを入力した表をファイルに書き込みます。" << endl;
    cout << "なんと言う名前のファイルに書き込みますか？ :"; 
    string failname2;
    cin >> failname2;
    cout << endl;
    while(cin.fail()){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024,'\n');
        cout << "もう一度入力してください。:";
        cin >> failname2;
        cout << endl;
    }
    ofstream outputfile;
    outputfile.open(failname2);

    //ファイルに書き込む処理
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            outputfile << setw(17) << TestTable[i][j];
        }
        outputfile << endl;
    }
    cout << "入力が完了しました。" << endl;
    outputfile.close();

    //exam2の結果が上昇した表を作る
    cout << "exam2の結果が15％上昇した数値を表に入れます。" << endl;
    for(int i = 1; i < 5; i++){
        stringstream sout3;
        sout3 << fixed << setprecision(1) << stod(TestTable[i][2])*1.15;
        TestTable[i][2] = sout3.str();
    }

    //計算して入力する。
    calculate(TestTable);

    cout << "出来上がった表を表示します。" << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << setw(17) << TestTable[i][j];
        }
        cout << endl;
    }

    //ファイルに入力する。
    cout << "次にexam2の結果が15%上昇した数値をファイルに入力します。なんというファイルに書き込みますか？ :" ;
    string failname3;
    cin >> failname3;
    cout << endl;
    while(cin.fail()){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024,'\n');
        cout << "もう一度入力してください。:";
        cin >> failname3;
        cout << endl;
    }
    outputfile.open(failname3);

    //ファイルに書き込む処理
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            outputfile << setw(17) << TestTable[i][j];
        }
        outputfile << endl;
    }
    cout << "入力が完了しました。" << endl;
    outputfile.close();


}



//TestTableの表に計算した結果を入れる関数
void calculate(string (&TestTable)[6][6]){
    //TotalOfScoreとAverageScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 5; i++){
        double TotalOfScore;
        for(int j = 1; j < 4; j++){
            TotalOfScore += stod(TestTable[i][j]);
        }
        double AverageScore;
        TotalOfScore = round(TotalOfScore*10)/10;
        AverageScore = TotalOfScore/3.0;
        AverageScore = round(AverageScore*10)/10;
        stringstream sout1,
                     sout2;
        sout1 << fixed << setprecision(1) << TotalOfScore;
        sout2 << fixed << setprecision(1) << AverageScore;
        TestTable[i][4] = sout1.str();
        TestTable[i][5] = sout2.str();
    }

    //TotalTestScoreの値をTestTableに入力
    //二次元配列を利用した計算
    for(int i = 1; i < 6; i++){
        double TotalTestScore;
        for(int j = 1; j < 5; j++){
            TotalTestScore += stod(TestTable[j][i]);
        }
        double AverageTestScore;
        AverageTestScore = TotalTestScore/4.0;
        AverageTestScore = round(AverageTestScore*10)/10;
        stringstream sout;
        sout << fixed << setprecision(1) << AverageTestScore;
        TestTable[5][i] = sout.str();
    }
}
