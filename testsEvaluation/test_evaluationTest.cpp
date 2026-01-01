#include "doctest.h"

#include "evaluationTest.h"
#include "questionnaire.h"
#include "questionTexte.h"

questionnaire creerQuestionnaireTest()
{
    questionnaire q("Test evaluation classique");

    q.ajouteQuestion(std::make_unique<questionTexte>("2 + 2 = ?", "4"));
    q.ajouteQuestion(std::make_unique<questionTexte>("3 + 3 = ?", "6"));

    return q;
}

// -----------------------------------------------------------------------------
// TESTS UNITAIRES DE evaluationTest
// -----------------------------------------------------------------------------

TEST_CASE("evaluationTest - constructeur")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    CHECK(eval.nombreQuestions() == 2);
    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
}

TEST_CASE("evaluationTest - commencer reinitialise l'etat")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();

    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK(eval.aEncoreDesQuestions());
}

TEST_CASE("evaluationTest - questionCourante retourne une question valide")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();

    question& qc = eval.questionCourante();
    CHECK(qc.titre() != "");
}

TEST_CASE("evaluationTest - bonne reponse")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();
    question& qc = eval.questionCourante();

    eval.repondre(qc.bonneReponse());

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.nombreBonnesReponses() == 1);
}

TEST_CASE("evaluationTest - mauvaise reponse")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();
    eval.repondre("mauvaise reponse");

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.nombreBonnesReponses() == 0);
}

TEST_CASE("evaluationTest - avance automatiquement a la question suivante")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();

    // Question 1
    question& q1 = eval.questionCourante();
    eval.repondre(q1.bonneReponse());

    CHECK(eval.aEncoreDesQuestions());

    // Question 2
    question& q2 = eval.questionCourante();
    eval.repondre(q2.bonneReponse());

    CHECK_FALSE(eval.aEncoreDesQuestions());
}

TEST_CASE("evaluationTest - fin de l'evaluation")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    eval.commencer();

    while (eval.aEncoreDesQuestions())
    {
        question& qc = eval.questionCourante();
        eval.repondre(qc.bonneReponse());
    }

    CHECK(eval.nombreEssais() == 2);
    CHECK(eval.nombreBonnesReponses() == 2);
    CHECK_FALSE(eval.aEncoreDesQuestions());
}

TEST_CASE("evaluationTest - peutAfficherBonneReponse retourne false")
{
    questionnaire q = creerQuestionnaireTest();
    evaluationTest eval(q);

    CHECK_FALSE(eval.peutAfficherBonneReponse());
}
