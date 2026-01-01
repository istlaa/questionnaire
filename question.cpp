#include"question.h"
#include<vector>

question::question(const std::string &titre):d_titre{titre},d_etat{NONREPONDU}
{}

std::string question::titre()   const
{
    return d_titre;
}

void question::changeEtat(const enum state &nouvelEtat)
{
    if(d_etat != nouvelEtat)
        d_etat = nouvelEtat;
}

enum state question::etat()  const
{
    return d_etat;
}

void question::reinitialiser()
{
    d_etat = NONREPONDU;
}





