#ifndef MENU_H
#define MENU_H


class questionnaire;

class menu {
public:
    menu();

    // Boucle principale du programme
    void execute();

    // Affichages
    void afficherMenuPrincipal();
    void afficherMenuEvaluation();

    // Actions
    void chargerQuestionnaire();
    void lancerApprentissage();
    void lancerEvaluation();

    // Savoir si un questionnaire est chargé
    bool questionnaireCharge() const;


private:
    questionnaire* d_questionnaire; // pointeur vers le questionnaire chargé

};




#endif // MENU_H
