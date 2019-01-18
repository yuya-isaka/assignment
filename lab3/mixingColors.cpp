#include <iostream>
#include <string>
using namespace std;

int main()
{
    string color_name_1,
           color_name_2;

    //input

    cout << "red,blue,yellowの3色から混ぜ合わせたい2色を選んでください。2色は被ってはいけません。red,blue,yellow で答えてください。" << endl;
    cout << " >>>";
    cin >> color_name_1;
    cout << "\n >>>";
    cin >> color_name_2;

    //process_and_output

    if(color_name_1 == "red" && color_name_2 == "blue"){

        cout << "redとblue混ぜ合わせたので、purpleができました。" << endl;

    }else if(color_name_1 == "red" && color_name_2 == "yellow"){

        cout << "redとyellowを混ぜ合わせたので、orangeができました。" << endl;

    }else if(color_name_1 == "blue" && color_name_2 == "red"){

        cout << "blueとredを混ぜ合わせたので、purpleができました。" << endl;

    }else if(color_name_1 == "blue" && color_name_2 == "yellow"){

        cout << "blueとyellowを混ぜ合わせたので、greenができました。" << endl;

    }else if(color_name_1 == "yellow" && color_name_2 == "red"){

        cout << "yellowとredを混ぜ合わせたので、orangeができました。" << endl;

    }else if(color_name_1 == "yellow" && color_name_2 == "blue"){

        cout << "yellowとblueを混ぜ合わせたので、greenができました。" << endl;
    }else{

        cout << "入力した色の名前が間違っています。" << endl;
    }

    return 0;
    

}
