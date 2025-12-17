#include "evaluationAdaptative.h"
#include <vector>
#include <string>
#include <random>
#include <stdexcept>
using std::out_of_range;

// Utilisation de d_questionnaire et d_index
EvaluationAdaptative::EvaluationAdaptative(const questionnaire& q) 
    : d_questionnaire(q), d_index(0) {}

bool EvaluationAdaptative::aUneQuestion() const {
    return d_index < d_questionnaire.questions().size();
}

question& EvaluationAdaptative::questionCourante() {
    if (!aUneQuestion()) {
        throw out_of_range("Plus de questions disponibles.");
    }
    return *d_questionnaire.questions()[d_index];
}

void EvaluationAdaptative::donneReponse(const std::string& rep) {
    if (!aUneQuestion()) {
        throw out_of_range("Plus de reponse a donner");
    }
    
    d_questionnaire.questions()[d_index]->verifierReponse(rep) ?  d_questionnaire.questions()[d_index]->changeEtat(REPONDUJUSTE) :  d_questionnaire.questions()[d_index]->changeEtat(REPONDUFAUX);
}

bool EvaluationAdaptative::peutAfficherBonneReponse() const {
    return aUneQuestion() && d_questionnaire.questions()[d_index]->etat() != NONREPONDU;
}

void EvaluationAdaptative::questionSuivante() {
    if (aUneQuestion()) {
        ++d_index;
    } else {
        throw out_of_range("Plus de questions disponibles.");
    }
}