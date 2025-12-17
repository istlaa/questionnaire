#ifndef EVALUATION_ADAPTATIVE_H
#define EVALUATION_ADAPTATIVE_H

#include "evaluation.h"
#include <random>

class EvaluationAdaptative : public Evaluation {
public:
    EvaluationAdaptative(const questionnaire& q);
    bool aUneQuestion() const override;
    question& questionCourante() override;
    void donneReponse(const std::string& rep) override;
    bool peutAfficherBonneReponse() const override;
    void questionSuivante() override;

private:
    bool d_afficherBonneReponse = false;
    std::mt19937 d_rng; // Générateur de nombre
};

#endif
