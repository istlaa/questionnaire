#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H
#include<vector>
#include"question.h"

class questionnaire {
    public:
        questionnaire(const std::vector<question>&questions);
    private:
        std::vector<question> d_questions;

};

#endif