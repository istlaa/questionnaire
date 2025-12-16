#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../questionTexte.h"
#include <string>
#include <iostream>


TEST_CASE("La classe verifie correctement les saisies")
{
    questionTexte qt{"Qui est le president de la France ?","Emmanuel Macron"};
    std::string rep;
    SUBCASE("La reponse est juste")
    {
        rep = "Emmanuel Macron";
        REQUIRE_EQ(qt.verifierReponse(rep),true);
    }
    SUBCASE("La reponse est fausse")
    {
        rep = "Francois Hollande";
        REQUIRE_EQ(qt.verifierReponse(rep),false);
    }

}
