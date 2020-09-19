//-------------------------
//class implentation(.cpp)
//author: Noah Funderburgh
//File:questiontf.cpp
//-------------------------
#include <cstring>
#include <iostream>
#include "question.h"
#include "questiontf.h"

using namespace std;
//------------------------
questionTF::~questionTF(){

}
//------------------------
questionTF::questionTF(){

}
//------------------------
void questionTF::showQuestion(){
    cout << questionText << " (True or False?)" <<  endl;
}
//------------------------
void questionTF::showAnswer(){
    cout << answerText << endl;
}
//------------------------
bool questionTF::checkAnswer(string answer){
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

    if(answer.at(0) == answerTextLower.at(0)){
        correct = true;
        return true;
    }
    else{
        correct = false;
        return false;
    }
}
//------------------------
