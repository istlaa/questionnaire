#ifndef QUESTION_H
#define QUESTION_H
#include<string>
#include<vector>
#include"reponse.h"
#include"afficheur.h"
#include <iostream>

using namespace std;
enum state {
    NONREPONDU = 0,
    REPONDUJUSTE = 1,
    REPONDUFAUX = 2
};
class question{
    public:
        virtual ~question() =default;
        question(const std::string &titre);
        std::string titre() const;
        enum state etat() const;
        void changeEtat(const enum state &nouvelEtat);
        virtual bool verifierReponse(string saisie) const = 0;
        virtual void afficherQuestion(afficheur& os) const = 0;

        virtual const std::string bonneReponse()  const = 0;
    private:
        std::string d_titre;
        enum state d_etat;
};
#endif
