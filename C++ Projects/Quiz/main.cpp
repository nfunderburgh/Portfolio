#include<iostream>
#include<fstream>
#include "quiz.h"
#include "question.h"
#include "questiontf.h"
/****************
 *Main File
 *Author: Noah Funderburgh
 *File Main.cpp
 *Date: 1/25/20
 * **************/
using namespace std;

int main(int argc, char *argv[]){
    string file = argv[1];
    cout << endl << "Hope your ready. It's quiz time!!!" << endl;
    cout << "After each answer is displayed, press enter to see the next question."<< endl << endl;
    quiz quiz;
    string dump = "-d";
    if(argc == 3){
        if(argv[2] == dump){
            quiz.loadQuestions(argv[1]);
            quiz.dumpQuestions();
        }
        else{
            cerr << "Failed to dump, Please use format (excutable filename.txt -d)." << endl;
            return 0;
        }
    }
    else{
        int correct;
        int numQuestions;
        cout <<"---------------------" << endl;
        quiz.loadQuestions(argv[1]);
        cout << endl;
        correct = quiz.deliverQuiz();
        numQuestions = quiz.numQuestions();

        try{
            if(numQuestions == 0){
                throw numQuestions;
            }
        }
        catch(...){
            cerr << "No questions were loaded!" << endl << endl;;
            return 0;
        }

        float percent = (correct*100) / numQuestions;
        cout << "You got " << correct << " of " << numQuestions << " correct: " << percent << "%." << endl;
    }
    return 0;
}
