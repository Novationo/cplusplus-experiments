#include <string>
#include <iostream>
#include "team.h"

// No change to constructors
Team::Team(std::string inputName){
    teamName = inputName;
}

Team::Team(std::string inputName, int inWins, int inLosses){
    teamName = inputName;
    wins = inWins;
    losses = inLosses;
}

std::string Team::getName(){
    return teamName;
}

void Team::setName(std::string inputName){
    teamName = inputName;
}

int Team::getWins(){
    return wins;
}

int Team::getLosses(){
    return losses;
}

void Team::setLosses(int inLosses){
    losses = inLosses;
}

void Team::setWins(int inWins){
    wins = inWins;
}

void Team::printTeamStatus(){
    std::cout << teamName << ": " << wins << " wins | " << losses << " losses" << std::endl;
    double winPct = calcWinPercentage();
    std::cout << "Win Percentage: "<< winPct << std::endl;

    if (winPct >= 0.5){
        std::cout << "Congratulations, Team "<< teamName << " has a winning average" << std::endl;
    }
    else {
        std::cout << "Team "<< teamName << " has a losing average" << std::endl;

    }
}

double Team::calcWinPercentage(){
    double percentage;
    percentage = static_cast<double>(wins) / (wins + losses);
    return percentage;
}
