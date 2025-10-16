#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream dataFS;
   string fileName;
   int line1;
   int line2;
   int line3;
   int line4;
   int line5;

   cin >> fileName;
   cin >> line1;
   cin >> line2;
   cin >> line3;
   cin >> line4;
   cin >> line5;

   dataFS.open(fileName);

   if(!dataFS.is_open()){
      cout << fileName << ": file-open operation failure" << endl;
   }
   else {
      dataFS << "* " << line1 << " *" << endl;
      dataFS << "* " << line2 << " *" << endl;
      dataFS << "* " << line3 << " *" << endl;
      dataFS << "* " << line4 << " *" << endl;
      dataFS << "* " << line5 << " *" << endl;

   }


   if (dataFS.is_open()) {  /* For testing purpose only */
      dataFS << "File is not closed." << endl;
   }

   return 0;
}
