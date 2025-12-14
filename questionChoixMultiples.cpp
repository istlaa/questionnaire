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

std::string questionChoixMultiples::bonneReponse()  const
{
    int i = 0;
    while(i < d_reponses.size() && d_reponses[i].estJuste())
        i++;
    return d_reponses[i].nom();
}
bool questionChoixMultiples::verifierReponse(string saisie) const
{
    int i = 0;
    while(i < d_reponses.size() && d_reponses[i].estJuste() && d_reponses[i].estSelectionne())
        i++;
    return i == d_reponses.size();
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