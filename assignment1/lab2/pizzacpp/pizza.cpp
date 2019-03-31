#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number_people,
        number_person_pizza, //1人が食べるスライスピザの数
        number_all_pizza,  //スライスピザの全体の数
        number_slices_pizza,
        number_all_all_pizza,  //丸いピザの全体の数
        rest_pizza;
    
    double percentage_cheese_pizza,
           percentage_combination_pizza,
           number_cheese_pizza,
           number_combination_pizza,
           cost_cheese_pizza,
           cost_combination_pizza,
           all_cost_cheese_pizza,
           all_cost_combination_pizza,
           sum_price_pizza;
    
    
    //input
    
    cout << "パーティーには何人のお客様がいらっしゃいますか？ >>>";
    cin >> number_people;
    
    if(number_people > 0){
        cout << "1人何枚のスライスピザを食べますか？ <<<";
        cin >> number_person_pizza;
        
        if(number_person_pizza > 0){
            cout << "ピザは何枚のスライスピザに切り分けますか？ <<<";
            cin >> number_slices_pizza;
            
            if(number_slices_pizza >= 0){
                cout << "こちらにはチーズピザとコンビネーションピザの2種類がございます。\nチーズピザの割合は全体のピザのうち何％になさいますか？ <<<";
                cin >> percentage_cheese_pizza;
                
                if(percentage_cheese_pizza >= 0){
                    cout << "チーズピザ1枚にかかる費用は何ドルでしょうか？ :$";
                    cin >> cost_cheese_pizza;
                    
                    if(cost_cheese_pizza >= 0){
                        cout << "コンビネーションピザ1枚にかかる費用は何ドルでしょうか？ :$";
                        cin >> cost_combination_pizza;
                        
                        if(cost_combination_pizza){
                            
                            
                            //process
                            
                            
                            number_all_pizza = number_people * number_person_pizza;
                            
                            percentage_combination_pizza = 100 - percentage_cheese_pizza;
                            
                            number_all_all_pizza = number_all_pizza / number_slices_pizza;
                            
                            if(number_all_pizza % number_slices_pizza != 0)
                                number_all_all_pizza++;
                            
                            number_cheese_pizza = number_all_all_pizza * percentage_cheese_pizza / 100;
                            
                            number_combination_pizza = number_all_all_pizza - number_cheese_pizza;
                            
                            all_cost_cheese_pizza = cost_cheese_pizza * number_cheese_pizza;
                            
                            all_cost_combination_pizza = cost_combination_pizza * number_combination_pizza;
                            
                            sum_price_pizza = all_cost_cheese_pizza + all_cost_combination_pizza;
                            
                            rest_pizza = (number_all_pizza % number_slices_pizza) * 8;
                            
                            
                            //output
                            
                            cout << "ご注文内容を確認させていただきます。" << endl;
                            cout << "ピザはお客様のご要望どおり" << number_slices_pizza << "枚に切り分けさせていただいています。" << endl;
                            cout << "パーティーに来られるお客様数は" << number_people << "名様で、1人" << number_person_pizza << "枚のピザを食べられるということですので、全体で頼むスライスピザの数は" << number_all_pizza << "枚で、ピザの数は" << number_all_all_pizza << "枚でございます。" << endl;
                            cout << fixed << setprecision(1) << "そのうちチーズピザの割合は全体の" << percentage_cheese_pizza << "％という要望ですので"  << number_cheese_pizza << "枚。コンビネーションピザは全体の" << percentage_combination_pizza << "%で"  << number_combination_pizza << "枚です。" << endl;
                            cout << fixed << setprecision(2) << "チーズピザの費用は" << cost_cheese_pizza << "$,コンビネーションピザの費用は" << cost_combination_pizza << "$,ですので,チーズピザ全体の費用は"  << all_cost_cheese_pizza << "＄、コンビネーションピザ全体の費用は" << all_cost_combination_pizza << "＄です。" <<endl;
                            cout << "ピザの合計費用は" << sum_price_pizza << "です。" << endl;
                            cout << "最後にお客様が食べられずに余るスライスピザの数は" << rest_pizza << "枚です。" << endl;
                            
                            
                        }
                    }
                }
            }
        }
    }
    else{
        cout << "入力をやり直してください" << endl;
    }
    
    
}

