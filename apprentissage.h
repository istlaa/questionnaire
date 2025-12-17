#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H
#include "questionnaire.h"


class apprentissage {
public:
    explicit apprentissage(const questionnaire& q);

    void commencer(afficheur& a);

private:
    const questionnaire& d_questionnaire;
};


#endif // APPRENTISSAGE_H
