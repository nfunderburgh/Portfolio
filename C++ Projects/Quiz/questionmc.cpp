//-------------------------
//class implentation(.cpp)
//author: Noah Funderburgh
//File:questionmc.cpp
//-------------------------
#include "question.h"
#include "questionmc.h"

using namespace std;
//------------------------
questionMC::~questionMC(){

}
//------------------------
questionMC::questionMC(){

}
//------------------------
void questionMC::multiChoice(const string &choices){
    int size = count(choices.begin(),choices.end(),':');
        stringstream ss(choices);
        string token;
        for(int i = 0; i<=size;i++){
            getline(ss,token,':');
            cout <<"   " <<  token << endl;
        }

}
//------------------------
void questionMC::showQuestion(){
    int size = count(questionText.begin(),questionText.end(),':');
    char letter = 'A';
        stringstream ss(questionText);
        string token;
        for(int i = 0; i<=size;i++){
            getline(ss,token,':');
            if(i ==0){
                cout << token << "?" << endl;
            }
            else{
            cout <<"   (" << letter <<") " <<  token << endl;
            letter++;
            }
        }
}
//------------------------
void questionMC::showAnswer(){
    cout << answerText << endl;
}
//------------------------
bool questionMC::checkAnswer(string answer){
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
