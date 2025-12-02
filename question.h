#ifndef QUESTION_H
#define QUESTION_H
#include<string>
#include<vector> 
#include"reponse.h"

class question{
    public:
        virtual ~question() =default;
        question(const std::string &titre);
        std::string titre() const;
        const enum state etat() const;
        void changeEtat(const enum state &nouvelEtat);
        
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
        std::vector<reponse> reponses() const; 
    protected:
        std::string bonneReponse()  const override;
    private:
        std::vector<reponse> d_reponses;
};
#endif