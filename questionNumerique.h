#ifndef QUESTIONNUMERIQUE_H
#define QUESTIONNUMERIQUE_H
#include<string>
#include<vector>
#include"reponse.h"
#include"question.h"
#include "afficheur.h"
#include <iostream>

class questionNumerique : public question{
    public:
        questionNumerique(const string& titre, int reponse, int min, int max);
        bool verifierReponse(string saisie) const override ;
        void ecrireQuestion(afficheur& os) const override;
    protected:
        string bonneReponse() const override;
    private:
        int d_reponse;
        int d_min;
        int d_max;
};
#endif
