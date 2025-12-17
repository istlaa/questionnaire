#include"questionTexte.h"
#include<vector>

questionTexte::questionTexte(const std::string &titre,const std::string &bonnereponse):question{titre},d_bonneReponse{bonnereponse}
{}

const std::string questionTexte::bonneReponse()   const
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
void questionTexte::ecrireQuestion(afficheur& os) const {
    os.affiche("T\n");
    os.affiche(titre()+"\n");
    os.affiche(d_bonneReponse+"\n");
    }
