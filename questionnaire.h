#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"
#include<memory>
using namespace std;

class questionnaire {
    public:
        questionnaire(const std::vector<unique_ptr<question>>&questions);
    private:
        string d_titre;
        std::vector<unique_ptr<question>> d_questions;

};

#endif