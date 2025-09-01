#include <iostream>

/*
Dylan Smith
Program Title: 2.17 Assignment
Program Summary: Printing ASCII Emotes
*/

/* dont use this !
using namespace std; */

int main(){
    std::cout << "   *" << std::endl;
    std::cout << "  ***" << std::endl;
    std::cout << " *****" << std::endl;
    std::cout << "*******" << std::endl;
    std::cout << "  ***" << std::string(1, '\n') << std::string(2,'\n');

    std::cout << "/\\   /\\"  << std::endl;
    std::cout << "  o o" << std::endl;
    std::cout << " =   =" << std::endl;
    std::cout << "  ---" << std::endl;

    return 0;
}