#include "Question.h"
#include <iostream>
#include <string>
using namespace std;

Question::Question()
{
    questionX = "";
    answer1 = "";
    answer2 = "";
    answer3 = "";
    answer4 = "";
    correctAnswer = 0;
}


Question::Question(string question, string ans1, string ans2, string ans3, string ans4, unsigned short int correct)
{
    
    questionX = question;
    answer1 = ans1;
    answer2 = ans2;
    answer3 = ans3;
    answer4 = ans4;
    correctAnswer = correct;
    
}

void Question::setQuestion(string question)
{
    questionX = question;
}
void Question::setAnswer1(string ans)
{
    answer1 = ans;
}
void Question::setAnswer2(string ans)
{
    answer2 = ans;
}
void Question::setAnswer3(string ans)
{
    answer3 = ans;
}
void Question::setAnswer4(string ans)
{
    answer4 = ans;
}
void Question::setCorrect(unsigned short int correct)
{
    correctAnswer = correct;
}


string Question::getQuestion()
{
    return questionX;
}
string Question::getAnswer1()
{
    return answer1;
}
string Question::getAnswer2()
{
    return answer2;
}
string Question::getAnswer3()
{
    return answer3;
}
string Question::getAnswer4()
{
    return answer4;
}
unsigned short int Question::getCorrectAnswer()
{
    return correctAnswer;
}


