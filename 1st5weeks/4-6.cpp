/* Dylan Smith
Program Title: Week 4 Compilation Demo
Program Summary: whats broken? who knows, were trying to find that out in this one.
*/

#include <iostream>

int main() {
  int toysPerKid(int toys, int kids);
  int toys = 0;
  int kids = 0;


  std::cout << "Enter the number of toys: ";
  std::cin >> toys;

  std::cout << "Enter the number of kids: ";
  std::cin >> kids;
    if (kids > 0) {
        if(toys >= kids) {
            std::cout << "Each kid can have " << toysPerKid(toys, kids) << " toy(s)\n";
        } else {
            std::cout << "Not enough toys for each kid\n";
        }
        return 0;
    }
    else {
        std::cout << "Invalid number of kids - Kids must be greater than 0" << std::endl;
        return 1;
    }
}
    int toysPerKid(int toys, int kids) {
        return (toys / kids);
  }