#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"
#include<memory>
#include <fstream>
using namespace std;

class questionnaire {
    public:
        questionnaire(const vector<unique_ptr<question>>&questions,const string &titre);
        vector<unique_ptr<question>> questionsFausses() const;
        int nbQuestionsRepondus()   const;
        string titre()  const;
        bool estFini() const;
        int score() const;
        void changeScore(int nscore); 
        void sauvegarder(const string& nomFichier) const;
    private:
        string d_titre;
        int d_score;
        vector<unique_ptr<question>> d_questions;

};


class questionnaireSecondeChance:public questionnaire{
    public:
        questionnaireSecondeChance();
};

#endif