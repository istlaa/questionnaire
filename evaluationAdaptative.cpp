#include "evaluationAdaptative.h"
#include <algorithm>
#include <random>

evaluationAdaptative::evaluationAdaptative(questionnaire& q)
    : evaluation(q), d_position(0), d_essais(0), d_bonnesReponses(0)
{}

void evaluationAdaptative::commencer()
{
    int n = static_cast<int>(questionnaireRef().questions().size());

    d_indices.resize(n);
    for (int i = 0; i < n; ++i)
        d_indices[i] = i;

    std::random_shuffle(d_indices.begin(), d_indices.end());

    d_position = 0;
    d_essais = 0;
    d_bonnesReponses = 0;
}


bool evaluationAdaptative::aEncoreDesQuestions() const
{
    return d_position < static_cast<int>(d_indices.size());
}

question& evaluationAdaptative::questionCourante()
{
    int idx = d_indices[d_position];
    return *(questionnaireRef().questions()[idx]);
}

void evaluationAdaptative::repondre(const std::string& saisie)
{
    d_essais++;

    question& q = questionCourante();
    if (q.verifierReponse(saisie)) {
        q.changeEtat(REPONDUJUSTE);
        d_bonnesReponses++;
        d_position++;
    } else {
        q.changeEtat(REPONDUFAUX);
        int idx = d_indices[d_position];
        d_indices.erase(d_indices.begin() + d_position);
        d_indices.push_back(idx);
    }
}

bool evaluationAdaptative::peutAfficherBonneReponse() const
{
    return false;
}

void evaluationAdaptative::questionSuivante()
{
    //vide
}

int evaluationAdaptative::nombreQuestions() const
{
    return static_cast<int>(questionnaireRef().questions().size());
}

int evaluationAdaptative::nombreEssais() const
{
    return d_essais;
}

int evaluationAdaptative::nombreBonnesReponses() const
{
    return d_bonnesReponses;
}
