#include"question.h"
#include<vector>

question::question(const std::string &titre):d_etat{NONREPONDU},d_titre{titre}
{}

std::string question::titre()   const
{
    return d_titre;
}

questionTexte::questionTexte(const std::string &titre,const std::string &bonnereponse):question{titre},d_bonneReponse{bonnereponse}
{}

std::string questionTexte::bonneReponse()   const 
{
    return d_bonneReponse;
}

void question::changeEtat(const enum state &nouvelEtat)    
{
    if(d_etat != nouvelEtat)
        d_etat = nouvelEtat;
}

const enum state question::etat()  const 
{
    return d_etat;
}

std::string questionTexte::reponseDonnee()  const
{
    return d_reponse;
}

questionChoixMultiples::questionChoixMultiples(const std::string &titre,const std::vector<reponse>&reponses):question{titre},d_reponses{reponses}
{}

void questionChoixMultiples::selectionReponse(int i)
{
    d_reponses[i].changeSelection(true);
}

std::vector<reponse> questionChoixMultiples::reponses() const
{
    return d_reponses;
} 

void questionChoixMultiples::enleverReponse(int i)
{
    d_reponses[i].changeSelection(false);
}

std::string questionChoixMultiples::bonneReponse()  const
{
    int i = 0;
    while(i < d_reponses.size() && d_reponses[i].estJuste())
        i++;
    return d_reponses[i].nom();
}




