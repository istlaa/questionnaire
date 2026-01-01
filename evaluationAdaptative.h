#ifndef EVALUATIONADAPTATIVE_H
#define EVALUATIONADAPTATIVE_H

#include "evaluation.h"
#include <vector>

class evaluationAdaptative : public evaluation {
public:
    explicit evaluationAdaptative(questionnaire& q);

    void commencer() override;
    bool aEncoreDesQuestions() const override;
    question& questionCourante() override;

    void repondre(const std::string& saisie) override;
    bool peutAfficherBonneReponse() const override;
    void questionSuivante() override;

    int nombreQuestions() const override;
    int nombreEssais() const override;
    int nombreBonnesReponses() const override;

private:
    std::vector<int> d_indices;
    int d_position;
    int d_essais;
    int d_bonnesReponses;
};

#endif

