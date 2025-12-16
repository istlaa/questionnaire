#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "questionChoixMultiples.h"
#include "reponse.h"
#include <vector>
#include <iostream>
#include <string>

TEST_CASE("La classe QCM fonctionne bien")
{
    reponse r1{"Terre",false};
    reponse r2{"V�nus",false};
    reponse r3{"Mercure",true};
    reponse r4{"Mars",false};
    vector<reponse> reps{r1,r2,r3,r4};
    questionChoixMultiples qcm{"Quelle est la plan�te la plus proche du soleil",reps};
    std::string repselection;
    SUBCASE("La reponse selectionnee est juste")
    {
        repselection = "Mercure";
        REQUIRE_EQ(qcm.verifierReponse(repselection),true);
    }
    SUBCASE("La reponse selectionnee est fausse")
    {
        repselection = "Terre";
        REQUIRE_UNARY_FALSE(qcm.verifierReponse(repselection));
    }
}
