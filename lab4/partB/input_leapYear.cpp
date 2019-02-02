#include <iostream>
#include <fstream>
#include <string>
#ifdef max
#define max
#endif

bool test_leap(int);

int main()
{

    std::ifstream inputfile;

    std::string file_name;

    int year1,
        year2;



    std::cout << "ファイルに書いてある2年間の間のうるう年の数を計算するプログラムです。" << std::endl;
    std::cout << "読み出すファイル名を入力してください" << std::endl;


    while(1){
        std::cout << ">>>";
        std::cin >> file_name;
        if(std::cin.fail()){
            std::cout << "入力を間違えています。もう一度入力してください。" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else 
            break;
    }

    inputfile.open(file_name);


    if(inputfile){


        while(inputfile >> year1 >> year2){

            int count_year = year1,
                number_leap_year = 0;

            if(year1 > year2){
                int year3 = year1;
                year1 = year2;
                year2 = year3;
            }

            for(int count_year = year1; count_year <= year2; count_year++){

                if(test_leap(count_year))
                    number_leap_year++;

            }

            if((year1 >= 1900) && (year1 <= 2099) && (year2 >= 1900) && (year2 <= 2099))
                std::cout << year1 << "-" << year2 << " there are " << number_leap_year << " leap years in this range" << std::endl;
            else
                std::cout << year1 << "-" << year2 << " (invalid range error for calculation)" << std::endl;

        }


        inputfile.close();


    }else
        std::cout << "そのようなファイルは存在しません。" << std::endl;


}


bool test_leap(int a){

    bool result;

    if(!(a % 4 == 0))
        result = 0;
    else if(!(a % 100 == 0))
        result = 1;
    else if(!(a % 400))
        result = 0;
    else
        result = 1;
    return result;
}
