#include"questionNumerique.h"
#include<vector>
#include <iostream>
#include <fstream>
questionNumerique::questionNumerique(const string& titre,int reponse,int min,int max) : question(titre),d_reponse{reponse},d_min{min},d_max{max}{}

const string questionNumerique::bonneReponse()   const
{
    return std::to_string(d_reponse);
}
const int questionNumerique::min() const
{
    return d_min;
}
const int questionNumerique::max() const
{
    return d_max;
}




bool questionNumerique::verifierReponse(string saisie) const  {
    return (d_min<stoi(saisie)) && (stoi(saisie)< d_max) ;

}


void questionNumerique::ecrireDansFichier(std::ofstream& fichier){
    fichier << "NUMERIQUE\n";
    fichier << titre() << "\n";
    fichier << d_reponse << "\n";
    fichier << d_min << "\n";
    fichier << d_max << "\n";
}
