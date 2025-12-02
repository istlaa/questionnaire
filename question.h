#ifndef QUESTION_H
#define QUESTION_H
#include<string>
class question{
    public:
        question(const std::string &titre,const std::string &bonnereponse);
    protected:
        const enum state {NONREPONDU = 0,REPONDUJUSTE = 1,REPONDUFAUX = 2};
    private:
        enum state etat;
        std::string d_titre;
        std::string d_bonnereponse;
};
#endif