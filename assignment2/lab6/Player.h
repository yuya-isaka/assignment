
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "LoShuSquare.h"

using namespace std;

//ユーザーとの対話
class Player : public LoShuSquare
{
    private:
        int tateBox,
            yokoBox,
            numberBox;
    public:
        Player(){
            LoShuSquare Object1;
            cout << "魔法陣を作ります！" << endl;
            cout << "魔法陣の位置を定めて数値を入れてください。あなたの入れた数字が魔法陣になっているか調べます。" << endl << endl;
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
        };
        void getSquare2() {
            getSquare(tateBox, yokoBox, numberBox);
        };    
        void getprint(){
            print();
        };
        void getmahoujin(){
            if(checkSquare()){
                cout << endl << "あなたの入力した数値で魔法陣ができました。" << endl;
            }
            else{
                cout << endl << "あなたの入力した数値では魔法陣はできませんでした。" << endl;
            }

        };
        ~Player(){};
};

/*
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
