#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "questionTexte.h"
#include "afficheurTerminal.h"
#include <string>
#include <iostream>


TEST_CASE("La classe vérifie correctement les saisies")
{
    questionTexte qt{"Qui est le président de la France ?","Emmanuel Macron"};
    std::string rep;
    SUBCASE("La reponse est juste")
    {
        rep = qt.bonneReponse();
        REQUIRE_EQ(qt.verifieReponse(rep),true);
    }
    SUBCASE("La reponse est fausse")
    {
        rep = "Francois Hollande";
        REQUIRE_UNARY_FALSE(qt.verifieReponse(rep));
    }

}
