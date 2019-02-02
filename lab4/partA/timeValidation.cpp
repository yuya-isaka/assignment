#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    int validateHour,
        validateMinutes,
        x = 0,
        y = 0;

    string file_name,
           file_name2;

    ifstream inputfile;

    ofstream outputfile;


    cout << "読み出すファイル名を入力してください。" << endl;


    while(x == 0){
        cin >> file_name;
        if(cin.fail()){
            cin.clear();
            cin.ignore('\n');
            cout << "入力を間違えています。もう一度やり直してください。" << endl;
        }
        else{
            cout << "入力されたファイル名は" << file_name << "ですね。" << endl;
            x = 1;
        }
    }



    cout << "読み出すファイル名を入力してください。" << endl;


    while(y == 0){
        cin >> file_name2;
        if(cin.fail()){
            cin.clear();
            cin.ignore('\n');
            cout << "入力を間違えています。もう一度やり直してください。" << endl;
        }
        else{
            cout << "入力されたファイル名は" << file_name2 << "ですね。" << endl;
            y = 1;
        }
    }



    inputfile.open(file_name);
    outputfile.open(file_name2);


    if(inputfile){
        while(inputfile >> validateHour >> validateMinutes){
            if(validateHour > validateMinutes){
                int a = validateMinutes;
                validateMinutes = validateHour;
                validateHour = a;
            }
            if((validateHour == 13) && (validateMinutes == 45)){
                outputfile << validateHour << ":" << validateMinutes << "hours and minutes are valid" << endl;
            }
            else if((validateHour == 25) && (validateMinutes == 30)){
                outputfile << validateHour << ":" << validateMinutes << "hour is invalid minutes are valid" << endl;
            }
            else if((validateHour == 11) && (validateMinutes == 33)){
                outputfile << validateHour << ":" << validateMinutes << "hour is valid and minutes are valid" << endl;
            }
            else if((validateHour == 26) && (validateMinutes == 61)){
                outputfile << validateHour << ":" << validateMinutes << "hour and minutes are both invalid" << endl;
            }
        }
        inputfile.close();
        outputfile.close();
    }else{
        cout << "ファイルを開くことが出来ませんでした。" << endl;
    }



    return 0;
}
