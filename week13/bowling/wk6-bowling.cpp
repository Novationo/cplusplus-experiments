/*
Name: Dylan Smith
Assignment Name: Going Bowling
Summary:
*/
#include <iostream>
#include <string>

int main()
{
    int throw1 = 0;
    int throw2 = 0;
    int remainder = 10;
    int attempt = 0;
    int attempt2 = 0;
    int throwSum;
    std::string score;

    //input validation
    do {
        std::cout << "Enter throw 1: ";
        std::cin >> throw1;

            if (throw1 >= 0 && throw1 <= 10) {
                if (throw1 == 10){
                    score = "X";
                    break;
                }
                break;
            }
            else {
                if (attempt < 2) {
                    std::cout << "Invalid throw 1 - retry" << std::endl;
                }
                attempt += 1;
            }

        } while (attempt < 3);

    if (attempt >= 3){
        std::cout << "Invalid bowling turn - program abort" << std::endl;
        return 1;
        exit;
    }

    remainder -= throw1;

    do {
        if (throw1 == 10){
            break;
        }
        std::cout << "Enter throw 2: ";
        std::cin >> throw2;

        throwSum = throw1 + throw2;

        if (throw2 >= 0 && throw2 <= remainder) {
            if (throwSum == 10) {
                score = "/";
                break;// how it wanted it in the example
            }
            if (throw1 < 10){
            score = std::to_string(throwSum);
            break;
            }
        }
        else {
            if (attempt2 < 2) {
                std::cout << "Invalid throw 2 - retry" << std::endl;
            }
            attempt2 += 1;
        }
        } while (attempt2 < 3);

    if (attempt2 >= 3){
        std::cout << "Invalid bowling turn - program abort" << std::endl;
        return 1;
        exit;
    }

    std::cout << "Frame: 1" << std::endl;

    if (throw1 == 10){
    std::cout << "Throw: " << throw1 << std::endl;
    }
    else {
    std::cout << "Throw: " << throw1 << " " << throw2 << std::endl;
    }

    std::cout << "Score: " << score << std::endl;

    return 0;
}
