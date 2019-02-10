#include <iostream>
#include <string>
#include <fstream>

const int x = 9;

bool CheckAnswer(std::string,std::string b[x],int);
bool CheckUserAnswer(std::string);
void IntoUserAnswer(std::string,std::string (&b)[x],int);


int main()
{
    std::ifstream ipfile,
        ippfile;
    std::ofstream opfile;
    int Count = 1,
        Number,
        CorrestAnswer = 0;
    std::string Question,
        UserAnswer,
        ArrayUserAnswer[x],
        Answer;


        ipfile.open("questions.txt");
        if(ipfile.fail()){
            std::cout << "ファイルを読み込めませんでした。" << std::endl;
            exit(1);
        }



        while(getline(ipfile,Question)){

            std::cout << Question << std::endl << std::endl;
            std::cout << "答えを入力してください。" << std::endl;


            while(1){
                std::cout << "Answer...";
                std::cin >> UserAnswer;
                if(std::cin.fail()){
                    std::cout << "入力を間違えています。再度入力してください。" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                }


                else if(CheckUserAnswer(UserAnswer)){
                    IntoUserAnswer(UserAnswer,ArrayUserAnswer,Count);
                    std::cout << std::endl;
                    Count++;
                    break;
                }

                else{
                    std::cout << "入力を間違えています。A,B,C,D のどれかを入力してください。" << std::endl;
                }        
                std::cout << "もう一度入力してください。" << std::endl;
            }
        }

        ipfile.close();


        ippfile.open("answers.txt");
        opfile.open("studentResults.txt");

        while(ippfile >> Number >> Answer){

            if(CheckAnswer (Answer,ArrayUserAnswer,Number)){
                std::cout << Number << "answer" << ArrayUserAnswer[Number] << "correst" << std::endl << std::endl;
                opfile << Number << "answer" << ArrayUserAnswer[Number] << "correst" << std::endl;
            }
            else{
                std::cout << Number << "answer" << ArrayUserAnswer[Number] << "incorrest" << std::endl;
                std::cout << "答えは" << Answer << " です。" << std::endl;
                CorrestAnswer++;
                opfile << Number << "answer" << ArrayUserAnswer[Number] << "incorrest" << std::endl;
            }

        }
        ippfile.close();
        opfile.close();
        std::cout << "8問中" << CorrestAnswer << "問不正解です。" << std::endl;

}


bool CheckAnswer (std::string a,std::string b[x],int c){
    bool result;

    if(a == b[c])
        result = 1;
    else
        result = 0;

    return result;
}

bool CheckUserAnswer (std::string a){
        bool result;

    if((a == "A") || (a == "B") || (a == "C") || (a == "D"))
        result = 1;
    else
        result = 0;

    return result;

}


void IntoUserAnswer (std::string a,std::string (&b)[x],int c){
    b[c] = a;
}
