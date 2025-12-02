#ifndef REPONSE_H
#define REPONSE_H
#include<string> 

//reponses aux questions à choix multiples
class reponse{
    public:
        reponse(const std::string &nom,bool estJuste);
        bool estSelectionne()   const;
        void changeSelection(bool e);
        std::string nom()   const;
        const bool estJuste()   const;
    private:
        std::string d_nom;
        bool d_selectionne;
        bool d_juste;
};

#endif