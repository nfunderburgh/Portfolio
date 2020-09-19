#ifndef QUESTIONTF_H
#define QUESTIONTF_H
/*********************
 * Class Header(.h)
 *Author: Noah Funderburgh
 *File: questionTF.h
 *Date: 1/30/20
 ****************/

#include "question.h"

class questionTF : public question{

    public:
        questionTF();
        ~questionTF();
        void showQuestion();
        void showAnswer();
        bool checkAnswer(string givenAnswer);
};


#endif // QUESTIONTF_H
