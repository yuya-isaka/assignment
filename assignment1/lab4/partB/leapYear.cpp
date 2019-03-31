#include <iostream>
#include <fstream>
#include <string>
#ifdef max
#define max
#endif


bool leap_test(int);

int main()
{

    int end_year,
        start_year,
        count_year = start_year,
        number_leap_year = 0,
        a[200],
        b = 0;



        std::cout << "うるう年を計算するプログラムです。1900年から2099年の任意の2年間の間のうるう年の数を計算します。" << std::endl << std::endl;
        std::cout << "始まりの年と終わりの年を入力してください。また終わりの年が始まりの年より大きくなるよう入力してください。" << std::endl << std::endl;

        std::cout << "始まりの年を入力してください。" << std::endl << std::endl;


        while(1){
            std::cout << "入力してください。>>>" ;
            std::cin >> start_year;
            if(( start_year >= 1900 ) && ( start_year <=2099 )){
                std::cout << "入力は正しいです。" << std::endl << std::endl;
                break;
            }
            std::cout << "入力を間違えています。もう一度入力してください。" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }


        std::cout << "次に終わりの年を入力してください。" << std::endl << std::endl;


        while(1){
            std::cout << "入力してください。>>>" ;
            std::cin >> end_year;
            if(( end_year >= 1900 ) && ( end_year <=2099 )){
                std::cout << "入力は正しいです。" << std::endl << std::endl << std::endl;
                break;
            }
            std::cout << "入力を間違えています。もう一度入力してください。" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }


        if(start_year > end_year){
            int year = start_year;
            start_year = end_year;
            end_year = year;
        }

        for(int count_year = start_year; count_year <= end_year; count_year++){

            if(leap_test(count_year)){
                number_leap_year++;
                b++;
                a[b] = count_year;
            }


        }


        std::cout << start_year << "-" << end_year << "の" << std::endl <<std::endl;

        std::cout << "うるう年の数は" << number_leap_year << "個です。" << std::endl << std::endl;

        std::cout << "ちなみにうるう年は" << std::endl << std::endl;

        for(int b = 1; b <= number_leap_year; b++){
            std::cout << b << " >>>>> " << a[b] << std::endl << std::endl;
        }

        std::cout << "です。" << std::endl;


}


bool leap_test(int a){

    bool result;

    if(!(a % 4 ==0))
        result =0;
    else if(!(a % 100 == 0))
        result = 1;
    else if(!(a % 400 == 0))
        result = 0;
    else
        result = 1;

    return result;
}
