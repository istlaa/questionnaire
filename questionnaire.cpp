#include"questionnaire.h"
#include<vector>
#include<fstream>
/*
*****************************************************************************************************
*****************************************************************************************************
****************** Définition du constructeur *******************************************************
*****************************************************************************************************
*****************************************************************************************************
*/

questionnaire::questionnaire(const string &titre):d_questions{}, d_titre{titre}
{}



/*
*****************************************************************************************************
*****************************************************************************************************
****************** Définitions des méthodes de questionnaire ****************************************
*****************************************************************************************************
*****************************************************************************************************
*/

const vector<unique_ptr<question>>& questionnaire::questions() const { return d_questions;}

/*vector<question*> questionnaire::questionsFausses()  const
{
    vector<question*> qFausses{};
    for(const auto &q:d_questions)
    {
        if(q->etat() == REPONDUFAUX)
            qFausses.push_back(q.get());
    }
    return qFausses;
}*/

/*int questionnaire::score()  const
{
    return d_score;
}*/

/*int questionnaire::nbQuestionsRepondus()    const
{
    unsigned int nb = 0;
    for(const auto &q:d_questions)
    {
        if(q->etat() != NONREPONDU)
            nb++;
    }
    return nb;
}*/

string questionnaire::titre()   const
{
    return d_titre;
}

/*bool questionnaire::estFini()   const
{
    return nbQuestionsRepondus() == d_questions.size();
}*/

/*void questionnaire::changeScore(int nscore)
{
    d_score = nscore;
}*/


bool questionnaire::sauvegarder(const string& nomFichier) const
{
    ofstream fichier(nomFichier);
    if(fichier)
    {
        fichier << "Questionnaire: " << d_titre << "\n";
        for(const auto &q:d_questions)
        {
           q->ecrireDansFichier(fichier);
            fichier << "\n";
        }
        fichier.close();
        return true;
    } else {
        return false;
    }

}

void questionnaire::ajouteQuestion(unique_ptr<question> q)
{
    d_questions.push_back(move(q));
}

/*
*****************************************************************************************************
*****************************************************************************************************
******************* Définition de méthode chargement*************************************************
*****************************************************************************************************
*****************************************************************************************************
*/

//A COMMIT///
bool questionnaire::chargement(const string &nomFichier)
{
    ifstream fichier(nomFichier);

    if(!fichier.good())
        return false;
    string type;
    string question;

    while(getline(fichier, type))
    {
        if (type.empty())
            continue;
        getline(fichier, question);

        if(type == "TEXTE")
        {
            string reponse;
            getline(fichier, reponse);
            ajouteQuestion(make_unique<questionTexte>(question, reponse));
        }
        else if(type == "NUMERIQUE")
        {
            string reponseStr, minStr, maxStr;
            getline(fichier, reponseStr);
            getline(fichier, minStr);
            getline(fichier, maxStr);
            int reponse = stoi(reponseStr);
            int min = stoi(minStr);
            int max = stoi(maxStr);
            ajouteQuestion(make_unique<questionNumerique>(question, reponse, min, max));
        }
        else if(type == "QCM")
        {
            vector<reponse> reponses;
            for(int i = 0; i < 4; ++i)
            {
                string res_title;
                string bonne_reponse;
                getline(fichier, res_title);
                getline(fichier, bonne_reponse);
                reponses.push_back(reponse{res_title, bonne_reponse == "true"});
            }
            ajouteQuestion(make_unique<questionChoixMultiples>(question, reponses));
        }
    }
    fichier.close();
    return true;
}








