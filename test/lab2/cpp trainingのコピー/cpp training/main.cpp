#include <iostream>
using namespace std;

int main()
{
    int one_person_pizza;  //1人あたりのスライスピザの数
    int all_person_pizza;  //合計のスライスピザの数
    int need_cheese_pizza; //最低限必要なチーズピザの割合
    int number_cheese_pizza;  //チーズピザの数
    int number_combination_pizza; //コンビネーションピザの数
    double sum_price_pizza;    //ピザの合計金額
    int rest_pizza;        //食べられずに残されたスライスピザの数
    
    cout << "1人何枚のスライスピザを食べますか？ 自然数でお答えください。" << endl;
    cin >> one_person_pizza;
    
    if(one_person_pizza == 0){
        cout << "お帰りください" << endl;
    }
    else{
    all_person_pizza = one_person_pizza * 40;   //合計のスライスピザの数
    
    need_cheese_pizza = all_person_pizza * 0.25;  //最低限必要なチーズピザの割合
    
    cout << "そのうち何枚のチーズピザを頼みますか？" << need_cheese_pizza << "枚以上でお答えください。数字でお答えください。" << endl;
    cin >> number_cheese_pizza;
    
    number_combination_pizza = all_person_pizza - number_cheese_pizza;
    sum_price_pizza = number_cheese_pizza * 8.99 + number_combination_pizza * 10.50;
    
    cout << "かしこまりました。合計金額は" << sum_price_pizza << "ドルとなります。" << endl;
    
    rest_pizza = all_person_pizza % 8;          //食べられずに残されたスライスピザの数
    
    cout << "焼いたピザのうち、食べられずに残されたスライスピザの数は" << rest_pizza << "です。" << endl;
    
    }
}
