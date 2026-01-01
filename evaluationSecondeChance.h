#ifndef EVALUATIONSECONDECHANCE_H
#define EVALUATIONSECONDECHANCE_H

#include "evaluation.h"

class evaluationSecondeChance : public evaluation {
public:
    explicit evaluationSecondeChance(questionnaire& q);
    bool estSecondeChance() const override;


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
    bool d_dejaReposee;
    bool d_afficherBonneReponse;
};

#endif

