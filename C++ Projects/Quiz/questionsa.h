#ifndef QUESTIONSA_H
#define QUESTIONSA_H
/*********************
 * Class Header(.h)
 *Author: Noah Funderburgh
 *File: questionsa.h
 *Date: 1/30/20
 ****************/
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "question.h"

class questionSA : public question{

    public:
        questionSA();
        ~questionSA();
        void showQuestion();
        void showAnswer();
        bool checkAnswer(string givenAnswer);
};


#endif // QUESTIONMC_H
