#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <string>

using std::string;

class afficheur
{
    public:
    virtual void affiche(const string& txt) = 0;
    virtual int demanderInt() = 0;
    virtual string demanderString() = 0;
    virtual ~afficheur() = default;
};



#endif // AFFICHEUR_H
