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
std::string bowler; //input name
const int MAX_ROLLS = 21;
int scoreArr[MAX_ROLLS]; //scores
std::fstream bowlScores; // read from file
int totalPoints = 0;
int frameNumbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int framePoints[10] = {0};
int cumulativePoints[10] = {0};
int firstRoll[10] = {0};
int secondRoll[10] = {0};
int thirdRoll[10] = {0};

// Function Prototypes
void GetFileInfo();
int ComputeFramesFromRolls();
void PrintPartialFrames(int upto);


// Helper: try to compute as many frames as possible from the rolls currently read
// returns number of frames fully computed (0..10)
int ComputeFramesFromRolls(int rollsRead)
{
    int rollIndex = 0;
    int framesComputed = 0;
    int FRAMES = 10;

    for (int frame = 0; frame < FRAMES; ++frame)
    {
        // Not enough rolls to even look at this frame
        if (rollIndex >= rollsRead) break;

        // frames 0..8
        if (frame < 9)
        {
            int first = scoreArr[rollIndex];
            // strike case needs two future rolls
            if (first == 10)
            {
                if (rollIndex + 2 >= rollsRead) break; // can't resolve yet
                firstRoll[frame] = 10;
                secondRoll[frame] = 0;
                framePoints[frame] = 10 + scoreArr[rollIndex + 1] + scoreArr[rollIndex + 2];
                rollIndex += 1;
            }
            else
            {
                if (rollIndex + 1 >= rollsRead) break; // need second roll
                int second = scoreArr[rollIndex + 1];
                firstRoll[frame] = first;
                secondRoll[frame] = second;
                if (first + second == 10)
                {
                    // spare needs one future roll
                    if (rollIndex + 2 >= rollsRead) break;
                    framePoints[frame] = 10 + scoreArr[rollIndex + 2];
                }
                else
                {
                    framePoints[frame] = first + second;
                }
                rollIndex += 2;
            }
        }
        else // 10th frame
        {
            // need at least two rolls for 10th
            if (rollIndex + 1 >= rollsRead) break;
            int first = scoreArr[rollIndex];
            int second = scoreArr[rollIndex + 1];
            firstRoll[frame] = first;
            secondRoll[frame] = second;
            if (first == 10)
            {
                // strike on 10th needs two extra rolls
                if (rollIndex + 2 >= rollsRead) break;
                thirdRoll[frame] = scoreArr[rollIndex + 2];
                framePoints[frame] = first + second + thirdRoll[frame];
                rollIndex += 3;
            }
            else if (first + second == 10)
            {
                // spare on 10th needs one extra roll
                if (rollIndex + 2 >= rollsRead) break;
                thirdRoll[frame] = scoreArr[rollIndex + 2];
                framePoints[frame] = first + second + thirdRoll[frame];
                rollIndex += 3;
            }
            else
            {
                framePoints[frame] = first + second;
                rollIndex += 2;
            }
        }

        // update cumulative for this frame
        if (frame == 0) cumulativePoints[frame] = framePoints[frame];
        else cumulativePoints[frame] = cumulativePoints[frame - 1] + framePoints[frame];

        framesComputed = frame + 1;
    }


    if (framesComputed > 0) 
    {
        totalPoints = cumulativePoints[framesComputed - 1];
    }
    else 
    {
        totalPoints = 0;
    }

    return framesComputed;
}

void PrintPartialFrames(int upto)
{
    std::stringstream frameSS;
    std::stringstream throwSS;
    std::stringstream scoreSS;
    const int COL_W = 5;

    for (int i = 0; i <= upto; ++i)
    {
        frameSS << "|" << std::setw(COL_W - 1) << std::right << frameNumbers[i] << " ";

        std::stringstream tempThrow;
        auto fmtNum = [](int v){ return std::to_string(v); };
        if (i == 9)
        {
            if (thirdRoll[i] != 0)
                tempThrow << fmtNum(firstRoll[i]) << " " << fmtNum(secondRoll[i]) << " " << fmtNum(thirdRoll[i]);
            else
                tempThrow << fmtNum(firstRoll[i]) << " " << fmtNum(secondRoll[i]);
        }
        else
        {
            tempThrow << fmtNum(firstRoll[i]) << " " << fmtNum(secondRoll[i]);
        }
        throwSS << "|" << std::setw(COL_W - 1) << std::right << tempThrow.str() << " ";

        bool isStrike = (firstRoll[i] == 10);
        bool isSpare = (!isStrike) && (firstRoll[i] + secondRoll[i] == 10);
        if (isStrike)
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << "X" << " ";
        else if (isSpare)
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << "/" << " ";
        else
            scoreSS << "|" << std::setw(COL_W - 1) << std::right << cumulativePoints[i] << " ";
    }

    std::string fstr = frameSS.str();
    if (!fstr.empty() && fstr[0] == '|') fstr = fstr.substr(1);
    std::string tstr = throwSS.str();
    if (!tstr.empty() && tstr[0] == '|') tstr = tstr.substr(1);
    std::string sstr = scoreSS.str();
    if (!sstr.empty() && sstr[0] == '|') sstr = sstr.substr(1);

    std::cout << "Frame: " << fstr << "|" << std::endl;
    std::cout << "Throw: " << tstr << "|" << std::endl;
    std::cout << "Score: " << sstr << "|" << std::endl;
    std::cout << std::endl;
}

void GetFileInfo()
{
    std::cout << "Enter bowler file: ";
    std::cin >> bowler;

    bowlScores.open(bowler);

    if (!bowlScores.is_open())
    {
        std::cout << "Error Opening File -- Try Again" << std::endl;
        return;
    }

    int rollsRead = 0;
    int lastPrintedFrame = -1;
    int val;
    while (rollsRead < MAX_ROLLS && (bowlScores >> val))
    {
        scoreArr[rollsRead++] = val;

        int framesNow = ComputeFramesFromRolls(rollsRead);
        while (lastPrintedFrame + 1 <= framesNow - 1)
        {
            lastPrintedFrame++;
            PrintPartialFrames(lastPrintedFrame);
        }
    }

    bowlScores.close();
}

int main()
{
    GetFileInfo();

    return 0;
}


