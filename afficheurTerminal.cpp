#include "afficheurTerminal.h"

void afficheurTerminal::affiche(const string& txt) {
        cout << txt;
    }
int afficheurTerminal::demanderInt() {
        int entier;
        cin>>entier;
        if(cin.fail())
        {
            cin.clear(); //retirer l'erreur
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->affiche("\n(Vous devez choisir un entier !)");
            cin >> entier;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return entier;

    }


string afficheurTerminal::demanderString() {
    string chCaractere;
    getline(cin, chCaractere);

    return chCaractere;
}
