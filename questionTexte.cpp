#include"questionTexte.h"
#include<vector>

questionTexte::questionTexte(const std::string &titre,const std::string &bonnereponse):question{titre},d_bonneReponse{bonnereponse}
{}

std::string questionTexte::bonneReponse()   const
{
    return d_bonneReponse;
}

std::string questionTexte::reponseDonnee()  const
{
    return d_reponse;
}

bool questionTexte::verifierReponse(string saisie) const {
    return saisie == d_bonneReponse;
}
void questionTexte::ecrireQuestion(ostream& os) const {
    os << "T" << endl;
    os << titre() << endl;
    os << d_bonneReponse<< endl;
    }