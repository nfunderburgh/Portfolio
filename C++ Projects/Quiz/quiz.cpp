//-------------------------
//class implentation(.cpp)
//author: Noah Funderburgh
//File: quiz.cpp
//-------------------------
#include "quiz.h"
#include "questiontf.h"
#include "questionmc.h"
#include "questionsa.h"
using namespace std;
//-------------------------
quiz::quiz(){

}
//-------------------------
bool quiz::isAnswerMulti(string line){
    int countSemiColons = 0;
    if(line[0] == 'M'){
        for(int i = 0;i<=line.length();i++){
            if(line[i] == ':'){
                if(line[i+1] == ':'){
                    cerr << "No given answer between Colons, ";
                    return false;
                }
                countSemiColons++;
            }
        }
        countSemiColons++;

        char isLower = countSemiColons + 'a';
        char isUpper = countSemiColons + 'A';
        int size = line.size();
        if(line[size-1] >= 'a' && line[size-1] < isLower){
            return true;
        }
        if(line[size-1] >= 'A' && line[size-1] < isUpper){
            return true;
        }
        else{
            cerr << "Answer does not match questions, ";
            return false;
        }
    }
    else{ 
        return true;
    }
}
//-------------------------
bool quiz::isType(string line){
    if( line[0] != 'M' && line[0]!='S' && line[0] != 'T'){
        cerr << "Type is inncorrect, ";
        return false;
    }
    return true;
}
//-------------------------
bool quiz::spacedCorrect(string line){
    int countMultiQuestions = 0;
    int countSpacers = 0;
    if(line[1] != '|' || line[3] != '|'){
        cerr << "Delimiters are in inncorrect places, ";
        return false;
    }
    for(int i = 0;i<=line.length();i++){
        if(line[0] == 'T' || line[0] == 'S'){
            if(line[i] == ':'){
                cerr << "There shouldnt be Colons, ";
                return false;
            }
        }
        if(line[i] == ':'){
            countMultiQuestions++;
        }
        if(line[i] == '|'){
            countSpacers++;
        }
    }
    if(line[0] == 'M'){
        if(countSpacers != 4){
            cerr << "There should only be 4 delimiters, ";
            return false;
        }
    }
    if(line[0] == 'T' || line[0] == 'S'){
        if(countSpacers != 3){
            cerr << "There should only be 3 delimiters, ";
            return false;
        }
    }
    return true;
}
//-------------------------
bool quiz::isLevel(string line){
    if(line[2] == '0'){ // 1-9 is our level range
        cerr << "Level is inncorrect, ";
        return false;
    }
    return true;
}
//-------------------------
bool quiz::checkLine(string line){
    int correct = 0;

    if(isAnswerMulti(line) == true)
        correct++;
    if(isType(line) == true)
        correct++;
    if(spacedCorrect(line) == true)
        correct++;
    if(isLevel(line) == true)
        correct++;
    if(correct == 4)
        return true;
    else
        return false;
}
//-------------------------
bool quiz::isComment(string line){
    if(line[0] == '#')
        return false;
    else
        return true;
}
//-------------------------
bool quiz::loadQuestions(string filename){
    ifstream infile(filename.c_str());
    if(infile.is_open()){
        int lineCount = 1;
        string line;
        question* temp = NULL;
        questionTF questTF;
        questionMC questMC;
        questionSA questSA;
        while(getline(infile,line)){

            stringstream ss(line);
            string token;
            if(isComment(line) == true){
                if(checkLine(line) == true){
                    getline(ss,token,'|');//type
                    char letter = token.at(0); 

                    if(letter == 'S')
                        temp = new questionSA;                      
                    if(letter == 'T')
                        temp = new questionTF;
                    if(letter == 'M')
                        temp = new questionMC;

                    getline(ss,token,'|');
                    int level = atoi(token.c_str());

                    if(letter == 'T' || letter == 'S'){
                        getline(ss,token,'|');
                        temp->setQuestion(token);
                    }
                    if(letter == 'M'){
                        getline(ss,token,'|');
                        string questionToken = token;
                        getline(ss,token,'|');
                        string questionPlusChoices = questionToken + ':' + token;
                        temp->setQuestion(questionPlusChoices);
                    }
                    getline(ss,token,'|');//Answer
                    temp->setAnswer(token);

                    questions.push_back(temp);
                }
                else{
                    cerr << "on Line " << lineCount << " question will be removed." << endl;
                }
            }
            lineCount++;
        }
        infile.close();
        return true;
    }
    else{
        cout << "cannot open the file" << endl;
        return false;
    }
}
//-------------------------
void quiz::dumpQuestions(){
    int size = questions.size();
    for(int i = 0; i<size;i++){
        questions.at(i)->showQuestion();
        cout << "Answer: ";
        questions.at(i)->showAnswer();
        cout <<"---------------------" << endl;
    }
}
//-------------------------
int quiz::deliverQuiz(){
    int correct = 0;
    int size =  questions.size();
    for(int i = 0; i<size;i++){
        questions.at(i)->showQuestion();

        string userGuess;
        cout <<"> ";
        cin >> userGuess;

        if(questions[i]->checkAnswer(userGuess)){
            cout << "Correct! Good Job!" << endl << endl;
            questions.at(i)->markCorrect();
            correct++;
        }
        else{ 
            cout << "Sorry, the answer was ";
            questions.at(i)->showAnswer();
            cout << endl;
        }
    }
    return correct;
}
//-------------------------
int quiz::numQuestions(){
    int size =  questions.size();
    return size;
}
//-------------------------
