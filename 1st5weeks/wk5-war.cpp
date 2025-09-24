#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int main() {
    /*
    Step 1: Set Up Random Number Generator
    Usually we use srand(time(0)); to seed the random number generator so you get different results each time the program runs. For this program to match to auto tests, the seed value is entered as input.
    */

    int seed;
    std::cout << "Enter seed: ";
    std::cin >> seed;
    srand(seed);

    /*
    Step 2: Generate Two Random Cards
    For each card:
    Generate a rank between 2 and 14:
    11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    Generate a suit between 1 and 4:
    1 = Clubs, 2 = Diamonds, 3 = Hearts, 4 = Spades
    */

    int rank1 = rand() % 13 + 2;
    int suit1 = rand() % 4 + 1;

    int rank2 = rand() % 13 + 2;
    int suit2 = rand() % 4 + 1;

    /*
    Step 3: Convert Rank and Suit to Names
    Use if or switch statements to convert:
    Rank numbers to names (e.g., 11 → Jack, 14 → Ace)
    Suit numbers to names (e.g., 3 → Hearts)
    */
    // CARD 1
    std::string card1;
    if (rank1 == 14)
        card1 = "Ace of ";
    else if (rank1 == 13)
        card1 = "King of ";
    else if (rank1 == 12)
        card1 = "Queen of ";
    else if (rank1 == 11)
        card1 = "Jack of ";
    else
        card1 = std::to_string(rank1) + " of ";

    if (suit1 ==1)
        card1 += "Clubs";
    if (suit1 ==2)
        card1 += "Diamonds";
    if (suit1 ==3)
        card1 += "Hearts";
    if (suit1 ==4)
        card1 += "Spades";

    // CARD 2
    std::string card2;
    if (rank2 == 14)
        card2 = "Ace of ";
    else if (rank2 == 13)
        card2 = "King of ";
    else if (rank2 == 12)
        card2 = "Queen of ";
    else if (rank2 == 11)
        card2 = "Jack of ";
    else
        card2 = std::to_string(rank2) +  "of ";

    if (suit2 ==1)
        card2 += "Clubs";
    if (suit2 ==2)
        card2 += "Diamonds";
    if (suit2 ==3)
        card2 += "Hearts";
    if (suit2 ==4)
        card2 += "Spades";

    /*
    Step 4: Display Both Cards
    Output the full name of each card, like:
    "Player 1: Queen of Hearts"
    "Player 2: 10 of Spades"
    */

    std::cout << "Card 1: " << card1 << std::endl;
    std::cout << "Card 2: " << card2 << std::endl;

    /*
    Step 5: Compare the Ranks and Display the result
    Use if statements to compare the ranks of the two cards:
    If Player 1’s rank is higher → Player 1 wins
    If Player 2’s rank is higher → Player 2 wins
    If ranks are equal → It’s a tie
    */

    if (rank1>rank2)
        std::cout << "Winner: Card 1" << std::endl;
    else if (rank2 > rank1)
        std::cout << "Winner: Card 2" << std::endl;
    else
     std::cout << "Winner: TIED" << std::endl;

    return 0;
}
