#ifndef EVALUATION_SECONDE_CHANCE_H
#define EVALUATION_SECONDE_CHANCE_H

#include "evaluation.h"

class EvaluationSecondeChance : public Evaluation {
public:
    EvaluationSecondeChance(const questionnaire& q);

    bool aUneQuestion() const override;
    question& questionCourante() override;
    void donneReponse(const std::string& rep) override;
    bool peutAfficherBonneReponse() const override;
    void questionSuivante() override;

private:
    bool d_dejaRateUneFois = false;
    bool d_afficherBonneReponse = false;
};

#endif
