#include "menu.h"
#include <iostream>
#include "questionnaire.h"

using std::cout;
using std::cin;
using std::string;

menu::menu(): d_questionnaireCharge{false} {}


bool menu::questionnaireEstCharge() const {
    return d_questionnaireCharge;
}

void menu::execute() {
    int choix = 0;

    //Premier choix
    while (!questionnaireEstCharge()) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Charger un questionnaire\n";
        cout << "2. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1:
            chargerQuestionnaire();
            break;
        case 2:
            cout << "\nAu revoir.\n";
            return;
        default:
            cout << "\nChoix invalide.\n";
            break;
        }
    }

    do {
        afficherMenuPrincipal();
        cin >> choix;

        switch (choix) {
        case 1:
            lancerApprentissage();
            break;
        case 2:
            lancerEvaluation();
            break;
        case 3:
            cout << "\nAu revoir !\n";
            break;
        default:
            cout << "\nChoix invalide.\n";
            break;
        }

    } while (choix != 3);
}


void menu::afficherMenuPrincipal() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Mode apprentissage\n";
    cout << "2. Mode evaluation\n";
    cout << "3. Quitter\n";
    cout << "Votre choix : ";
}

string menu::afficherChargerQuestionnaire() const
{
    string nomFichier {""};
    do
    {
        cout << "Nom du fichier : ";
        cin >> nomFichier;
    }while(nomFichier == "");

    return nomFichier;
}

void menu::chargerQuestionnaire()
{
    string fichier = afficherChargerQuestionnaire();
    questionnaire q {"test"};
    q.chargement(fichier);

    d_questionnaire = q;
}


void menu::lancerApprentissage()
{

}
void menu::lancerEvaluation()
{

}
