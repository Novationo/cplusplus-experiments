#include <iostream>
#include <iomanip>    // For setprecision
#include <vector> 
#include <cstdlib>


int main() {
   std::vector<double> vectorWeight;
    double numWeight;

   for(int i=0; i < 5; i++){
        std::cout << "Enter weight " << i+1 << ":" << std::endl;
        std::cin >> numWeight;
        vectorWeight.push_back(numWeight);

   }

   std::cout << std::fixed << std::setprecision(2) << "You entered: ";
   for(int i =0; i < 5; i++){
   std::cout << vectorWeight[i] << " ";
   }
   std::cout << std::endl;


   double totalWeight = 0;
   for(int i = 0; i < vectorWeight.size(); i++){
     //    std::cout << vectorWeight[i] << " ";
        totalWeight += vectorWeight[i];
   }

   std::cout << "\nTotal weight: " << totalWeight << std::endl;


   if(vectorWeight.size()>0){
    double average = totalWeight / vectorWeight.size();
    std::cout << "Average weight: " << average << std::endl;
   }

     if (vectorWeight.size() > 0) {
          double maxWeight = vectorWeight[0];
          
          for (size_t i = 1; i < vectorWeight.size(); ++i) {
               if (vectorWeight[i] > maxWeight) {
                    maxWeight = vectorWeight[i];
               }
          }
          std::cout << "Max weight: " << maxWeight << std::endl;
     }

   return 0;
}