#include <iostream>
#include <fstream>
#include <vector>
#include "questionChoixMultiples.h"
questionChoixMultiples::questionChoixMultiples(const std::string &titre,const std::vector<reponse>&reponses):question{titre},d_reponses{reponses}
{}

void questionChoixMultiples::selectionReponse(int i)
{
    for (auto& r : d_reponses) r.changeSelection(false);
    d_reponses[i].changeSelection(true);
}


const std::vector<reponse> questionChoixMultiples::reponses() const
{
    return d_reponses;
}

void questionChoixMultiples::enleverReponse(int i)
{
    d_reponses[i].changeSelection(false);
}
const std::string questionChoixMultiples::bonneReponse() const
{
    for(const auto& r : d_reponses)
    {
        if(r.estJuste())
            return r.nom();
    }
    return "";
}


bool questionChoixMultiples::verifierReponse(string /* saisie */) const
{
    for(const auto& r : d_reponses)
    {
        if(r.estJuste() != r.estSelectionne())
            return false;
    }
    return true;
}



void questionChoixMultiples::ecrireDansFichier(std::ofstream& fichier){
    fichier << "QCM\n";
    fichier << titre() << "\n";
    fichier << d_reponses.size() << "\n";
    for(const auto &r:d_reponses)
    {
        fichier << r.nom() << "\n";
        fichier << r.estJuste() << "\n";
    }
}
