#include"doctest.h"
#include"questionNumerique.h"
#include<iostream>
#include <string>

TEST_CASE("La classe v�rfie bien les r�ponses")
{
    questionNumerique qn{"En quelle ann�e s'est termin�e la Seconde Guerre Mondiale ?",1945,1943,1947};
    qn.ecrireQuestion(std::cout);
    std::string rep;
    SUBCASE("La reponse est dans la portee de bonne reponse")
    {
        rep = "1944";
        REQUIRE_EQ(qn.verifierReponse(rep),true);
    }
    SUBCASE("La reponse n'est pas dans la portee de bonne reponse")
    {
        rep = "1939";
        REQUIRE_EQ(qn.verifierReponse(rep),false);
    }
}
