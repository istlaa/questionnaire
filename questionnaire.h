#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"
#include"questionNumerique.h"
#include"questionTexte.h"
#include"questionChoixMultiples.h"
#include<memory>
#include <fstream>
using namespace std;

class questionnaire {
    public:
        questionnaire(const string &titre);
        string titre()  const;
        /*int score() const;
        void changeScore(int nscore);*/
        bool sauvegarder(const string& nomFichier) const;
        bool chargement(const string& nomFichier);
        const vector<unique_ptr<question>>& questions() const;
        void ajouteQuestion(unique_ptr<question> q);
    private:
        
        vector<unique_ptr<question>>d_questions;
        string d_titre;
};








#endif
