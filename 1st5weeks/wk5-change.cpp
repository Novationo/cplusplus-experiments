/*
 *Dylan Smith
 * Change Counting Program
 * A Program that tells you the amout of each type of coin you need to give someone their change.
 */

#include <iostream>
#include <iomanip>


int main()
{
    double cost;
    double paid;
    double change;

    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    bool counting = 1;

    std::cout << "Enter Cost Amount $" << std::endl;
    std::cin >> cost;
    std::cout << "Enter Paid Amount $" << std::endl;
    std::cin >> paid;

    change = paid - cost;

    // test line to see stored amounts
    //std:: cout << cost << std::endl << paid << std::endl << change << std::endl;

std::cout << "CHANGE DUE: $" << change << std::endl;

if (change < 0){
    std::cout << "*** Insufficient Funds ***" << std::endl;
    std::cout << "Amount Owed $" << (change * -1) << std::endl;
    return 1;
}

while (change >= 1.00){
    change -= 1.0;
    dollars +=1;
}
while (change >= .25){
    change -= .25;
    quarters += 1;
}
while (change >= .10){
    change -= .10;
    dimes += 1;
}
while (change >= .05){
    change -= .05;
    nickels += 1;
}
while (change >= 0.0){
    change -= .01;
    pennies += 1;
}
if (change == 0.0){
    counting = 0;
    return 0;
}

std::cout << "Dollars: " << dollars << std::endl;
std::cout << "Quarters: " << quarters << std::endl;
std::cout << "Dimes: " << dimes << std::endl;
std::cout << "Nickels: " << nickels << std::endl;
std::cout << "Pennies: " << pennies << std::endl;



    return 0;
}
