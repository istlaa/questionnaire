#ifndef EVALUATION_H
#define EVALUATION_H

#include "questionnaire.h"
#include <vector>
#include <memory>
#include <string>

class Evaluation {
public:
    virtual ~Evaluation() = default;
    virtual bool aUneQuestion() const = 0;
    virtual question& questionCourante() = 0;
    virtual void donneReponse(const std::string& rep) = 0;
    virtual bool peutAfficherBonneReponse() const = 0;
    virtual void questionSuivante() = 0;

protected:

    std::vector<std::unique_ptr<question>> d_questions;
    std::size_t d_indiceCourant = 0;
};

#endif

