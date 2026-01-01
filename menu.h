#ifndef MENU_H
#define MENU_H
#include "questionnaire.h"
#include "afficheur.h"
#include "afficheurTerminal.h"
#include "apprentissage.h"


using std::string;

class afficheur;

class menu {
public:
    menu(afficheur& affiche);

    void executionProgramme();


private:
    string recupererNomFichier()const;
    bool questionnaireEstCharge() const;
    afficheur& d_afficheur;
    bool d_questionnaireCharge;
    questionnaire d_questionnaire;

     // Affichages

    int lancerChoixMenuDepart() const;
    void chargerQuestionnaire();
    void lancerApprentissage();
    void lancerEvaluation();
    int lancerChoixMenuPrincipal() const;
    int lancerChoixMenuEvaluation() const;
    void afficherEnTete(const string& entete) const;
    void choixInvalide();
    void choixQuitter();


};




#endif // MENU_H
