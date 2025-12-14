#include"questionNumerique.h"
#include<vector>
questionNumerique::questionNumerique(const string& titre,int reponse,int min,int max) : question(titre),d_reponse{reponse},d_min{min},d_max{max}{}

std::string questionNumerique::bonneReponse()   const
{
    return to_string(d_reponse);
}




bool questionNumerique::verifierReponse(string saisie) const  {
    return (d_min<stoi(saisie)) && (stoi(saisie)< d_max) ;

}


void questionNumerique::ecrireQuestion(ostream& os) const {
    os<< "N" << endl;
    os << titre() << endl;
    os<< d_reponse << endl;
    os<< d_min << endl;
    os<< d_max << endl;
    }