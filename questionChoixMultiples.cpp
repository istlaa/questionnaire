#include"questionChoixMultiples.h"
#include<vector>
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

std::string questionChoixMultiples::bonneReponse() const
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


void questionChoixMultiples::ecrireQuestion(ostream& os) const {
    os << "Q" << endl;
    os << titre() << endl;
    os << d_reponses.size() << endl;
    for(const auto &r:d_reponses)
    {
        os << r.nom() << endl;
    }
}
