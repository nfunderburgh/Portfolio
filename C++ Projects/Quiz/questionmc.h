#ifndef QUESTIONMC_H
#define QUESTIONMC_H
/*********************
 * Class Header(.h)
 *Author: Noah Funderburgh
 *File: questionmc.h
 *Date: 1/30/20
 ****************/
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "question.h"

class questionMC : public question{

    public:
        questionMC();
        ~questionMC();
        void showQuestion();
        void multiChoice(const string &choices);
        void showAnswer();
        bool checkAnswer(string givenAnswer);
};


#endif // QUESTIONMC_H
