#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <string>
#include <iostream>

using std::string;

class afficheur
{
    //Classe abstraite pure qui permettra plus tard de faire différentes interfaces
    public:
    virtual void affiche(const string& txt) = 0;
    virtual int demanderInt() = 0;
    virtual string demanderString() = 0;
    virtual ~afficheur() = default;
};



#endif // AFFICHEUR_H
