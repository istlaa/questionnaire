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
    void afficherEnTete();
    void choixInvalide();
    void choixQuitter();

    void chargerQuestionnaire();
    void lancerApprentissage();
    void lancerEvaluation();

    string recupererNomFichier()const;
    bool questionnaireEstCharge() const;


private:
    afficheur& d_afficheur;
    bool d_questionnaireCharge;
    static constexpr int PREMIER {1};
    static constexpr int DEUXIEME {2};
    static constexpr int TROISIEME {3};


};




#endif // MENU_H
