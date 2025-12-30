#ifndef EVALUATION_H
#define EVALUATION_H

#include "questionnaire.h"
#include <string>

class evaluation {
public:
    explicit evaluation(questionnaire& q);
    virtual ~evaluation() = default;

    virtual void commencer() = 0;
    virtual bool aEncoreDesQuestions() const = 0;
    virtual question& questionCourante() = 0;

    virtual void repondre(const std::string& saisie) = 0;
    virtual bool peutAfficherBonneReponse() const = 0;
    virtual void questionSuivante() = 0;

    virtual int nombreQuestions() const = 0;
    virtual int nombreEssais() const = 0;
    virtual int nombreBonnesReponses() const = 0;

protected:
    questionnaire& questionnaireRef();
    const questionnaire& questionnaireRef() const;

private:
    questionnaire& d_questionnaire;
};

#endif
