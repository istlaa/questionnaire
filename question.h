#ifndef QUESTION_H
#define QUESTION_H
#include<string>
#include<vector> 
#include"reponse.h"
#include <iostream>
using namespace std;

class question{
    public:
        virtual ~question() =default;
        question(const std::string &titre);
        std::string titre() const;
        const enum state etat() const;
        void changeEtat(const enum state &nouvelEtat);
        virtual bool verifierReponse(string saisie) const = 0;
        virtual void ecrireQuestion(ostream& os) const = 0;
        
    protected:
        virtual std::string bonneReponse()  const = 0;
        
    private:
        std::string d_titre;
        enum state d_etat;
};


const enum state {  
    NONREPONDU = 0,
    REPONDUJUSTE = 1,
    REPONDUFAUX = 2
};

class questionTexte:public question{
    public:
        questionTexte(const std::string &titre,const std::string &bonnereponse);
        std::string reponseDonnee() const;
        bool verifierReponse(string saisie) const override;
        void ecrireQuestion(ostream& os) const override;
    protected:
        std::string bonneReponse()  const override;
    private:
        std::string d_bonneReponse;
        std::string d_reponse;
};

class questionChoixMultiples:public question{
    public:
        questionChoixMultiples(const std::string &titre,const std::vector<reponse>&reponses);
        void selectionReponse(int i);
        void enleverReponse(int i);
        bool verifierReponse(string saisie) const override;
        std::vector<reponse> reponses() const; 
        void ecrireQuestion(ostream& os) const override;
    protected:
        std::string bonneReponse()  const override;
    private:
        std::vector<reponse> d_reponses;
};

class questionNumerique : public question{
    public:
    questionNumerique(const string& titre, int reponse, int min, int max);
    bool verifierReponse(string saisie) const override ; 
    void ecrireQuestion(ostream& os) const override;
    protected:
    string bonneReponse() const override;
    private:
    int d_reponse;
    int d_min;
    int d_max;

};
#endif