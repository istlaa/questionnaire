#define DOCTEST_CONFIG_IMPLEMENT
#include <cstdlib>
#include <stdexcept>
#include "doctest.h"
#include "evaluation.h"
#include "questionnaire.h"

int main(int argc, char** argv)
{
    doctest::Context context;
    int res = context.run();

    system("pause");
    return res;
}

class EvaluationFake : public evaluation {
public:
    explicit EvaluationFake(questionnaire& q) : evaluation(q) {}

    questionnaire& accessQuestionnaire() {
        return questionnaireRef();
    }

    const questionnaire& accessQuestionnaire() const {
        return questionnaireRef();
    }


    void commencer() override {}
    bool aEncoreDesQuestions() const override { return false; }
    question& questionCourante() override { throw std::logic_error("pas de question"); }
    void repondre(const std::string&) override {}
    bool peutAfficherBonneReponse() const override { return false; }
    void questionSuivante() override {}

    int nombreQuestions() const override { return 0; }
    int nombreEssais() const override { return 0; }
    int nombreBonnesReponses() const override { return 0; }
};


TEST_CASE("evaluation conserve la référence du questionnaire")
{
    questionnaire q("Test questionnaire");
    EvaluationFake e(q);

    CHECK(&e.accessQuestionnaire() == &q);
}

TEST_CASE("questionnaireRef const retourne la bonne référence")
{
    questionnaire q("Const questionnaire");
    const EvaluationFake e(q);

    CHECK(&e.accessQuestionnaire() == &q);
}

TEST_CASE("estSecondeChance retourne false par défaut")
{
    questionnaire q("Second chance");
    EvaluationFake e(q);

    CHECK_FALSE(e.estSecondeChance());
}

