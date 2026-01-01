#ifndef EVALUATIONTEST_H
#define EVALUATIONTEST_H

#include "evaluation.h"

class evaluationTest : public evaluation {
public:
    explicit evaluationTest(questionnaire& q);

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
    int d_index;
    int d_essais;
    int d_bonnesReponses;
};

#endif
