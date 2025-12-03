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
questionNumerique::questionNumerique(const string& titre,int reponse,int min,int max) : question(titre),d_reponse{reponse},d_min{min},d_max{max}{}

std::string questionNumerique::bonneReponse()   const 
{
    return to_string(d_reponse);
}
bool questionTexte::verifierReponse(string saisie) const {
    return saisie == d_bonneReponse;
}

bool questionChoixMultiples::verifierReponse(string saisie) const 
{
    int i = 0;
    while(i < d_reponses.size() && d_reponses[i].estJuste() && d_reponses[i].estSelectionne())
        i++;
    return i == d_reponses.size();
}

bool questionNumerique::verifierReponse(string saisie) const  {
    return (d_min<stoi(saisie)) && (stoi(saisie)< d_max) ;

}
void questionTexte::ecrireQuestion(ostream& os) const {
    os << "T" << endl;
    os << titre() << endl;
    os << d_bonneReponse<< endl;
    }
void questionChoixMultiples::ecrireQuestion(ostream& os) const {
    os << "Q" << endl;
    os << titre() << endl;
    os << d_reponses.size() << endl;
    for(const auto &r:d_reponses)
    {
        os << r.nom() << endl;
    }
}
void questionNumerique::ecrireQuestion(ostream& os) const {
    os<< "N" << endl;
    os << titre() << endl;
    os<< d_reponse << endl;
    os<< d_min << endl;
    os<< d_max << endl;
    }




