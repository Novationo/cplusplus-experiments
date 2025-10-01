#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

bool readMovieData(std::vector<std::string> & movies);

int main() {
   std::vector<std::string> movies;
   if( ! readMovieData(movies) ) {
      std::cout << "Program Abort\n";
      return -1;
   }

   // TODO write your code here

   std::cout << "\n\n";
   return 0;
}

bool readMovieData(std::vector<std::string> & movies) {
   std::cout << "Enter movie data file: ";
   std::string inputFileName;
   std::cin >> inputFileName;

   std::ifstream movieFS;
   movieFS.open(inputFileName);
   if (!movieFS.is_open()) {
      std::cout << "Could not open input file " << inputFileName << std::endl;
      return false;
   }

   std::string movieRecord;
   std::getline(movieFS >> std::ws, movieRecord);
   while(!movieFS.fail()) {
      movies.push_back(movieRecord);
      std::getline(movieFS >> std::ws, movieRecord);
   }

   if (!movieFS.eof()) {
      std::cout << "Input failure before reaching end of file." << std::endl;
      return false;
   }
   movieFS.close();
   return true;
}
