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
    int roll_index = 0;
    totalPoints = 0;
    const int FRAMES = 10;

    for (int frame = 1; frame <= FRAMES; frame++)
    {
        int frame_score = 0;

        // strike
        if (scoreArr[roll_index] == 10)
        {
            frame_score = 10 + scoreArr[roll_index + 1] + scoreArr[roll_index + 2];
            roll_index++;
            std::cout << "Frame " << frame << ": Strike! Score: " << frame_score << std::endl;
        }
        // spare
        else if (scoreArr[roll_index] + scoreArr[roll_index + 1] == 10)
        {
            frame_score = 10 + scoreArr[roll_index + 2];
            roll_index += 2;
            std::cout << "Frame " << frame << ": Spare! Score: " << frame_score << std::endl;
        }
        // open
        else
        {
            frame_score = scoreArr[roll_index] + scoreArr[roll_index + 1];
            roll_index += 2;
            std::cout << "Frame " << frame << ": Open Frame. Score: " << frame_score << std::endl;
        }

        totalPoints += frame_score;
    }
}

void PrintFrames()
{
    std::stringstream header;
    header << std::setw(6) << ;

}

int main()
{
    GetFileInfo();

    CalculateScore();

    std::cout << "\nPoints per bowl: ";
    for (int i = 0; i < MAX_ROLLS; i++ )
    {
        std::cout << scoreArr[i] << " ";
    }

    std::cout << "\nFinal Score: " << totalPoints << std::endl;

    return 0;
}
