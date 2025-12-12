#include "afficheurTerminal.h"

void afficheurTerminal::affiche(const string& txt) {
        cout << txt;
    }
int afficheurTerminal::demanderInt() {

        int entier;
        cin >> entier;
        return entier;

    }


string afficheurTerminal::demanderString() {
    string chCaractere;
    cin>>chCaractere;
    return chCaractere;
}
