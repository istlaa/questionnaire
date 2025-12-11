#ifndef MENU_H
#define MENU_H
#include "questionnaire.h"
#include "afficheur.h"
#include "afficheurTerminal.h"


using std::string;

class afficheur;

class menu {
public:
    menu(afficheur& affiche);

    void executionProgramme();

    // Affichages
    int lancerMenuDepart();
    int lancerMenuPrincipal();
    int afficherMenuEvaluation();
    string recupererNomFichier() const;
    void choixInvalide();
    void choixQuitter();

    void chargerQuestionnaire();
    void lancerApprentissage();
    void lancerEvaluation();

    // Savoir si un questionnaire est chargé
    bool questionnaireEstCharge() const;


private:
    afficheur& d_afficheur;
    bool d_questionnaireCharge;

};




#endif // MENU_H
