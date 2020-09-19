#ifndef QUESTION_H
#define QUESTION_H
/***********************
 *Class Header(.h)
 *Author: Noah Funderburgh
 *File: question.h
 *Date:1/25/20
 **********************/ 
#include<string>
using namespace std;

class question{
    protected: 
        string questionText;
        string answerText;
        bool correct;

    public:
        void setQuestion(const string &question);
        virtual void showQuestion() = 0;
        virtual bool checkAnswer( string givenAnswer) = 0;
        void setAnswer(const string &answer);
        virtual void showAnswer();
        void markCorrect();

};
#endif //QUESTION_H
