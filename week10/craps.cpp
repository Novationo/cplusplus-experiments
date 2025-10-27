/*
Name: Dylan Smith
Assignment Name: Craps
Summary: Create a simple rice info thingamajig for the dice game craps
*/
#include <iostream>
#include <cstdlib> // srand and rand
#include <string>

int rollDie(int numSides);
void printDiceRoll(int die1, int die2);
std::string firstThrow(int die1, int die2);
std::string pointThrow(int points, int die1, int die2);

int main() {
    int seed = 0;
    std::cout << "Enter program seed: ";
    std::cin >> seed;
    std::cout << "\n";
    srand(seed);

    int die1 = 0;
    int die2 = 0;
    die1 = rollDie(6);
    die2 = rollDie(6);

    std::cout << "Craps First Throw\n";
    printDiceRoll(die1, die2);

    std::string gameStatus = firstThrow(die1, die2);
    int point = die1 + die2;

    std::cout << "\nGame Status " << gameStatus << "\n";

    while (gameStatus != "WIN" && gameStatus != "LOSE") {
        die1 = rollDie(6);
        die2 = rollDie(6);

        printDiceRoll(die1, die2);

        gameStatus = pointThrow(point, die1, die2);
        std::cout << "\nGame Status " << gameStatus << "\n";
    }

    return 0;
}

int rollDie(int numSides){
    int roll = (rand() % numSides) + 1;
    return roll;
}

void printDiceRoll(int dieVal1, int dieVal2){
    std::cout << "Die 1: " << dieVal1 << "\t" << "Sum: " << (dieVal1+dieVal2) << std::endl;
    std::cout << "Die 2: " << dieVal2 << std::endl;

}

std::string firstThrow(int dieVal1, int dieVal2){
    int sum = dieVal1 + dieVal2;
    std::string status;
    if (sum == 7 || sum == 11){
        status = "WIN"; // natural
    }
    else if (sum == 2 || sum == 3 || sum == 12){
        status = "LOSE"; //craps
    }
    else{
        status = "Roll for point: " + std::to_string(sum);
    }

    return status;
}

std::string pointThrow(int points, int dieVal1, int dieVal2){
    int sum = dieVal1 + dieVal2;
    std::string status;
    if (sum == points){
        status = "WIN"; // natural
    }
    else if (sum == 7){
        status = "LOSE"; // craps
    }
    else{
        status = "KEEP rolling for point: " + std::to_string(points);
    }
    return status;
}
