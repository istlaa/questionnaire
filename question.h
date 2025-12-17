#ifndef QUESTION_H
#define QUESTION_H

#include "reponse.h"
#include "afficheur.h"

#include <string>
#include <vector>
#include <iostream>

enum state {
    NONREPONDU = 0,
    REPONDUJUSTE = 1,
    REPONDUFAUX = 2
};
class question{
    public:
        virtual ~question() =default;
        question(const string &titre);
        string titre() const;
        enum state etat() const;
        void changeEtat(const enum state &nouvelEtat);
        virtual bool verifierReponse(string saisie) const = 0;
        virtual void ecrireDansFichier(std::ofstream& fichier)=0;


        virtual const string bonneReponse()  const = 0;
    private:
        string d_titre;
        enum state d_etat;
};
#endif
