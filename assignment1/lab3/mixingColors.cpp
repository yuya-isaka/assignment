#include <iostream>
#include <string>
using namespace std;

int main()
{
    string color_name_1,
           color_name_2;


    while(1){

        cout << "red,blue,yellowの3色から混ぜ合わせたい2色を選んでください。red,blue,yellow で答えてください。混ぜ合わせを終わりたい場合は、'exit exit'と答えてください。" << endl;
    cout << " >>>";
    cin >> color_name_1 >> color_name_2;


    if((color_name_1 == "red" && color_name_2 == "blue") || (color_name_1 == "blue" && color_name_2 == "red")){

        cout << "redとblue混ぜ合わせたので、purpleができました。" << endl;

    }else if((color_name_1 == "yellow" && color_name_2 == "blue") || (color_name_1 == "blue" && color_name_2 == "yellow")){

        cout << "redとyellowを混ぜ合わせたので、greenができました。" << endl;

    }else if((color_name_1 == "red" && color_name_2 == "yellow") || (color_name_1 == "yellow" && color_name_2 == "red")){

        cout << "blueとredを混ぜ合わせたので、orangeができました。" << endl;

    } 
    else if(color_name_1 == "exit" || color_name_2 == "exit"){
        return 0;
    }
    else if((color_name_1 == color_name_2) && !(color_name_1 == "exit" || color_name_2 == "exit")){
        cout << "混ぜ合わせた色は" << color_name_1 << "となりました。" << endl;
    }
    else{
        cin.clear();
        cin.ignore('\n');
        cout << "入力が間違えています。もう一度やり直してください。" << endl;
    }

    }

    return 0;
    

}
