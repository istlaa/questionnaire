#ifndef EVALUATION_ADAPTATIVE_H
#define EVALUATION_ADAPTATIVE_H

#include "evaluation.h"
#include <random>
#include <vector>

class EvaluationAdaptative : public Evaluation {
public:
    EvaluationAdaptative(const questionnaire& q);
    bool aUneQuestion() const override;
    question& questionCourante() override;
    int score() const override;
    void changeScore(int nscore) override;
    bool estFini() const override;
    vector<question*> questionsFausses() const override;
    void donneReponse(const std::string& rep) override;
    bool peutAfficherBonneReponse() const override;
    void questionSuivante() override;

private:
    bool d_afficherBonneReponse = false;
    std::mt19937 d_rng;
};

#endif
