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
    int throwSum;
    std::string score;

    //input validation
    do {
        std::cout << "Throw 1: ";
        std::cin >> throw1;
        attempt += 1;

        if (throw1 >= 0 && throw1 <= 10) {
            if (throw1 == 10){
                score = "X";
                break;
            }
            break;
        }
        else {
            std::cout << "Invalid throw 1 - retry" << std::endl;
        }

        } while (attempt < 3);

    if (attempt >= 3){
        std::cout << "Invalid bowling turn - program abort" << std::endl;
        return 1;
    }


    // score calculation
    while (throw1 >= 0 && throw1 <=10){
        if (throw1 == 10){
            score = "X";
            break;
        }
        else if (throwSum == 10 && throw1 < 10){
            score = "/";
            break;
        }
        else if (throw1 < 10){
            throwSum = throw1 + throw2;
            //score = std::to_string(throwCombined);

        }
    }
    //end
    std::cout << "Frame: 1" << std::endl;
    std::cout << "Throw: " << throw1 << " " << throw2 << std::endl;
    std::cout << "Score: " << score << std::endl;

    return 0;
}
