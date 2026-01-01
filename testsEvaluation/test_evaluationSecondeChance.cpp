#include "doctest.h"

#include "evaluationSecondeChance.h"
#include "questionnaire.h"
#include "questionTexte.h"

questionnaire creerQuestionnaireSecondeChance()
{
    questionnaire q("Test seconde chance");

    q.ajouteQuestion(std::make_unique<questionTexte>("2 + 2 = ?", "4"));
    q.ajouteQuestion(std::make_unique<questionTexte>("3 + 3 = ?", "6"));

    return q;
}

// -----------------------------------------------------------------------------
// TESTS UNITAIRES DE evaluationSecondeChance
// -----------------------------------------------------------------------------

TEST_CASE("evaluationSecondeChance - constructeur")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    CHECK(eval.nombreQuestions() == 2);
    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK_FALSE(eval.estSecondeChance());
}

TEST_CASE("evaluationSecondeChance - commencer reinitialise l'etat")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();

    CHECK(eval.nombreEssais() == 0);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK_FALSE(eval.estSecondeChance());
    CHECK_FALSE(eval.peutAfficherBonneReponse());
}

TEST_CASE("evaluationSecondeChance - bonne reponse du premier coup")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();
    question& qc = eval.questionCourante();

    eval.repondre(qc.bonneReponse());

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.nombreBonnesReponses() == 1);
    CHECK_FALSE(eval.estSecondeChance());
    CHECK_FALSE(eval.peutAfficherBonneReponse());
}

TEST_CASE("evaluationSecondeChance - mauvaise reponse puis bonne reponse (seconde chance)")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();

    // 1er essai faux → seconde chance activée
    eval.repondre("mauvaise");

    CHECK(eval.nombreEssais() == 1);
    CHECK(eval.estSecondeChance());
    CHECK_FALSE(eval.peutAfficherBonneReponse());

    // 2e essai bon → valide la question
    question& qc = eval.questionCourante();
    eval.repondre(qc.bonneReponse());

    CHECK(eval.nombreEssais() == 2);
    CHECK(eval.nombreBonnesReponses() == 1);
    CHECK_FALSE(eval.estSecondeChance());
}

TEST_CASE("evaluationSecondeChance - deux mauvaises reponses")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();

    // 1ère mauvaise réponse
    eval.repondre("faux");

    CHECK(eval.estSecondeChance());
    CHECK_FALSE(eval.peutAfficherBonneReponse());

    // 2e mauvaise réponse
    eval.repondre("encore faux");

    CHECK(eval.nombreEssais() == 2);
    CHECK(eval.nombreBonnesReponses() == 0);
    CHECK(eval.peutAfficherBonneReponse());
}

TEST_CASE("evaluationSecondeChance - questionSuivante avance correctement")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();

    question& qc = eval.questionCourante();
    eval.repondre(qc.bonneReponse());

    eval.questionSuivante();

    CHECK_FALSE(eval.estSecondeChance());
    CHECK_FALSE(eval.peutAfficherBonneReponse());
    CHECK(eval.aEncoreDesQuestions());
}

TEST_CASE("evaluationSecondeChance - fin de l'evaluation")
{
    questionnaire q = creerQuestionnaireSecondeChance();
    evaluationSecondeChance eval(q);

    eval.commencer();

    while (eval.aEncoreDesQuestions())
    {
        question& qc = eval.questionCourante();
        eval.repondre(qc.bonneReponse());
        eval.questionSuivante();
    }

    CHECK(eval.nombreBonnesReponses() == 2);
    CHECK(eval.aEncoreDesQuestions() == false);
}
