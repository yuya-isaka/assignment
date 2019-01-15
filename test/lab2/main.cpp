#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number_people,
        number_person_pizza,   //1人が食べるスライスピザの数
        number_all_pizza,       //スライスピザの全体の個数
        number_slices_pizza,
        number_all_all_pizza,   // 大きいピザの全体の個数
        rest_pizza;
    
    double
           percentage_cheese_pizza,
           percentage_combination_pizza,
           number_cheese_pizza,
           number_combination_pizza,
           cost_cheese_pizza,
           cost_combination_pizza,
           all_cost_cheese_pizza,
           all_cost_combination_pizza,
           sum_price_pizza;
    
    
    //input
    
    cout << "パーティーには何人のお客様がいらっしゃいますか？ >>>" ;
    cin >> number_people;
    
    cout << "1人何枚のスライスピザを食べますか？ >>>" ;
    cin >> number_person_pizza;
    
    cout << "こちらにはチーズピザとコンビネーションピザの2種類ございます。\nチーズピザの割合は全体のピザのうち何%になさいますか？ >>>" ;
    cin >> percentage_cheese_pizza;
    
    cout << "チーズピザ1枚にかかる費用は何ドルでしょうか？ :$" ;
    cin >> cost_cheese_pizza;
    
    cout << "コンビネーションピザ1枚にかかる費用は何ドルでしょうか？　:$" ;
    cin >> cost_combination_pizza;
    
    cout << "ピザは何枚のスライスピザに切り分けますか？ >>>" ;
    cin >> number_slices_pizza;
    
    
    
    
    //process
        
        number_all_pizza = number_people * number_person_pizza;
        
        percentage_combination_pizza = 100 - percentage_cheese_pizza;
    
        number_all_all_pizza = number_all_pizza / number_slices_pizza;
    
        if(number_all_pizza % number_slices_pizza != 0)
        {
            number_all_all_pizza++;
        }
    
        number_cheese_pizza = number_all_all_pizza * percentage_cheese_pizza / 100;
        
        number_combination_pizza = number_all_all_pizza - number_cheese_pizza;

        all_cost_cheese_pizza = cost_cheese_pizza * number_cheese_pizza;
        
        all_cost_combination_pizza = cost_combination_pizza * number_combination_pizza;
        
        sum_price_pizza = all_cost_cheese_pizza + all_cost_combination_pizza;
        
        rest_pizza = (number_all_pizza % number_slices_pizza) * 8;
    
  
    
        //output
    
        cout << "ご注文内容を確認させていただきます。\nピザはお客様の要望通り" << number_slices_pizza << "枚に切り分けさせていただいています。\nパーティーに来られるお客様の数は" << number_people << "名様で、1人" << number_person_pizza <<"枚のピザを食べられるということですので、全体で頼むスライスピザの数は" << number_all_pizza << "枚で,ピザの数は" << number_all_all_pizza << "枚でございます。\nそのうちチーズピザの割合は全体の" << percentage_cheese_pizza << "％という要望ですので" << fixed << setprecision(1) << number_cheese_pizza << "枚。コンビネーションピザは全体の" << fixed << setprecision(1) << percentage_combination_pizza << "％で" << number_combination_pizza << "枚です。\n　チーズピザの費用は" << cost_cheese_pizza << "＄、コンビネーションピザの費用は" << cost_combination_pizza << "$、ですので、チーズピザ全体の費用は" << fixed << setprecision(2) << all_cost_cheese_pizza << "＄、コンビネーションピザ全体の費用は" << fixed << setprecision(2) << all_cost_combination_pizza << "＄、合計費用は" << fixed << setprecision(2) << sum_price_pizza << "$です。\n最後にお客様が食べられずに余るスライスピザの数は" << rest_pizza << "枚です。" <<  endl;
        
    }

    





