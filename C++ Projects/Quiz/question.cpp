//-------------------------
//class implentation(.cpp)
//author: Noah Funderburgh
//File:question.cpp
//-------------------------
#include <cstring>
#include <iostream>
#include "question.h"

using namespace std;
//------------------------
void question::setQuestion(const string &question){
    questionText = question;
}
//------------------------
/*void question::showQuestion(){
    cout << questionText << endl;
}*/
//------------------------
/*bool question::checkAnswer(string answer){
    string answerTextLower = answerText;
    for(int i = 0;i<=answer.length();i++){
        if(answer[i] >= 65 && answer[i]<=92){
            answer[i]=answer[i]+32;
        }
    }

    for(int i = 0;i<=answerTextLower.length();i++){
        if(answerTextLower[i] >= 65 && answerTextLower[i]<=92){
            answerTextLower[i]=answerTextLower[i]+32;
        }
    }

    if(answer == answerTextLower){
        correct = true;
        return true;
    }
    else{
        correct = false;
        return false;
    }
}*/
//------------------------
void question::setAnswer(const string &answer){
    answerText = answer;
}
//------------------------
void question::showAnswer(){
    cout << answerText << endl;
}
//------------------------
void question::markCorrect(){
    correct = true;
}
//------------------------
