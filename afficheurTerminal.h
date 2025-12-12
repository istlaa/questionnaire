#ifndef AFFICHEURTERMINAL_H
#define AFFICHEURTERMINAL_H
#include "afficheur.h"
using std::string;
using std::cin;
using std::cout;



class afficheurTerminal : public afficheur
{
public:
    void affiche(const string& txt) override;

    int demanderInt() override;

    string demanderString() override;
};

#endif // AFFICHEURTERMINAL_H
