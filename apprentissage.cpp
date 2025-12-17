#include "apprentissage.h"
#include "question.h"
#include <iostream>

using namespace std;

apprentissage::apprentissage(const questionnaire& q)
    : d_questionnaire{q}
{}

void apprentissage::commencer(afficheur& a)
{
/*
    for (const auto& q : d_questionnaire.questions())
    {

        q->ecrireQuestion(cout);

        // Affichage immédiat de la réponse (apprentissage)
        a.affiche("\nRéponse : ");
        a.affiche(q->afficherBonneReponse());
        a.affiche("\n");

        // Pause pédagogique
        a.affiche("\nAppuyez sur Entrée pour continuer...");
        a.demanderString();

        a.affiche("\n-----------------------------\n");
    }

    a.affiche("\nFin du mode apprentissage.\n");*/
}
