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
int frameNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int framePoints[10] = {0};
int cumulativePoints[10] = {0};
int firstRoll[10] = {0};
int secondRoll[10] = {0};
int thirdRoll[10] = {0};

// Function Prototypes
void GetFileInfo();
void CalculateScore();
void PrintScores();


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

    for (int frame = 0; frame < FRAMES; frame++)
    {
        int frameScore = 0;

        // strike
        if (frame < 9 && scoreArr[rollIndex] == 10)
        {
            // regular strike (frames 1..9)
            firstRoll[frame] = 10;
            secondRoll[frame] = 0;
            frameScore = 10 + scoreArr[rollIndex + 1] + scoreArr[rollIndex + 2];
            rollIndex++;
        }
        else if (frame == 9 && scoreArr[rollIndex] == 10)
        {
            // 10th frame strike can have two more rolls
            firstRoll[frame] = scoreArr[rollIndex];
            secondRoll[frame] = scoreArr[rollIndex + 1];
            thirdRoll[frame] = scoreArr[rollIndex + 2];
            frameScore = firstRoll[frame] + secondRoll[frame] + thirdRoll[frame];
            // advance rollIndex defensively
            rollIndex += 3;
        }
        // spare
        else if (frame < 9 && (scoreArr[rollIndex] + scoreArr[rollIndex + 1] == 10))
        {
            firstRoll[frame] = scoreArr[rollIndex];
            secondRoll[frame] = scoreArr[rollIndex + 1];
            frameScore = 10 + scoreArr[rollIndex + 2];
            rollIndex += 2;
        }
        else if (frame == 9 && (scoreArr[rollIndex] + scoreArr[rollIndex + 1] == 10))
        {
            // 10th frame spare: two rolls only plus bonus
            firstRoll[frame] = scoreArr[rollIndex];
            secondRoll[frame] = scoreArr[rollIndex + 1];
            thirdRoll[frame] = scoreArr[rollIndex + 2];
            frameScore = firstRoll[frame] + secondRoll[frame] + thirdRoll[frame];
            rollIndex += 3;
        }
        // open
        else
        {
            // regular open frame (including 10th if no strike/spare)
            firstRoll[frame] = scoreArr[rollIndex];
            secondRoll[frame] = scoreArr[rollIndex + 1];
            frameScore = firstRoll[frame] + secondRoll[frame];
            if (frame == 9)
            {
                // 10th frame might still have a third roll in input but it's only used for strike/spare
                rollIndex += 2;
            }
            else
            {
                rollIndex += 2;
            }
        }

        framePoints[frame] = frameScore;
        if (frame == 0) cumulativePoints[frame] = framePoints[frame];
        else cumulativePoints[frame] = cumulativePoints[frame - 1] + framePoints[frame];
        totalPoints = cumulativePoints[frame];
    }
}

void PrintScores()
{
    // Build three rows (Frame, Throw, Score) and append each frame as a column using stringstream and iomanip
    std::stringstream frameSS;
    std::stringstream throwSS;
    std::stringstream scoreSS;

    // Column width for each frame (including separators)
    const int COL_W = 7;

    for (int f = 0; f < 10; f++)
    {
        // Frame number column: center-ish using setw
        frameSS << "|" << std::setw(COL_W - 1) << std::right << frameNumbers[f] << " ";

        // Throw column: two throws (third only for 10th if present)
        std::stringstream tempThrow;
        // For printing throws we will always show both numbers (including 0 as "0").
        // For 10th frame, show up to three rolls.
        auto fmtNum = [](int v){ return std::to_string(v); };
        if (f == 9)
        {
            // 10th frame: show first, second (always), and third only if non-zero or if strike/spare occurred
            if (thirdRoll[f] != 0)
            {
                tempThrow << fmtNum(firstRoll[f]) << " " << fmtNum(secondRoll[f]) << " " << fmtNum(thirdRoll[f]);
            }
            else
            {
                tempThrow << fmtNum(firstRoll[f]) << " " << fmtNum(secondRoll[f]);
            }
        }
        else
        {
            // frames 1..9: always display both throws numerically
            tempThrow << fmtNum(firstRoll[f]) << " " << fmtNum(secondRoll[f]);
        }
        throwSS << "|" << std::setw(COL_W - 1) << std::right << tempThrow.str() << " ";

        // Score column: for strikes show 'X', for spares show '/', otherwise show cumulative
        bool isStrike = (firstRoll[f] == 10);
        bool isSpare = (!isStrike) && (firstRoll[f] + secondRoll[f] == 10);
        if (isStrike)
        {
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << "X" << " ";
        }
        else if (isSpare)
        {
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << "/" << " ";
        }
        else
        {
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << cumulativePoints[f] << " ";
        }
    }

    // Print the three labeled rows
    std::cout << std::left << std::setw(8) << "Frame" << frameSS.str() << "|" << std::endl;
    std::cout << std::left << std::setw(8) << "Throw" << throwSS.str() << "|" << std::endl;
    std::cout << std::left << std::setw(8) << "Score" << scoreSS.str() << "|" << std::endl;

    std::cout << "\nPoints per bowl: ";
    for (int i = 0; i < MAX_ROLLS; i++)
    {
        std::cout << scoreArr[i] << " ";
    }

    std::cout << "\nFinal Score: " << totalPoints << std::endl;

}

int main()
{
    GetFileInfo();

    CalculateScore();

    PrintScores();

    return 0;
}
