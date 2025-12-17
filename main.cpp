#include <iostream>
#include "menu.h"


using namespace std;

int main()
{
    afficheurTerminal a{};
    menu m{a};
    m.executionProgramme();
    return 0;
}
