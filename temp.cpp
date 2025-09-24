#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> intValues;
   intValues.push_back(4);
   intValues.push_back(5);
   intValues.push_back(1);
   intValues.push_back(2);
   intValues.push_back(3);

   for (int &currVal : intValues) {
      currVal += 2;
   }

   for (int intVal : intValues) {
      cout << intVal << endl;
   }
}
