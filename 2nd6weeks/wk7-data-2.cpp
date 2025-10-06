#include <iostream>
/*
Dylan Smith
Program Title: Data Visualization 
Program Summary: get a bunch of stuff from your user and output it into a pretty graph that splits your data into its name and respective data. 
*/

#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

int main() {
    std::string dataTitle, columnOne, columnTwo;
    std::string userInput, nameStr, numberStr;
    std::vector<std::string> stringData;
    std::vector<int> intData;
    bool collecting = true;

    // first inputs
    std::cout << "Enter a title for the data:" << std::endl;
    std::getline(std::cin, dataTitle); 
    std::cout << "You entered: " << dataTitle << std::endl;

    std::cout << "Enter the column 1 header:" << std::endl;
    std::getline(std::cin, columnOne);
    std::cout << "You entered: " << columnOne << std::endl;

    std::cout << "Enter the column 2 header:" << std::endl;
    std::getline(std::cin, columnTwo);
    std::cout << "You entered: " << columnTwo << std::endl;

    // data collection
    while (collecting) {
        std::cout << "Enter a data point (-1 to stop input):" << std::endl;
        std::getline(std::cin, userInput);

        if (userInput == "-1") {
            collecting = false;
            break;
        }

        // input validation
        int commaPosition = userInput.find(',');
        if (commaPosition == std::string::npos) {
            std::cout << "Error: No comma in string." << std::endl;
            continue;
        }

        if (userInput.rfind(',') != commaPosition) {
            std::cout << "Error: Too many commas in input." << std::endl;
            continue;
        }

        
        nameStr = userInput.substr(0, commaPosition);
        numberStr = userInput.substr(commaPosition + 1);

        // string whitesapce
        int firstChar = nameStr.find_first_not_of(" \t");
        if (firstChar == std::string::npos) { 
             nameStr = "";
        } else {
             int lastChar = nameStr.find_last_not_of(" \t");
             nameStr = nameStr.substr(firstChar, (lastChar - firstChar + 1));
        }

        firstChar = numberStr.find_first_not_of(" \t");
        if (firstChar == std::string::npos) {
            numberStr = "";
        } else {
            int lastChar = numberStr.find_last_not_of(" \t");
            numberStr = numberStr.substr(firstChar, (lastChar - firstChar + 1));
        }
        
        // input validation
        bool validInt = !numberStr.empty(); 
        for (char c : numberStr) {
            if (!std::isdigit(c)) {
                validInt = false;
                break;
            }
        }

        if (!validInt) {
            std::cout << "Error: Comma not followed by an integer." << std::endl;
            continue;
        }

        int dataInteger = std::stoi(numberStr);

        
        stringData.push_back(nameStr);
        intData.push_back(dataInteger);
        std::cout << "Data string: " << nameStr << std::endl;
        std::cout << "Data integer: " << dataInteger << std::endl;
    }

    std::cout << std::endl;

    // output
    std::cout << std::right << std::setw(33) << dataTitle << std::endl;
    std::cout << std::left << std::setw(20) << columnOne << "|  " << columnTwo << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < stringData.size(); ++i) {
        std::cout << std::left << std::setw(20) << stringData[i] << "|"
                  << std::right << std::setw(23) << intData[i] << std::endl;
    }

    std::cout << std::endl;

    
    for (int i = 0; i < stringData.size(); ++i) {
        std::cout << std::right << std::setw(20) << stringData[i] << " ";
        for (int j = 0; j < intData[i]; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
https://cplusplus.com/reference/string/string/find_first_not_of/
https://cplusplus.com/reference/cctype/
*/