#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

class RealTimeBowlingGame
{
private:
    std::string bowlerName;
    std::fstream bowlScores;
    int totalPoints = 0;

    const static int TOTAL_FRAMES = 10;
    int frameScores[TOTAL_FRAMES] = {0};
    int runningTotals[TOTAL_FRAMES] = {0};

    int frameRolls[TOTAL_FRAMES][3] = {0};

    int getNextRoll()
    {
        int roll = 0;
        if (bowlScores >> roll)
        {
            return roll;
        }
        return -1; // Indicate end-of-file or error
    }

    // X, /, -
    std::string getRollDisplay(int roll, bool isSpareSecondRoll) const
    {
        if (roll == -1) return " ";
        if (roll == 10 && !isSpareSecondRoll) return "X";
        if (isSpareSecondRoll) return "/";
        if (roll == 0) return "-";
        return std::to_string(roll);
    }

public:
    RealTimeBowlingGame(const std::string& filename): bowlerName(filename)
    {
        bowlScores.open(filename);
        if (!bowlScores.is_open())
        {
            std::cerr << "Error: Could not open file " << bowlerName << std::endl;
        }
    }

    ~RealTimeBowlingGame()
    {
        if (bowlScores.is_open())
        {
            bowlScores.close();
        }
    }

    void calculateScoreRealTime()
    {
        if (!bowlScores.is_open()) return;

        totalPoints = 0;

        for (int frame = 0; frame < TOTAL_FRAMES; ++frame)
        {
            int roll1 = getNextRoll();
            if (roll1 == -1) break;

            int frame_score = 0;
            int r2 = 0; // Initialize second roll
            int r3 = 0; // Initialize third roll (bonus for frame 10)

            // 1. Strike
            if (roll1 == 10)
            {
                int bonusRoll1 = getNextRoll();
                int bonusRoll2 = getNextRoll();

                // Store rolls for visualization
                frameRolls[frame][0] = 10;
                // For strikes in frames 1-9, the second slot is 'X'.
                // For frame 10, all three rolls are stored.
                if (frame == 9) {
                    frameRolls[frame][1] = bonusRoll1;
                    frameRolls[frame][2] = bonusRoll2;
                    r2 = bonusRoll1;
                    r3 = bonusRoll2;
                }

                frame_score = 10 + bonusRoll1 + bonusRoll2;
            }
            else
            {
                // 2. Open Frame or Spare
                r2 = getNextRoll();
                if (r2 == -1) break;

                // Store rolls
                frameRolls[frame][0] = roll1;
                frameRolls[frame][1] = r2;

                // Check for Spare
                if (roll1 + r2 == 10)
                {
                    int bonusRoll1 = getNextRoll();
                    if(frame == 9) {
                        frameRolls[frame][2] = bonusRoll1;
                        r3 = bonusRoll1;
                    }
                    frame_score = 10 + bonusRoll1;
                }
                // Check for Open Frame
                else
                {
                    frame_score = roll1 + r2;
                }
            }

            // Store and display cumulative score
            totalPoints += frame_score;
            frameScores[frame] = frame_score;
            runningTotals[frame] = totalPoints;
        }

    }

    void PrintFrames() const
    {
        // --- 1. Print Header (Frame Numbers) ---
        std::stringstream headerStream;
        headerStream << std::setw(6) << std::left << "Frame |";
        for (int i = 0; i < TOTAL_FRAMES; ++i) {
            headerStream << std::setw(5) << std::right << i + 1 << "|";
        }
        std::cout << headerStream.str() << "\n";

        // --- 2. Print Rolls (Throws) ---
        std::stringstream throwStream;
        throwStream << std::setw(6) << std::left << "Throw |";
        for (int i = 0; i < TOTAL_FRAMES; ++i) {

            int r1 = frameRolls[i][0];
            int r2 = frameRolls[i][1];
            int r3 = frameRolls[i][2]; // Only used for Frame 10 (i=9)

            std::string r1_disp, r2_disp;

            if (i == 9) { // Frame 10 (index 9)
                std::string r3_disp = getRollDisplay(r3, false);

                if (r1 == 10) r1_disp = "X";
                else r1_disp = getRollDisplay(r1, false);

                if (r1 == 10 && r2 == 10) r2_disp = "X";
                else if (r1 + r2 == 10) r2_disp = "/";
                else r2_disp = getRollDisplay(r2, false);

                if ((r1 == 10 || r1 + r2 == 10) && r3 == 10) r3_disp = "X";
                else if (r1 + r2 == 10 && r2 + r3 == 10) r3_disp = "/"; // If third roll makes a spare after first two
                else r3_disp = getRollDisplay(r3, false);

                // Print all three rolls for Frame 10
                throwStream << std::setw(1) << r1_disp
                            << std::setw(2) << r2_disp
                            << std::setw(2) << r3_disp << "|";
            }
            else { // Frames 1-9
                if (r1 == 10) { // Strike
                    r1_disp = " ";
                    r2_disp = "X";
                } else if (r1 + r2 == 10) { // Spare
                    r1_disp = getRollDisplay(r1, false);
                    r2_disp = "/";
                } else { // Open Frame
                    r1_disp = getRollDisplay(r1, false);
                    r2_disp = getRollDisplay(r2, false);
                }
                // Print the two slots for Frames 1-9
                 throwStream << std::setw(2) << std::right << r1_disp << " "
                            << std::setw(1) << r2_disp << " |";
            }
        }
        std::cout << throwStream.str() << "\n";

        // --- 3. Print Running Score ---
        std::stringstream scoreStream;
        scoreStream << std::setw(6) << std::left << "Score |";
        for (int i = 0; i < TOTAL_FRAMES; ++i) {
            // Only print if the frame was actually calculated
            if (runningTotals[i] > 0) {
                scoreStream << std::setw(5) << std::right << runningTotals[i] << "|";
            } else {
                scoreStream << std::setw(5) << std::right << " " << "|";
            }
        }
        std::cout << scoreStream.str() << "\n";
    }
};

int main()
{
    std::string filename;
    std::cout << "Enter bowler file: ";
    std::cin >> filename;

    RealTimeBowlingGame game(filename);

    // 1. Calculate the scores in real-time while reading the file
    game.calculateScoreRealTime();

    // 2. Print the frames using the stored array data
    game.PrintFrames();

    return 0;
}
