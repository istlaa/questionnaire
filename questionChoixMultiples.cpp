#include"questionChoixMultiples.h"
#include<vector>
questionChoixMultiples::questionChoixMultiples(const std::string &titre,const std::vector<reponse>&reponses):question{titre},d_reponses{reponses}
{}

void questionChoixMultiples::selectionReponse(int i)
{
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


void questionChoixMultiples::afficherQuestion(afficheur& os) const {
    os.affiche("Q \n");
    os.affiche(titre()+"\n");
    os.affiche(d_reponses.size()+"\n");
    for(const auto &r:d_reponses)
    {
        os.affiche( r.nom() +"\n");
    }
}
