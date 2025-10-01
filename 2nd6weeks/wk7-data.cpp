/*
Dylan Smith
Program Title: Data Visualization 
Program Summary: 
*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<cctype>

int main(){
    std::string title, column1, column2, input;
    std::vector<std::string> inputNames;
    std::vector<std::string> inputNums;
    std::vector<int> actualNums;
    bool collecting = true;


    // title input
    std::cout << "Enter a title for the data: ";
    std::cin >> title;
    std::cout << "You entered: " << title << std::endl;

    // coloum inputs
    std::cout << "Enter the column 1 header: ";
    std::cin >> column1;
    std::cout << "You entered: " << column1 << std::endl;

    std::cout << "Enter the column 2 header: ";
    std::cin >> column2;
    std::cout << "You entered: " << column2 << std::endl;

    // data collection
    while(collecting){
        std::cout << "Enter a data point (-1 to stop input)" << std::endl;
        std::cin >> input;

        int locator = input.find(",");
        int locator2 = input.rfind(",");
        inputNames.push_back(input.substr(0,locator));
        inputNums.push_back(input.substr(locator,(input.size()-1)));

        // if locator is invalid
        if (locator == std::string::npos){
            std::cout << "Error: No comma in string." << std::endl;
            continue;
        }
        if (locator != locator2){
            std::cout << "Error: Too many commas in input." << std::endl;
            continue;             
        }

        // for / if there are to many commas (how, do i need another loop?)



        // for / if there is no int at the end of input for inputNums. 
        for(int i = 0; i < inputNums.size(); i++){
            if(isdigit(std::stoi(inputNums[i])) == true){
                continue;
            }
            else{
                std::cout << "Error: not an integer" << std::endl;
            }
        }


        if (input == "-1"){
            collecting = false;
        }

    }

    for(int i = 0; i < 10; i++){
        std::cout << inputNames[i] << std::endl;

        
    }
    
    for(int i = 0; i < inputNames.size(); i++){ //edit number later
        int temp = 0;
        

    }
    
    // output thing before comma and after seperately as string, int
    //no comma, to many commas, comma not followed by int


    // table printing

    std::cout << std::right << std::setw(33) << title << std::endl;
    std::cout << std::left << std::setw(20) << column1 << "| " << std::left << std::setw(23) << column2 << std::endl;

    std::cout << std::left << std::setw(20) << std::string(20, "-") << "| " << std::left << std::string(23, "-") << std::endl;



    for (int i = 0; i < inputNames.size(); ++i) {
        std::cout << std::right << std::setw(20) << inputNames[i] << " ";

        for (int i = 0; i < inputNums[i]; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;

    


    return 0;
}