#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){

    vector<vector<string> > report;
    vector<string> salesPerson = {"Sales Person"};
    vector<string> carsSold = {"Cars Sole"};
    vector<string> percentOfScore = {"\% of Sales"};
    string personData,
           soldData;
    int percentData,
        totalSoldData = 0;

    //セールスマンの名前をユーザーに入力してもらう
    cout << "車の売り上げの表を作ります。セールスマンの名前を入力してください。" << endl;
    cout << "1人ずつ入力してください。入力し終えたら'NoPerson'と入力してください。" << endl;
    //何人でも入力できる
    while(1){
        cout << " :";
        cin >> personData;
        //入力の確認
        while(cin.fail()){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << " :";
            cin >> personData;
        }
        //ユーザーがNoPersonと打ったら入力が終わる
        if(personData == "NoPerson"){
            break;
        }
        salesPerson.push_back(personData);
    }
    //セールスマンを画面に出力する
    cout << "セールスマンは ";
    for(int i = 1; i < salesPerson.size(); i++){
        cout << salesPerson[i] << ", ";
    }
    cout << "ですね。" << endl;

    //セールスマンの売り上げを入力してもらう
    cout << endl << "それぞれのセールスマンの売り上げを教えてください。" << endl;
    for(int i = 1; i < salesPerson.size(); i++){
        cout << salesPerson[i] << "の売り上げは？ :";
        cin >> soldData;
        //入力の確認
        while(cin.fail()){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "売り上げは？ :";
            cin >> soldData;
        }
        carsSold.push_back(soldData);
    }

    //全員の売り上げの合計を計算
    for(int i = 1; i < carsSold.size(); i++){
        totalSoldData += stoi(carsSold[i]);
    }

    //それぞれの売り上げの割合を調べる
    for(int i = 1; i < carsSold.size(); i++){
        percentData = (int)stoi(carsSold[i])*100/totalSoldData;
        percentOfScore.push_back(to_string(percentData));
    }

    //表を出力する
    cout << endl << "出来上がった表がこちらです。" << endl;

    for(int i = 0; i < salesPerson.size(); i++){
        stringstream sout1,
                     sout2,
                     sout3;
        sout1 << setw(15) << salesPerson[i];
        sout2 << setw(15) << carsSold[i];
        sout3 << setw(15) << percentOfScore[i];
        report.push_back({sout1.str(), sout2.str(), sout3.str()});
    }

    for(int i = 0; i < report.size(); i++){
        for(int j = 0; j < report.front().size(); j++){
            cout << report[i][j] << " ";
        }
        cout << endl;
    }

}
