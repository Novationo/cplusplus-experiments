/*
Dylan Smith
Making and breaking classes

*/

/*
DO NOT ALTER MAIN
*/

#include <iostream>
#include <string>
#include <cassert>
#include "team.h"

int main() {

    Team raven("Raven");
    assert(raven.getName() == "Raven");
    assert(raven.getWins() == 0);
    assert(raven.getLosses() == 0);
    raven.setWins(13);
    raven.setLosses(3);
    assert(raven.getName() == "Raven");
    assert(raven.getWins() == 13);
    assert(raven.getLosses() == 3);

    raven.printTeamStatus();

    Team angels;
    assert(angels.getName() == "Unknown");
    assert(angels.getWins() == 0);
    assert(angels.getLosses() == 0);
    angels.setName("Angels");
    angels.setWins(80);
    angels.setLosses(82);
    assert(angels.getName() == "Angels");
    assert(angels.getWins() == 80);
    assert(angels.getLosses() == 82);

    angels.printTeamStatus();

    Team rrcc("RRCC", 100, 0);
    assert(rrcc.getName() == "RRCC");
    assert(rrcc.getWins() == 100);
    assert(rrcc.getLosses() == 0);

    rrcc.printTeamStatus();

    std::cout << "\nEnd of Team Class Test\n";
    return 0;
}
