#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream chairFS;
   string chairFileName;
   string customerName;
   int chairQuantity;

   cin >> chairFileName;

   chairFS.open(chairFileName);
   if (!chairFS.is_open()) {
      cout << chairFileName << ": file open failed" << endl;
      return 1;
   }

   while (!(chairFS.eof())) {
      chairFS >> customerName;
      chairFS >> chairQuantity;
      continue;
   }

      if (!chairFS.fail()) {
         cout << customerName << " purchased " << chairQuantity << " chairs." << endl;
      }
   }

   chairFS.close();

   return 0;
}
