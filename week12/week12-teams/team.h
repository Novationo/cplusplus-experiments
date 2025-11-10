#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team {
public:
    Team(){}
    Team(std::string teamName);
    Team(std::string teamName, int wins, int losses);

    std::string getName();
    void setName(std::string inputName);
    int getWins();
    int getLosses();

    void setLosses(int losses);
    void setWins(int wins);
    void printTeamStatus();


private:
    int wins = 0;
    int losses = 0;
    std::string teamName = "Unknown";
    double calcWinPercentage();

};

#endif
