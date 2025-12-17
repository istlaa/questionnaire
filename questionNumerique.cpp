#include"questionNumerique.h"
#include<vector>
#include <iostream>  
#include <fstream>  
questionNumerique::questionNumerique(const string& titre,int reponse,int min,int max) : question(titre),d_reponse{reponse},d_min{min},d_max{max}{}

const std::string questionNumerique::bonneReponse()   const
{
    return to_string(d_reponse);
}




bool questionNumerique::verifierReponse(string saisie) const  {
    return (d_min<stoi(saisie)) && (stoi(saisie)< d_max) ;

}


void questionNumerique::afficherQuestion(afficheur& os) const {
    os.affiche("N\n");
    os.affiche(titre()+"\n");
    os.affiche("d_reponse\n");
    os.affiche(d_min+"\n");
    os.affiche(d_max+"\n");
    }
void questionNumerique::ecrireDansFichier(std::ofstream& fichier){ 
    fichier << "N\n";
    fichier << titre() << "\n";
    fichier << d_reponse << "\n";
    fichier << d_min << "\n";
    fichier << d_max << "\n";
}
