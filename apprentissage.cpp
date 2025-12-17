#include "apprentissage.h"
#include "question.h"
#include <iostream>

using namespace std;

apprentissage::apprentissage(const questionnaire& q)
    : d_questionnaire{q}
{}

void apprentissage::commencer(afficheur& a)
{

    for (const auto& q : d_questionnaire.questions())
    {
        q->afficherQuestion(a);
        a.affiche("\n");

        // Pause
        a.affiche("\nEntrez n'importe quel touche pour continuer : ");
        a.demanderString();

        a.affiche("\n-----------------------------\n");
    }

    a.affiche("\nFin du mode apprentissage.\n");
}
