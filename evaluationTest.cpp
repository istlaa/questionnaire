#include "evaluationTest.h"

evaluationTest::evaluationTest(questionnaire& q)
    : evaluation(q), d_index(0), d_essais(0), d_bonnesReponses(0)
{}

void evaluationTest::commencer()
{
    d_index = 0;
    d_essais = 0;
    d_bonnesReponses = 0;
}

bool evaluationTest::aEncoreDesQuestions() const
{
    return d_index < static_cast<int>(questionnaireRef().questions().size());
}

question& evaluationTest::questionCourante()
{
    return *(questionnaireRef().questions()[d_index]);
}

void evaluationTest::repondre(const std::string& saisie)
{
    d_essais++;

    question& q = questionCourante();
    if (q.verifierReponse(saisie)) {
        q.changeEtat(REPONDUJUSTE);
        d_bonnesReponses++;
    } else {
        q.changeEtat(REPONDUFAUX);
    }
}

bool evaluationTest::peutAfficherBonneReponse() const
{
    return false;
}

void evaluationTest::questionSuivante()
{
    d_index++;
}

int evaluationTest::nombreQuestions() const
{
    return static_cast<int>(questionnaireRef().questions().size());
}

int evaluationTest::nombreEssais() const
{
    return d_essais;
}

int evaluationTest::nombreBonnesReponses() const
{
    return d_bonnesReponses;
}
