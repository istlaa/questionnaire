#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../questionnaire.h"
#include <string>

questionnaire q{"test"};

TEST_CASE("Constructeur du questionnaire")
{
    REQUIRE_EQ(q.questions().size(),0);
    REQUIRE_EQ(q.titre(),"test");
}

TEST_CASE("Chargement du questionnaire")
{
    questionnaire q2{"test2"};
    std::string nomFichier;
    SUBCASE("Le nom du fichier est bon")
    {
        nomFichier = "../listequestions.txt";
        
        REQUIRE_EQ(q2.chargement(nomFichier), true);
    }
    SUBCASE("Le nom du fichier n'est pas bon")
    {
        nomFichier = "fichierInexistant.txt";
        REQUIRE_EQ(q2.chargement(nomFichier),false);
    }

}

TEST_CASE("Sauvegarde du questionnaire")
{
    SUBCASE("Sauvegarde sans questions")
    {
        std::string nomFichier = "sauvegarde_vide.txt";
        REQUIRE_EQ(q.sauvegarder(nomFichier), true);
    }
    SUBCASE("Sauvegarde avec questions")
    { 
    questionTexte qt{"Quelle est la capitale de la France?","Paris"};
    questionNumerique qn{"Combien de continents y a-t-il sur Terre?",7,5,8};
    questionChoixMultiples qcm{"Quelle(s) couleur(s) trouve-t-on dans le drapeau français?", {reponse{"Bleu",true}, reponse{"Vert",false}, reponse{"Blanc",true}, reponse{"Rouge",true}}};
    questionnaire q3{"test3"};
    q3.ajouteQuestion(std::make_unique<questionTexte>(qt));
    q3.ajouteQuestion(std::make_unique<questionNumerique>(qn));
    q3.ajouteQuestion(std::make_unique<questionChoixMultiples>(qcm));
    
    std::string nomFichier = "sauvegarde_test.txt";
    REQUIRE_EQ(q3.sauvegarder(nomFichier), true);
    }
   
}
