#include <iostream>
#include <string>

int main(){
    // std::string dolphin = "DOLPHIN"; // hardcoded
    // std::string wolf = "WOLF"; // hardcoded
    std::string first;
    std::string second;

    std::cout << "Enter First Animal: ";
    std::cin >> first;
    std::cout << "Enter Second Animal: ";
    std::cin >> second;

    // std::cout << wolf.substr(0,3) << dolphin.substr(3,4) << std::endl; // hardcoded
    std::cout << first.substr(0,3) << second.substr((second.length() - 4), 4) << std::endl;
}
