#ifndef MENU_H
#define MENU_H
#include "questionnaire.h"

using std::unique_ptr;

class questionnaire;

class menu {
public:
    menu();

    // Boucle principale du programme
    void execute();

    // Affichages
    void afficherMenuPrincipal();
    void afficherMenuEvaluation();
    std::string afficherChargerQuestionnaire() const;

    void chargerQuestionnaire();
    void lancerApprentissage();
    void lancerEvaluation();

    // Savoir si un questionnaire est chargé
    bool questionnaireEstCharge() const;


private:
    questionnaire d_questionnaire; // questionnaire
    bool d_questionnaireCharge;

};




#endif // MENU_H
