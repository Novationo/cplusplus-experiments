/*
Name: Dylan Smith
Assignment Name:
Summary:
*/
#include <iostream>

int factorial (int n);
int main()
{
    // std::cout << recursiveSum() << std::endl;
    std::cout << factorial(5) << std::endl;
    return 0;
}
int factorial(int n){
    if (n==1)
        return 1;
    return n* factorial(n-1);

}
