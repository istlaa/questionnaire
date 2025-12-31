#include "evaluation.h"

evaluation::evaluation(questionnaire& q)
    : d_questionnaire(q)
{}

questionnaire& evaluation::questionnaireRef()
{
    return d_questionnaire;
}

const questionnaire& evaluation::questionnaireRef() const
{
    return d_questionnaire;
}
