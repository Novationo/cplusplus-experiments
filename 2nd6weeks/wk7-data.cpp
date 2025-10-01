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
        inputNames.push_back(input.substr(0,locator));
        inputNums.push_back(input.substr(locator,(input.size()-1)));
        
        for(int i = 0; i < 10; i++){
            std::cout << inputNames[i] << std::endl;

        }

        for(int i = 0; i < 5; i++){ //edit number later
            int temp = 0;
            

        }
        // output thing before comma and after seperately as string, int


        //error checking
        //no comma, to many commas, comma not followed by int



        if (input == "-1"){
            collecting = false;
        }

    }









    return 0;
}