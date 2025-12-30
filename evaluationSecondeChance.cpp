#include "evaluationSecondeChance.h"

evaluationSecondeChance::evaluationSecondeChance(questionnaire& q)
    : evaluation(q),
      d_index(0),
      d_essais(0),
      d_bonnesReponses(0),
      d_dejaReposee(false),
      d_afficherBonneReponse(false)
{}

void evaluationSecondeChance::commencer()
{
    d_index = 0;
    d_essais = 0;
    d_bonnesReponses = 0;
    d_dejaReposee = false;
    d_afficherBonneReponse = false;
}

bool evaluationSecondeChance::aEncoreDesQuestions() const
{
    return d_index < static_cast<int>(questionnaireRef().questions().size());
}

question& evaluationSecondeChance::questionCourante()
{
    return *(questionnaireRef().questions()[d_index]);
}

void evaluationSecondeChance::repondre(const std::string& saisie)
{
    d_essais++;

    question& q = questionCourante();
    if (q.verifierReponse(saisie)) {
        q.changeEtat(REPONDUJUSTE);
        d_bonnesReponses++;
        d_dejaReposee = false;
        d_afficherBonneReponse = false;
    } else {
        if (!d_dejaReposee) {
            d_dejaReposee = true;
            return;
        }
        q.changeEtat(REPONDUFAUX);
        d_afficherBonneReponse = true;
    }
}

bool evaluationSecondeChance::peutAfficherBonneReponse() const
{
    return d_afficherBonneReponse;
}

void evaluationSecondeChance::questionSuivante()
{
    d_index++;
    d_dejaReposee = false;
    d_afficherBonneReponse = false;
}

int evaluationSecondeChance::nombreQuestions() const
{
    return static_cast<int>(questionnaireRef().questions().size());
}

int evaluationSecondeChance::nombreEssais() const
{
    return d_essais;
}

int evaluationSecondeChance::nombreBonnesReponses() const
{
    return d_bonnesReponses;
}
