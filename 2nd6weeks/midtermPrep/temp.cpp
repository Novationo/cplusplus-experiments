/*
Name: Dylan Smith
Assignment Name:
Summary:
*/
#include <iostream>
#include <iomanip>
#include <string>
// using namespace std;

int main()
{
    // double mod = 66 % 60;

    // bool thing = (true && (-5 != 0 || !(false)));
    // bool thing = (true && (4/3 != 0 || !(6)));
    // std::cout << thing << std::endl;

    // int num1 = -1;
    // int num2 = 0;

    // while(num1 < 3)
    // {
    //    num2 += 2;
    //    ++num1;
    // }
    // std::cout << num2 << std::endl;
    //
    // int x = -1;
    // int y = 0;

    // while(x < 3)
    // {
    //    y += 2;
    //    x++;
    // }
    // std::cout << y << std::endl;

    // double num = 3 / 5.0 + 4 / 5 + 2.0;
    // std::cout << num << std::endl;

    // if (6 < 8) {
    //     std::cout << "**" << std::endl;
    //     std::cout << "****" << std::endl;
    // } else if (9 != 4)
    //     std::cout << "***" << std::endl;
    //     std::cout << "*" << std::endl;
    //
    // int num = 8;

    // if (num > 8)
    // {
    //     std::cout << " ** " << std::endl ;
    //     std::cout << "****" << std::endl;
    // }
    // else if (num != 4)
    //     std::cout << "***" << std::endl;
    // else
    //     std::cout << "*" << std::endl;
    //
    //
    for(int i=0; i<4; ++i) {
       for(int j=0; j<3; ++j) {
          if(i == 2){
            std::cout << i << std::endl;
            break;
          }
        std::cout << i << std::endl;
       }
        std::cout << i << std::endl;
    }

    return 0;
}
