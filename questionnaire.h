#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"
#include<memory>
#include <fstream>
using namespace std;

class questionnaire {
    public:
        virtual ~questionnaire() =default;
        questionnaire(const vector<unique_ptr<question>>&questions,const string &titre);
        vector<unique_ptr<question>> questionsFausses() const;
        int nbQuestionsRepondus()   const;
        string titre()  const;
        bool estFini() const;
        int score() const;
        void changeScore(int nscore); 
        void sauvegarder(const string& nomFichier) const;
        virtual void chargement(const string& nomFichierTexte,const string &nomFichierNumerique,const &nomFichierQCM) =0;
    private:
        void ajouteQuestion(const question &q);

};

const int nombreQuestionsTest = 12;
const int nombreQuestionsAdaptative = 6;

class questionnaireSecondeChance:public questionnaire{
    public:
        questionnaireSecondeChance();
};

class questionnaireTest:public questionnaire{
    public:
        questionnaireTest(const vector<unique_ptr<question>> &questions,const string &titre);
        void chargement(const string &nomFichierTexte,const string &nomFichierNumerique,const string &nomFichierQCM)   override;
};



#endif