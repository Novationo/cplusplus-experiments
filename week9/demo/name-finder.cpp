/* Dylan Smith
Program Title: Class Session Name Finder
Program Summary: A program made to learn about sorting and io with text files
*/

#include <iostream>
#include <string>
#include <cctype> // toupper
#include <algorithm>
#include <vector>
#include <fstream>

int nameScore(const std::string& name);

int main() {
    int used = 0;
    std::vector<std::string> allNames;
    std::ifstream fin;

    fin.open("names.txt");

    if(!fin.is_open()){
        std::cout << "Error opening file for reading" << std::endl;
        return 2;
    }

    std::string name;
    while(std::getline(fin, name, ',')){
        name = name.substr(1, name.size() - 2);
        allNames.push_back(name);
        used++;
    }
    fin.close();

    // name entry
    std::cout << "Enter name to find: " << std::endl;
    std::string nameToFind;
    std::cin >> nameToFind;

    // searching
    bool found = false;
    for (int i = 0; i < allNames.size(); i++){
        std::string nameToCheck = allNames[i];

        if(nameToCheck == nameToFind){
            // Print the results: name was FOUND at #.
            // Removed tolower conversion to print the name as found in the file (uppercase).
            std::cout << nameToCheck << " was FOUND at " << i+1 << "." << std::endl;
            found = true;
            break;
        }
    }
    if (!found){ // not found
        std::cout << nameToFind << " was NOT found." << std::endl;
        return 1;
    }

    std::sort(allNames.begin(), allNames.end());

    int total = 0; // Changed to long long to prevent potential overflow
    for (int i = 0; i < allNames.size(); i++){
        // i+1
        total += (i+1) * nameScore(allNames[i]);
    }

    std::cout << "Total: " << total << std::endl;
    return 0;
}

int nameScore(const std::string& name) {
    int total = 0;
    for(char letter : name){
        total += (int)(toupper(letter)) - 64; // to make everything lowercase
    }
    return total;
}
