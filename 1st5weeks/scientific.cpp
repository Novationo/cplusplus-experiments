#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat;

   myFloat = 50.8423;

   cout << scientific << setprecision(3) << myFloat;

   return 0;
}