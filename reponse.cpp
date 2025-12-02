#include"reponse.h"

reponse::reponse(const std::string &nom,bool estJuste):d_nom{nom},d_selectionne{false},d_juste{estJuste}
{}

bool reponse::estSelectionne()  const
{
    return d_selectionne;
}

std::string reponse::nom()  const
{   return d_nom;   }

void reponse::changeSelection(bool e)
{
    if(d_selectionne != e)
        d_selectionne = e;
}

const bool reponse::estJuste()  const
{
    return d_juste;
}

