#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <iostream>
#include "team.h"

class Team {    
public:
     Team(){}
    Team(std::string inputName){
        teamName = inputName;
    }
    Team(std::string inputName, int inWins, int inLosses){
        teamName = inputName;
        wins = inWins;
        losses = inLosses;
    }
    std::string setName(std::string inputName){
        teamName = inputName;
    }
    int getWins(int inWins){
        return wins;
    }
    int getLosses(int inLosses){
        return losses;
    }
    int setLosses(int inLosses){
        losses = inLosses;
    }
    int setWins(int inWins){
        wins = inWins;
    }
    void printTeamStatus(){
        std::cout << teamName << wins << "wins | " << losses << "losses" << std::endl;
        std::cout << "Win Percentage: "<< calcWinPercentage() << std::endl;
        if (calcWinPercentage() < 0.5){
            std::cout << "Congratulations, Team "<< teamName << " has a winning average" << std::endl;
        }
        else {
            std::cout << "Team "<< teamName << " has a losing average" << std::endl;

        }


    }


private:
    int wins = 0;
    int losses = 0;
    std::string teamName = "Unknown";
    double calcWinPercentage(){
        double percentage;
        percentage = wins / (wins+losses);
        return percentage;
    }
};





#endif