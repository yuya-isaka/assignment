#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#ifdef max
#define max
#endif

int money_test(int);

int main()
{

    std::cout << "旅行のプランがあります。それぞれのプランの金額を貯めるのにかかる日数を調べるプログラムです。" << std::endl << std::endl;


    std::ifstream inputfile;

    std::ofstream outputfile;

    std::string country_name,
        country_array[10];

    int money,
        money_array[10],
        number = 0,
        day_array[10],
        a = 1;



        inputfile.open("tripSavingPlans.txt");
        outputfile.open("daysNeededPerTrip");

        if(inputfile){


            while(inputfile >> country_name >> money){
                number++;
                std::cout << country_name << ":" << money << "ドル" << std::endl << std::endl;
                country_array[number] = country_name;
                money_array[number] = money;
            }

            std::cout << "左が旅行場所。右が旅行にかかる費用です。" << std::endl;


            for(int x = 1; x <= number; x++){
                day_array[x] = money_test(money_array[x]);
            }

            std::cout << "旅行の費用は、1日目を２セントとして、毎日2倍して貯金していきます。" << std::endl << std::endl;


            for(int a = 1; a <= number; a++){
                std::cout << country_array[a] << " は " << money_array[a] << "ドルかかるので、貯金を貯めるのにかかる日数は"<< day_array[a] << "日です。" << std::endl << std::endl;
                outputfile << country_array[a] << " は " << money_array[a] << "ドルかかるので、貯金を貯めるのにかかる日数は"<< day_array[a] << "日です。" << std::endl;

            }


            inputfile.close();
            outputfile.close();

        }else
            std::cout << "ファイルが存在しません。" << std::endl;

}


int money_test(int trip_money){

    double x = 0,
           y = 0,
           z = 0.02;
    int day = 0;

    for(double y = 0; x <= (double)trip_money; z = y*2){
        y = z;
        x += z;
        day++;
    }
    return day;


}
