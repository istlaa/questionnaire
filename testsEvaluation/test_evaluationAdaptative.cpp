#include "doctest.h"
#include <cstdlib>
#include "evaluationAdaptative.h"
#include "questionnaire.h"
#include "questionTexte.h"


questionnaire creerQuestionnaireSimple()
{
    questionnaire q("Test evaluation adaptative");

    q.ajouteQuestion(std::make_unique<questionTexte>("2 + 2 = ?", "4"));
    q.ajouteQuestion(std::make_unique<questionTexte>("3 + 3 = ?", "6"));

    return q;
}

// -----------------------------------------------------------------------------
// TESTS UNITAIRES DE evaluationAdaptative
// -----------------------------------------------------------------------------

TEST_CASE("evaluationAdaptative - constructeur")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    CHECK(eval.nombreQuestions() == 2);
    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
}

TEST_CASE("evaluationAdaptative - commencer initialise l'etat")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    eval.commencer();

    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK(eval.aEncoreDesQuestions() == true);
}

TEST_CASE("evaluationAdaptative - questionCourante retourne une question valide")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    eval.commencer();

    question& qc = eval.questionCourante();
    CHECK(qc.titre() != "");
}

TEST_CASE("evaluationAdaptative - bonne reponse incremente les compteurs")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    eval.commencer();
    question& qc = eval.questionCourante();

    eval.repondre(qc.bonneReponse());

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.nombreBonnesReponses() == 1);
}

TEST_CASE("evaluationAdaptative - mauvaise reponse n'incremente pas les bonnes reponses")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    eval.commencer();
    eval.repondre("mauvaise reponse");

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK(eval.aEncoreDesQuestions() == true);
}

TEST_CASE("evaluationAdaptative - fin de l'evaluation")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    eval.commencer();

    while (eval.aEncoreDesQuestions())
    {
        question& qc = eval.questionCourante();
        eval.repondre(qc.bonneReponse());
    }

    CHECK(eval.nombreBonnesReponses() == 2);
    CHECK(eval.aEncoreDesQuestions() == false);
}

TEST_CASE("evaluationAdaptative - peutAfficherBonneReponse retourne false")
{
    questionnaire q = creerQuestionnaireSimple();
    evaluationAdaptative eval(q);

    CHECK_FALSE(eval.peutAfficherBonneReponse());
}
