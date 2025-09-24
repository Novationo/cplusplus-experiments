/*
Name: Dylan Smith
Assignment Name: Parsing and Prompting
Summary:
*/
#include <iostream>
#include <string>

int main()
{
    std::string userIn;

    std::cout << "Enter input string: " << std::endl;
    std::getline(std::cin >> std::ws, userIn);

    while (userIn != "q") {

        int commaIndex = userIn.find(',');
        if(userIn == "q"){
            break;
        }
        if(commaIndex == std::string::npos){
            std::cout << "Error: No comma in string." << std::endl;
        }
        else{
            std::string word1 = userIn.substr(0,commaIndex);
            std::string word2 = userIn.substr(commaIndex + 1);
            std::cout << "First word: " << word1 << std::endl;
            std::cout << "Second word:" << word2 << std::endl;
        }
        std::cout << "Enter input string: " << std::endl;
        std::getline(std::cin >> std::ws, userIn);

    }


    return 0;
}
