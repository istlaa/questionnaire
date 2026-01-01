#include <memory>
#include "menu.h"
#include "questionnaire.h"
#include "evaluation.h"
#include "evaluationTest.h"
#include "evaluationSecondeChance.h"
#include "evaluationAdaptative.h"


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


int menu::afficherMenuEvaluation()
{
    afficherEnTete("MENU EVALUATION");
    d_afficheur.affiche("1. Evaluation test\n");
    d_afficheur.affiche("2. Evaluation seconde chance\n");
    d_afficheur.affiche("3. Evaluation adaptative\n");
    d_afficheur.affiche("Votre choix : ");
    return d_afficheur.demanderInt();
}



void menu::lancerApprentissage()
{
    afficherEnTete("MODE APPRENTISSAGE");
    apprentissage a{d_questionnaire};
    a.commencer(d_afficheur);

}

void menu::lancerEvaluation()
{

    int choix = afficherMenuEvaluation();
    std::unique_ptr<evaluation> eval;

    switch (choix)
    {
        case 1:
            eval = std::make_unique<evaluationTest>(d_questionnaire);
            break;
        case 2:
            eval = std::make_unique<evaluationSecondeChance>(d_questionnaire);
            break;
        case 3:
            eval = std::make_unique<evaluationAdaptative>(d_questionnaire);
            break;
        default:
            choixInvalide();
            return;
    }

    eval->commencer();

    while (eval->aEncoreDesQuestions())
    {
        question& q = eval->questionCourante();

        if (eval->estSecondeChance())
        {
            d_afficheur.affiche(
                "Tu as le droit a une DEUXIEME CHANCE!\n"
            );
        }

        d_afficheur.affiche("\nQuestion :\n");
        d_afficheur.affiche(q.titre() + "\n");

        if (auto* qcm = dynamic_cast<questionChoixMultiples*>(&q))
        {
            int i = 1;
            for (const auto& r : qcm->reponses())
            {
                d_afficheur.affiche(
                    std::to_string(i) + ". " + r.nom() + "\n"
                );
                i++;
            }

            d_afficheur.affiche("Votre choix (numero) : ");
            int choixUtilisateur = d_afficheur.demanderInt();
            qcm->selectionReponse(choixUtilisateur - 1);

            eval->repondre("");
        }
        else
        {
            d_afficheur.affiche("Votre reponse : ");
            std::string saisie = d_afficheur.demanderString();
            eval->repondre(saisie);
        }

        if (q.etat() == REPONDUJUSTE)
        {
            d_afficheur.affiche("Bonne reponse\n");
        }
        else
        {
            d_afficheur.affiche("Mauvaise reponse\n");
            if (eval->peutAfficherBonneReponse())
            {
                d_afficheur.affiche(
                    "Bonne reponse : " + q.bonneReponse() + "\n"
                );
            }
        }

        if (q.etat() != NONREPONDU)
        {
            eval->questionSuivante();
        }
    }

    afficherEnTete("RESULTATS");

    d_afficheur.affiche(
        "Nombre de questions : " +
        std::to_string(eval->nombreQuestions()) + "\n"
    );
    d_afficheur.affiche(
        "Nombre d'essais     : " +
        std::to_string(eval->nombreEssais()) + "\n"
    );
    d_afficheur.affiche(
        "Bonnes reponses     : " +
        std::to_string(eval->nombreBonnesReponses()) + "\n"
    );
    d_afficheur.affiche(
        "Score               : " +
        std::to_string(eval->nombreBonnesReponses()) +
        " / " +
        std::to_string(eval->nombreQuestions()) + "\n"
    );

    d_afficheur.affiche("\nMerci d'avoir participe.\n");
}





