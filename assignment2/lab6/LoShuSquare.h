
#ifndef LOSHUSQUARE_H
#define LOSHUSQUARE_H

#include <iostream>
#include <iomanip>

using namespace std;

class LoShuSquare
{
    private:
        int agamegrid[3][3];
    public:
        LoShuSquare(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; i < 3; j++){
                    agamegrid[i][j] = 0;
                }
            }
        };
        ~LoShuSquare(){};
        void getSquare(const int tateParameter, const int yokoParameter, const int numberParameter){
            agamegrid[tateParameter][yokoParameter] = numberParameter;
        };
        void print(){
            for(int i = 0; i < 3; i++){
                cout << setw(3) << "|";
                for(int j = 0; j < 3; j++){
                    cout << setw(3) << agamegrid[i][j] << "|";
                }
                cout << "------------" << endl;
            }
        };
        bool checkSquare(){
            int yokoSum[3],
            tateSum[3];
            bool check = true;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    yokoSum[i] += agamegrid[i][j];
                    tateSum[i] += agamegrid[j][i];
                }
            }
            int nanameSum1,nanameSum2;
            for(int i = 0; i < 3; i++){
                nanameSum1 += agamegrid[i][i];
            }
            int jjj = 2;
            for(int i = 0; i < 3; i++){
                nanameSum2 += agamegrid[i][jjj];
                jjj--;
            }

            for(int i = 0; i < 3; i++){
                if(nanameSum1 != yokoSum[i] || nanameSum1 != tateSum[i]){
                    check = false;
                    break;
                }
                else if(nanameSum1 != nanameSum2){
                    check = false;
                    break;
                }
            }
            return check;
        };
};

/*
//初期化
LoShuSquare::LoShuSquare(){
for(int i = 0; i < 3; i++){
for(int j = 0; i < 3; j++){
agamegrid[i][j] = 0;
}
}
}

void LoShuSquare::getSquare(const int tate, const int yoko, const int number){
agamegrid[tate][yoko] = number;
}

void LoShuSquare::print(){
for(int i = 0; i < 3; i++){
cout << setw(3) << "|";
for(int j = 0; j < 3; j++){
cout << setw(3) << agamegrid[i][j] << "|";
}
cout << "------------" << endl;
}
}

bool LoShuSquare::checkSquare(){
int yokoSum[3],
tateSum[3];
bool check = true;
for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j++){
yokoSum[i] += agamegrid[i][j];
tateSum[i] += agamegrid[j][i];
}
}
int nanameSum1,nanameSum2;
for(int i = 0; i < 3; i++){
nanameSum1 += agamegrid[i][i];
}
for(int i = 0; i < 3; i++){
int j = 2;
nanameSum2 += agamegrid[i][j];
j--;
}

for(int i = 0; i < 3; i++){
if(nanameSum1 != yokoSum[i] || nanameSum1 != tateSum[i]){
check = false;
break;
}
else if(nanameSum1 != nanameSum2){
check = false;
break;
}
}
return check;
}


//ユーザーとの対話
class player : public LoShuSquare
{
private:
int tateBox,
yokoBox,
numberBox;
public:
player();
~player(){};
};

player::player(){
cout << "魔法陣を作ります！" << endl;
cout << "魔法陣の位置を定めて数値を入れてください。あなたの入れた数字が魔法陣になっているか調べます。" << endl << endl;
for(int i = 0; i < 9; i++){
    cout << "縦の位置を入力して下さい。(0-2で選んでください) :";
    cin >> tateBox;
    while(cin.fail()){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "もう一度入力して下さい。 :";
        cin >> tateBox;
    }
    cout << "横の位置を入力して下さい。(0-2で選んでください) :";
    cin >> yokoBox;
    while(cin.fail()){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "もう一度入力して下さい。 :";
        cin >> yokoBox;
    }
    cout << "数値を入力して下さい。(ただし一桁の自然数とすること) :";
    cin >> numberBox;
    while(cin.fail()){
        cout << "入力を間違えています。" << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "もう一度入力して下さい。 :";
        cin >> numberBox;
    }
    getSquare(tateBox, yokoBox, numberBox);
    print();
}
if(checkSquare()){
    cout << endl << "あなたの入力した数値で魔法陣ができました。" << endl;
}
else{
    cout << endl << "あなたの入力した数値では魔法陣はできませんでした。" << endl;
}
}
*/

#endif

