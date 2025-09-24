#include <iostream>
#include <iomanip>

int main() {
    double cost, paid;

    std::cout << "Enter Cost Amount $";
    std::cin >> cost;

    std::cout << "Enter Paid Amount $";
    std::cin >> paid;

    double change_due = paid - cost;

    if (change_due < 0) {
        std::cout << "\n*** Insufficient Funds ***" << std::endl;
        std::cout << "Remaining amount owed: $" << std::fixed << std::setprecision(2) << -change_due << std::endl;
        return 0;
    }

    // Convert to cents to handle floating-point precision issues
    int change_in_cents = static_cast<int>((change_due * 100) + 0.5); // Add 0.5 for rounding

    std::cout << "\nCHANGE DUE: $" << std::fixed << std::setprecision(2) << change_due << std::endl;

    int quarters = change_in_cents / 25;
    if (quarters > 0) {
        std::cout << "Quarters: " << quarters << std::endl;
        change_in_cents %= 25;
    }

    int dimes = change_in_cents / 10;
    if (dimes > 0) {
        std::cout << "Dimes: " << dimes << std::endl;
        change_in_cents %= 10;
    }

    int nickels = change_in_cents / 5;
    if (nickels > 0) {
        std::cout << "Nickels: " << nickels << std::endl;
        change_in_cents %= 5;
    }

    int pennies = change_in_cents / 1;
    if (pennies > 0) {
        std::cout << "Pennies: " << pennies << std::endl;
    }

    return 0;
}
