#include <iostream>
#include <string>
#include <fstream>

bool HourTest(int);
bool MinuteTest(int);

int main()
{

    std::ifstream inputfile;
    std::ofstream outputfile;
    unsigned int Hour,
                 Minutes;

    inputfile.open("timeDate.txt");
    outputfile.open("timeValidation.txt");

    if(inputfile && outputfile){

        while(inputfile >> Hour >> Minutes){
            if(HourTest(Hour) && MinuteTest(Minutes)){
                std::cout << Hour << ":" << Minutes << "hours and minutes are valid " << std::endl;
                outputfile << Hour << ":" << Minutes << "hours and minutes are valid " << std::endl;
            }
            else if(HourTest(Hour) && !(MinuteTest(Minutes))){
                std::cout << Hour << ":" << Minutes << "hour is valid and minutes are invalid" << std::endl;
                outputfile << Hour << ":" << Minutes << "hour is valid and minutes are invalid" << std::endl;
            }
            else if(!HourTest(Hour) && (MinuteTest(Minutes))){
                std::cout << Hour << ":" << Minutes << "hour is invalid minutes are valid " << std::endl;
                outputfile << Hour << ":" << Minutes << "hour is invalid minutes are valid " << std::endl;
            }
            else if(!(HourTest(Hour) && MinuteTest(Minutes))){
                std::cout << Hour << ":" << Minutes << "hour and minutes are both invalid" << std::endl;
                outputfile << Hour << ":" << Minutes << "hour and minutes are both invalid" << std::endl;
            }
        }
    }else{
        std::cout << "ファイルを読み込み出力することができませんでした。" << std::endl;
    }


    inputfile.close();
    outputfile.close();
}



bool HourTest(int a)
{
    bool result;

    if (a <= 24)
        result = 1;
    return result;
}

bool MinuteTest(int a)
{
    bool result;

    if(a <= 60)
        result = 1;
    return result;
}
