#include"questionTexte.h"
#include<vector>
#include <iostream>
#include <fstream>
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

void questionTexte::ecrireDansFichier(std::ofstream& fichier){
    fichier << "TEXTE\n";
    fichier << titre() << "\n";
    fichier << d_bonneReponse << "\n";
}
