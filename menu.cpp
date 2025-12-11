#include "menu.h"
#include <iostream>
#include "questionnaire.h"

using std::cout;
using std::cin;

menu::menu(afficheur& affiche): d_afficheur{affiche}, d_questionnaireCharge{false} {}


bool menu::questionnaireEstCharge() const {
    return d_questionnaireCharge;
}

void menu::choixInvalide()
{
   d_afficheur.affiche("\nChoix invalide.\n");
}
void menu::choixQuitter()
{
    d_afficheur.affiche("\nAu revoir.\n");
}

void menu::executionProgramme() {

int choix;
    //Premier choix
    do {

        choix = lancerMenuDepart();

        switch (choix) {
        case 1:
            chargerQuestionnaire();
            break;
        case 2:
            choixQuitter();
            return;
        default:
            choixInvalide();
            break;
        }
    }while (!questionnaireEstCharge());

    do {

        choix = lancerMenuPrincipal();

        switch (choix) {
        case 1:
            lancerApprentissage();
            break;
        case 2:
            lancerEvaluation();
            break;
        case 3:
            choixQuitter();
            break;
        default:
            choixInvalide();
            break;
        }

    } while (choix != 3);
}

int menu::lancerMenuDepart()
{
        d_afficheur.affiche("\n===== MENU PRINCIPAL =====\n");
        d_afficheur.affiche("1. Charger un questionnaire\n");
        d_afficheur.affiche("2. Quitter\n");
        d_afficheur.affiche("Votre choix : ");
        int choix = d_afficheur.demanderInt();
        return choix;
}

int menu::lancerMenuPrincipal() {
    d_afficheur.affiche("\n===== MENU PRINCIPAL =====\n");
    d_afficheur.affiche("1. Mode apprentissage\n");
    d_afficheur.affiche("2. Mode evaluation\n");
    d_afficheur.affiche("3. Quitter\n");
    d_afficheur.affiche("Votre choix : ");
    int choix = d_afficheur.demanderInt();
        return choix;
}

string menu::recupererNomFichier() const
{
    string nomFichier;
    d_afficheur.affiche("Nom du fichier : ");
    nomFichier = d_afficheur.demanderString();
    cout << " -" <<nomFichier<<"-";


    return nomFichier;
}

void menu::chargerQuestionnaire()
{
    string fichier = recupererNomFichier();
    questionnaire q {"test"};
    q.chargement(fichier);

    d_questionnaireCharge = true;
}


void menu::lancerApprentissage()
{

}
void menu::lancerEvaluation()
{

}
