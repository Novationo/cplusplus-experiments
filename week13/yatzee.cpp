/*
Program info: name and summary
*/

#include <cstdlib>  // srand and rand
#include <iostream>

// Sort the array in ascending order
void bubbleSort(int diceValues[]);

// Check for singles (sum all dice) - return sum
int CheckSingles(int diceValues[]);

// Check for three of a kind - return 30 or 0
int Check3Kind(int diceValues[]);

// Check for four of a kind - return 40 or 0
int Check4Kind(int diceValues[]);

// Check for five of a kind - return 50 or 0
int Check5Kind(int diceValues[]);

// Check for full house - return 35 or 0
int CheckFullHouse(int diceValues[]);

// Check for straight - return 45 or 0
int CheckStraight(int diceValues[]);

// Find high score - return high score
int FindHighScore(int diceValues[]);

const int MAX = 5; // maximum number of dice

int main() {
    int seed = 0;
    std::cout << "Enter seed: ";
    std::cin >> seed;

    srand(seed);

    int diceValues[MAX]; // array declared of type int and size of 5
    int highScore = 0;

    // Fill array with five values from random dice rolls  
    for (int i = 0; i < MAX; ++i) {
        diceValues[i] = rand() % 6 + 1; // roll of die
    }

    // Sort values in ascending order
    bubbleSort(diceValues);

    // Print the Dice Poker hand
    std::cout << " Dice Poker Hand\n";
    for(int i = 0; i < MAX; i++){
        std::cout << diceValues[i] << "\t";
    }
    std::cout << "\n\n";

    // Find high score and output
    highScore = FindHighScore(diceValues);
    std::cout << "High score: " << highScore;

    std::cout << "\n\n";

    return 0;
}

// Sort the array in ascending order
void bubbleSort(int diceValues[]){
    bool sorted = false; //a counter
    while(!sorted){
    sorted = true;
    for(int i = 0; i < MAX-1; i++){
        if(diceValues[i] > diceValues[i+1]){
            int tmp = diceValues[i];
            diceValues[i] = diceValues[i+1];
            diceValues[i+1] = tmp;
            sorted = false;
        }
    }
    } 
}

// Check for singles (sum all dice) - return sum
int CheckSingles(int diceValues[]){
    int sum = 0;
    for(int i = 0; i < MAX; i++){
        sum += diceValues[i];
    }
    return sum;
}


// score = 30
int Check3Kind(int diceValues[]) {
 

    // 0, 1, 2
    if (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2]) {
        return 30;
    }

    // 1, 2, 3
    if (diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3]) {
        return 30;
    }

    // 2, 3, 4
    if (diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]) {
        return 30;
    }

    //else{}
    return 0;
  
}

// score = 40
int Check4Kind(int diceValues[]){

    // 0, 1, 2, 3
    if (diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3]) {
        return 40;
    }

    // indices 1, 2, 3, 4
    if (diceValues[1] == diceValues[2] && diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]) {
        return 40;
    }

    return 0;

}

// score = 50
int Check5Kind(int diceValues[]){
    
    // Step 1: Loop through all the dice values except the last one.
    // Step 2: For each value, compare it to the one that follows.
    // Step 3: If any pair of adjacent values is not equal,

    //         immediately return a score of 0 (not all values match).

    for (int i = 0; i < MAX - 1; ++i) {
        if (diceValues[i] != diceValues[i+1]) {
            return 0;
        }
    }

    // Step 4: If all values are equal (no mismatches found),
    //         return a score of 50 to indicate a five-of-a-kind.
    return 50;
    
}

// score = 35
int CheckFullHouse(int diceValues[]){
    
    // xxx yy
    if ((diceValues[0] == diceValues[1] && diceValues[1] == diceValues[2]) && // first 3 
        (diceValues[3] == diceValues[4]) &&                                  // last 2 
        (diceValues[2] != diceValues[3])) {
        return 35;
    }

    // xx yyy 
    if ((diceValues[0] == diceValues[1]) &&                                  // first 2 
        (diceValues[2] == diceValues[3] && diceValues[3] == diceValues[4]) && // Last 3 
        (diceValues[1] != diceValues[2])) {
        return 35;
    }

    // Step 3: If neither full house pattern is found,
    //         return a score of 0.
    return 0;
    
}

// score = 45
int CheckStraight(int diceValues[]){
    
    // Step 1: Loop through each dice value except the last one.
    for (int i = 0; i < MAX - 1; ++i) {

    // Step 2: For each value, check if the next value is exactly one greater.
    // Step 3: If any value does not follow this consecutive pattern,
    //         return a score of 0 (not a straight).
        if (diceValues[i+1] != diceValues[i] + 1) {
            return 0;
        }
    }

    // Step 4: If all values are in consecutive order,
    //         return a score of 45 to indicate a straight.
    return 45;
    
}

// Find high score
int FindHighScore(int diceValues[]) {
    int high =0;
    // Step 1: Initialize a variable to keep track of the highest score found. (Done: high = 0)

    // Step 2: Check if the dice values match the pattern for five-of-a-kind.
    int score5Kind = Check5Kind(diceValues);
    if (score5Kind > high) {
        high = score5Kind;
    }

    // Step 3: Check for a straight pattern.
    int scoreStraight = CheckStraight(diceValues);
    if (scoreStraight > high) {
        high = scoreStraight;
    }

    // Step 4: Check for four-of-a-kind.
    int score4Kind = Check4Kind(diceValues);
    if (score4Kind > high) {
        high = score4Kind;
    }

    // Step 5: Check for a full house.
    int scoreFullHouse = CheckFullHouse(diceValues);
    if (scoreFullHouse > high) {
        high = scoreFullHouse;
    }

    // Step 6: Check for three-of-a-kind.
    int score3Kind = Check3Kind(diceValues);
    if (score3Kind > high) {
        high = score3Kind;
    }

    // Step 7: Check for the highest single-value score (e.g., sum of dice).
    int scoreSingles = CheckSingles(diceValues);
    if (scoreSingles > high) {
        high = scoreSingles;
    }

    // Step 8: Return the highest score found among all pattern checks.
    return high;
    
}