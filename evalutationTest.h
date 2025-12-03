#ifndef EVALUATION_TEST_H
#define EVALUATION_TEST_H

#include "evaluation.h"

class EvaluationTest : public Evaluation {
public:
    EvaluationTest(const questionnaire& q);
    bool aUneQuestion() const override;
    question& questionCourante() override;
    void donneReponse(const std::string& rep) override;
    bool peutAfficherBonneReponse() const override;
    void questionSuivante() override;

private:
    bool d_afficherBonneReponse = false;
};

#endif
