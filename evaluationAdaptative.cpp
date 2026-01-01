#include "evaluationAdaptative.h"
#include <algorithm>
#include <random>

evaluationAdaptative::evaluationAdaptative(questionnaire& q)
    : evaluation(q), d_position(0), d_essais(0), d_bonnesReponses(0)
{}

void evaluationAdaptative::commencer()
{
    int n = questionnaireRef().questions().size();

    d_indices.clear();
    for (int i = 0; i < n; ++i)
        d_indices.push_back(i);

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(d_indices.begin(), d_indices.end(), gen);

    d_position = 0;
    d_essais = 0;
    d_bonnesReponses = 0;
}


bool evaluationAdaptative::aEncoreDesQuestions() const
{
    return !d_indices.empty();
}


question& evaluationAdaptative::questionCourante()
{
    int idx = d_indices.front();
    return *(questionnaireRef().questions()[idx]);
}


void evaluationAdaptative::repondre(const std::string& saisie)
{
    d_essais++;

    int idx = d_indices.front();
    question& q = *(questionnaireRef().questions()[idx]);

    if (q.verifierReponse(saisie))
    {
        q.changeEtat(REPONDUJUSTE);
        d_bonnesReponses++;
        d_indices.erase(d_indices.begin());
    }
    else
    {
        q.changeEtat(REPONDUFAUX);
        d_indices.erase(d_indices.begin());
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
