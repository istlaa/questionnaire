#include"questionnaire.h"

questionnaire::questionnaire(const std::vector<unique_ptr<question>>&questions,const string &titre):d_questions{{}},d_score{0},d_titre{titre}
{}

vector<unique_ptr<question>> questionnaire::questionsFausses()  const
{
    vector<unique_ptr<question>> qFausses{};
    for(const auto &q:d_questions)
    {
        if(q->etat() == REPONDUFAUX)
            qFausses.push_back(move(q));
    }
    return qFausses;
}

int questionnaire::score()  const
{
    return d_score;
}

int questionnaire::nbQuestionsRepondus()    const
{
    int nb = 0;
    for(const auto &q:d_questions)
    {
        if(q->etat() != NONREPONDU)
            nb++;
    }
    return nb;
}

string questionnaire::titre()   const
{
    return d_titre;
}

bool questionnaire::estFini()   const
{
    return nbQuestionsRepondus() == d_questions.size();
}

void questionnaire::changeScore(int nscore)
{
    d_score = nscore;
}

questionnaireSecondeChance::questionnaireSecondeChance():questionnaire{questionsFausses(),titre()} //est-ce que j'ai le droit de faire ça ???
{}
