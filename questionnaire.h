#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"
#include<memory>
#include <fstream>
using namespace std;

class questionnaire {
    public:
        questionnaire(const string &titre);
        vector<question*> questionsFausses() const;
        int nbQuestionsRepondus()   const;
        string titre()  const;
        bool estFini() const;
        int score() const;
        void changeScore(int nscore);
        void sauvegarder(const string& nomFichier) const;
        void chargement(const string& nomFichier);
    private:
        void ajouteQuestion(unique_ptr<question> q);
        vector<unique_ptr<question>>d_questions;
        int d_score;
        string d_titre;
};








#endif
