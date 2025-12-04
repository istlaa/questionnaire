#include"questionnaire.h"

/*
*****************************************************************************************************
*****************************************************************************************************
****************** Définition du constructeur *******************************************************
*****************************************************************************************************
*****************************************************************************************************
*/

questionnaire::questionnaire(const string &titre):d_questions{{}},d_score{0},d_titre{titre}
{}



/*
*****************************************************************************************************
*****************************************************************************************************
****************** Définitions des méthodes de questionnaire ****************************************
*****************************************************************************************************
*****************************************************************************************************
*/

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


void questionnaire::sauvegarder(const string& nomFichier) const
{
    ofstream fichier(nomFichier);
    if(fichier)
    {
        fichier << "Questionnaire: " << d_titre << "\n";
        fichier << "Score: " << d_score << "\n\n";
        for(const auto &q:d_questions)
        {
            q->ecrireQuestion(fichier);
            fichier << "\n";
        }
    }
    fichier.close();
}

void questionnaire::ajouteQuestion(const question &q)
{
    d_questions.push_back(*q);
}

/*
*****************************************************************************************************
*****************************************************************************************************
******************* Définition de méthode chargement*************************************************
*****************************************************************************************************
*****************************************************************************************************
*/

void questionnaireTest::chargement(const string &nomFichier)
{
    ifstream fichier(nomFichier);
    if(!fichier.end())
    {
        //écriture des questions textes
        string questions = "";
        string questionSuivante = "";
        getline(fichier,questions);
        while(questions != "T")
        {
            string reponse;
            getline(fichier,reponse);
            ajouteQuestion(questionTexte{questions,reponse});
            getline(fichier,questionSuivante);
            questions = questionSuivante;
        }
        getline(fichier,questions);

        //écriture questions numériques
        int res,min,max;
        while(questions != "T")
        {
            string reponseprecise,limitemin,limitemax;
            getline(fichier,reponseprecise);
            getline(fichier,limitemin);
            getline(fichier,limitemax);
            res = stoi(reponseprecise);
            min = stoi(limitemin);
            max = stoi(limitemax);
            ajouteQuestion(questionNumerique{questions,res,min,max});
            getline(fichier,questionSuivante);
            questions = questionSuivante;
        }
        getline(fichier,questions);

        //écriture des questions QCM
        while(questions != "T")
        {
            vector<reponse> responses{};
            bool bres1,
            for(int i = 0;i < 4;i++)
            {
                string res_title;
                string bonne_reponse;
                getline(fichier,res_title);
                getline(fichier,bonne_reponse);
                responses.pushback(reponse{res_title,bonne_reponse =="true"});
            }
            ajouteQuestion(questionChoixMultiples{questions,reponses});
            getline(fichier,questionSuivante);
            questions = questionSuivante;
        }
    }
}


