
#ifndef QUESTIONCHOIXMULTIPLES_H
#define QUESTIONCHOIXMULTIPLES_H
#include<string>
#include<vector>
#include"reponse.h"
#include"question.h"
#include <iostream>
class questionChoixMultiples:public question{
    public:
        questionChoixMultiples(const std::string &titre,const std::vector<reponse>&reponses);
        void selectionReponse(int i);
        void enleverReponse(int i);
        bool verifierReponse(string saisie = "") const override;
        const std::vector<reponse> reponses() const;
        void ecrireQuestion(ostream& os) const override;
    protected:
        std::string bonneReponse()  const override;
    private:
        std::vector<reponse> d_reponses;
};
#endif
