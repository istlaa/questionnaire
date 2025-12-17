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
