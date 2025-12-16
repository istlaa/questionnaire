#include"../questionNumerique.h"
#include"doctest.h"
#include<iostream>
#include <string>

TEST_CASE("La classe verfie bien les reponses")
{
    questionNumerique qn{"En quelle annee s'est terminee la Seconde Guerre Mondiale ?",1945,1943,1947};
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
