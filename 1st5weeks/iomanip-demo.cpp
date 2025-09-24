#include <iostream>
#include <iomanip>
#include <string>

int main(){
    std::string month;
    std::string day;
    std::string year;

    std::cout << "Date:" << std::setw(2) << std::setfill('0') << month;
    std::cout << "Date:" << std::setw(2) << std::setfill('0') << day;
    std::cout << "Date:" << std::setw(2) << std::setfill('0') << year;

}
