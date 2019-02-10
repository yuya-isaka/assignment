#include <iostream>
#include <string>
#include <fstream>

bool CheckAnswer(int,int);

int main()
{
    std::ifstream ipfile,
        ippfile;
    std::ofstream opfile;
    int count = 1,
        Number,
        CorrestAnswer = 0;
    const int a = 9;
    std::string Question,
        UserAnswer,
        ArrayUserAnswer[a],
        A = "A",
        B = "B",
        C = "C",
        D = "D",
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


                else if((UserAnswer == A) || (UserAnswer == B) || (UserAnswer == C) || (UserAnswer == D)){
                    ArrayUserAnswer[count] = UserAnswer;
                    count++;

                    std::cout << std::endl;
                    break;
                }else{
                    std::cout << "入力を間違えています。A,B,C,D のどれかを入力してください。" << std::endl;
                }        
                std::cout << "もう一度入力してください。" << std::endl;
            }
        }

        ipfile.close();


        ippfile.open("answers.txt");
        opfile.open("studentResults.txt");

        while(ippfile >> Number >> Answer){

            if(Answer == ArrayUserAnswer[Number]){
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
