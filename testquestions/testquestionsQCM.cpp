#include "../questionChoixMultiples.h"
#include "../reponse.h"
#include"doctest.h"
#include <vector>
#include <iostream>
#include <string>

TEST_CASE("La classe QCM fonctionne bien")
{
    reponse r1{"Terre",false};
    reponse r2{"Venus",false};
    reponse r3{"Mercure",true};
    reponse r4{"Mars",false};
    vector<reponse> reps{r1,r2,r3,r4};
    questionChoixMultiples qcm{"Quelle est la planete la plus proche du soleil",reps};
    SUBCASE("La reponse selectionnee est juste")
    {
        qcm.selectionReponse(2);
        REQUIRE_EQ(qcm.verifierReponse(""),true);
    }
    SUBCASE("La reponse selectionnee est fausse")
    {
        qcm.selectionReponse(0);
        REQUIRE_EQ(qcm.verifierReponse(""),false);
    }
}
