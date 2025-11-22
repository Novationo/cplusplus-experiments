/*
Dylan Smith
Bowling Sim
A bowling program that calculates score in realtime 
and makes it look pretty while doing it.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

// Global variables
std::string bowler;
const int MAX_ROLLS = 21;
int scoreArr[MAX_ROLLS];
std::fstream bowlScores;
int totalPoints = 0;

// Function Prototypes
void GetFileInfo();
void CalculateScore();

void GetFileInfo()
{
    int count = 0;
    std::cout << "Enter bowler file: ";
    std::cin >> bowler;

    bowlScores.open(bowler);

    if (!bowlScores.is_open())
    {
        std::cout << "Error Opening File -- Try Again" << std::endl;
        GetFileInfo();
        return;
    }

    while(bowlScores >> scoreArr[count])
    {
        count++;
        if (count >= MAX_ROLLS) break; // safety break / eof
    }
    bowlScores.close();
}

void CalculateScore()
{
    int rollIndex = 0;
    totalPoints = 0;
    const int FRAMES = 10;

    for (int frame = 1; frame <= FRAMES; frame++)
    {
        int frameScore = 0;

        // strike
        if (scoreArr[rollIndex] == 10)
        {
            frameScore = 10 + scoreArr[rollIndex + 1] + scoreArr[rollIndex + 2];
            rollIndex++;
            // std::cout << "Frame " << frame << ": strike Score: " << frameScore << std::endl;
        }
        // spare
        else if (scoreArr[rollIndex] + scoreArr[rollIndex + 1] == 10)
        {
            frameScore = 10 + scoreArr[rollIndex + 2];
            rollIndex += 2;
            // std::cout << "Frame " << frame << ": spare - Score: " << frameScore << std::endl;
        }
        // open
        else
        {
            frameScore = scoreArr[rollIndex] + scoreArr[rollIndex + 1];
            rollIndex += 2;
            // std::cout << "Frame " << frame << "open - core: " << frameScore << std::endl;
        }

        totalPoints += frameScore;
    }
}


int main()
{
    GetFileInfo();

    CalculateScore();

    std::cout << "\nPoints per bowl: ";
    for (int i = 0; i < MAX_ROLLS; i++)
    {
        std::cout << scoreArr[i] << " ";
    }

    std::cout << "\nFinal Score: " << totalPoints << std::endl;

    return 0;
}
