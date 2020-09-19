#ifndef QUIZ_H
#define QUIZ_H
/**************
 * Class Header(.h)
 * Author: Noah Funderburgh
 * File:quiz.h
 * Date: 1/28/20
 * ***************/
#include "question.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class quiz{
      
        vector<question*> questions;
    public:
        quiz();
        void setFilename(string filename);
        bool isAnswerMulti(string line);
        bool isType(string line);
        bool spacedCorrect(string line);
        bool isLevel(string line);
        bool checkLine(string line);
        bool isComment(string line);
        bool loadQuestions(string filename);
        void dumpQuestions();
        int deliverQuiz();
        int numQuestions();

};

#endif //QUIZ_H
