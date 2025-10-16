#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int main() {

    std::cout << "Enter total number of days: ";
    int days = 0;
    std::cin >> days;

    std::stringstream ss;
    std::string strMoney;

    double money = .01;

    for(int dayCount = 2; dayCount <= days; dayCount++)
        money *= 2;

    ss << std::fixed << std::showpoint << std::setprecision(2); // to_string wouldnt work and apply these flags
    ss << money;

    ss >> strMoney;

    int index = strMoney.find('.');
    while (index > 0){
        strMoney.insert(index, 1, ',');
        index -= 3;

    }



    std::cout << "\nA Penny doubled for " << days << " days: $" << strMoney;



    std::cout <<"\n\n";
    return 0;
}
