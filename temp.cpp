#include <iostream>
#include <vector>
using namespace std;

int main() {
   int row;
   int col;

   for(row = 2; row <= 3; row = row + 1) {
      for(col = 0; col <= 1; col = col + 1) {
         cout << row << col << " ";
      }
   }

   return 0;
}
