#include "menu.h"
#include <iostream>
#include "questionnaire.h"

using std::cout;
using std::cin;
using std::to_string;

menu::menu(afficheur& affiche): d_afficheur{affiche}, d_questionnaireCharge{false}, d_questionnaire{""} {}


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
        case PREMIER:
            chargerQuestionnaire();
            break;
        case DEUXIEME:
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
        case PREMIER:
            lancerApprentissage();
            break;
        case DEUXIEME:
            lancerEvaluation();
            break;
        case TROISIEME:
            choixQuitter();
            break;
        default:
            choixInvalide();
            break;
        }

    } while (choix != TROISIEME);
}
void menu::afficherEnTete(const string& entete)
{
    d_afficheur.affiche("\n===== "+entete+" =====\n");
}

int menu::lancerMenuDepart()
{
        afficherEnTete("MENU PRINCIPAL");
        d_afficheur.affiche(to_string(PREMIER)+". Charger un questionnaire\n");
        d_afficheur.affiche(to_string(DEUXIEME)+". Quitter\n");
        d_afficheur.affiche("Votre choix : ");
        int choix = d_afficheur.demanderInt();
        return choix;
}

int menu::lancerMenuPrincipal() {
    afficherEnTete("MENU PRINCIPAL");
    d_afficheur.affiche(to_string(PREMIER)+". Mode apprentissage\n");
    d_afficheur.affiche(to_string(DEUXIEME)+". Mode evaluation\n");
    d_afficheur.affiche(to_string(TROISIEME)+". Quitter\n");
    d_afficheur.affiche("Votre choix : ");
    int choix = d_afficheur.demanderInt();
        return choix;
}

const string menu::recupererNomFichier() const
{
    string nomFichier;
    d_afficheur.affiche("Nom du fichier : ");
    nomFichier = d_afficheur.demanderString();

    return nomFichier;
}

void menu::chargerQuestionnaire()
{
    string fichier = recupererNomFichier();
    d_questionnaire = questionnaire{"questionnaire"};

    d_questionnaireCharge = d_questionnaire.chargement(fichier);


    if(!d_questionnaireCharge)
        d_afficheur.affiche("Erreur de chargement veuillez reessayez.\n");



}


void menu::lancerApprentissage()
{
    afficherEnTete("MODE APPRENTISSAGE");
    apprentissage a{d_questionnaire};
    a.commencer(d_afficheur);

}
void menu::lancerEvaluation()
{

}
