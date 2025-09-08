/* Dylan Smith
Title: Secret ID Generator
Summary: breaks apart two strings and turns it into a username you can use  
*/

#include <iostream>
#include <string>

int main() {
	std::string fullName;
    std::string pin;
    std::string finalID;
    std::string lastName;
    int lastLength;
    std::string firstName;

    std::cout << "Enter first and last name: ";
    //std::cin >> fullName;
    getline(std::cin,fullName);
    std::cout << "Enter a 4-digit number: ";
    std::cin >> pin;

    size_t spaceIndex = fullName.find(' ');
    firstName = fullName.substr(0, spaceIndex);

    lastName = fullName.substr(spaceIndex + 1);
    char lastInitial = lastName.at(0);

    finalID = firstName.substr(0,6) + lastInitial + std::to_string(lastLength) + pin.at(3);

    std::cout << finalID << std::endl;
    std::cout << fullName;

	return 0;
}