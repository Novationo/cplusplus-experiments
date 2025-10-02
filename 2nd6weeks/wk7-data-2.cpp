/*
Dylan Smith
Program Title: Data Visualization 
Program Summary: get a bunch of stuff from your user and output it into a pretty graph that splits your data into its name and respective data. 
*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<cctype> // havent learned about but was helpful

// i got stuck trying to figure out how to solve this
std::string trim(const std::string& str) {
    // Find the first non-space character
    int first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return ""; // The string is empty or all spaces
    }
    int last = str.find_last_not_of(' ');


    return str.substr(first, (last - first + 1));
}


int main(){
    std::string title, column1, column2, input, nameStr, numStr;
    std::vector<std::string> inputNames;
    std::vector<int> actualNums;
    bool collecting = true;
        
    // on learn cpp it mentioned std::cin.sync() for getline might not need

    std::cout << "Enter a title for the data: " << std::endl;
    std::getline(std::cin, title);
    std::cout << "You entered: " << title << std::endl;

    std::cout << "Enter the column 1 header: " << std::endl;
    std::getline(std::cin, column1);
    std::cout << "You entered: " << column1 << std::endl;

    std::cout << "Enter the column 2 header: " << std::endl;
    std::getline(std::cin, column2);
    std::cout << "You entered: " << column2 << std::endl;

    while(collecting){
        std::cout << "Enter a data point (-1 to stop input):" << std::endl;
        std::getline(std::cin, input);

        if (input == "-1"){
            collecting = false;
            break;
        }

        int locator = input.find(",");
        int locator2 = input.rfind(","); //rfind seems really useful

        if (locator == std::string::npos){
            std::cout << "Error: No comma in string." << std::endl;
            continue;
        }

        if (locator != locator2){
            std::cout << "Error: Too many commas in input." << std::endl;
            continue;             
        }
        
        nameStr = input.substr(0, locator);
        numStr = input.substr(locator + 1);

        nameStr = trim(nameStr);
        numStr = trim(numStr);
        

    //error things
        bool is_valid_int = true;
        if (numStr.empty()) {
            is_valid_int = false;
        } else {
            // check to see if digit
            for (char c : numStr) {
                if (!std::isdigit(c)) {
                    is_valid_int = false;
                    break;
                }
            }
        }
        
        if (!is_valid_int){
            std::cout << "Error: Comma not followed by an integer." << std::endl;
            continue;
        }

        int dataNum = 0;
        // remembered this from python i still dont really get it
        try {
            dataNum = std::stoi(numStr);
        } catch (const std::exception& e) {
            std::cout << "Error: Comma not followed by an integer." << std::endl;
            continue;
        }
        
        inputNames.push_back(nameStr);
        actualNums.push_back(dataNum);

        std::cout << "Data string: " << nameStr << std::endl;
        std::cout << "Data integer: " << dataNum << std::endl;
    }

    std::cout << std::endl;
    
    //output data    
    std::cout << std::right << std::setw(33) << title << std::endl;
    
    std::cout << std::left << std::setw(20) << column1 << "|    " << column2 << std::endl;

    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < inputNames.size(); ++i) {
        std::cout << std::left << std::setw(20) << inputNames[i] << "|";
        std::cout << std::right << std::setw(23) << actualNums[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < inputNames.size(); ++i) {
        std::cout << std::right << std::setw(20) << inputNames[i] << " ";

        for (int j = 0; j < actualNums[i]; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}