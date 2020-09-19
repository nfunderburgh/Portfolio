//-------------------------
//class implentation(.cpp)
//author: Noah Funderburgh
//File:questionsa.cpp
//-------------------------
#include "question.h"
#include "questionsa.h"

using namespace std;
//------------------------
questionSA::questionSA(){

}
//------------------------
questionSA::~questionSA(){

}
//------------------------
void questionSA::showQuestion(){
    cout << questionText << "?" <<  endl;
}
//------------------------
void questionSA::showAnswer(){
    cout << answerText << endl;
}
//------------------------
bool questionSA::checkAnswer(string answer){
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
