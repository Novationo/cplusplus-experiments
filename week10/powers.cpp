/*
Name: Dylan Smith
Assignment Name: Simple Pythangorean Theorum Function Example
Summary: Uses a function and io of/to it to calculate the c value of a given pythagorean/ 90 degree triangle.
*/

#include <iostream>
#include <cmath> // for pow(), sqrt()

// technically should declare int pythan and after main put all of the below information
// int pythag(int a, int b);

int pythag(int a, int b){
    a = pow(a,2);
    b = pow(b,2);
    int c = sqrt(a+b);

    // alternatively
    // int c = pow(a,2) + pow(b,2);
    // return sqrt(c); // not implicit
    // c = sqrt(c)
    // return c;

    return c;
}

int main()
{
    int width, height;
    std::cin >> width >> height;

    std::cout << pythag(width,height) << std::endl;


    return 0;
}
