#ifndef QUESTIONTEXTE_H
#define QUESTIONTEXTE_H

#include <string>
#include "question.h"
#include "afficheur.h"

class questionTexte:public question{
    public:
        questionTexte(const std::string &titre,const std::string &bonnereponse);
        std::string reponseDonnee() const;
        bool verifierReponse(string saisie) const override;
        void afficherQuestion(afficheur& os) const override;
        const std::string bonneReponse()  const override;
        void ecrireDansFichier(std::ofstream& fichier) override;
    private:
        std::string d_bonneReponse;
        std::string d_reponse;
};
#endif // QUESTIONTEXTE_H
