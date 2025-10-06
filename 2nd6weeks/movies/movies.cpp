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
   std::string oldTitle;
   // TODO write your code here
   for (int i = 0; i < movies.size(); i++){
      int firstComma = movies[i].find(",");
      int secondComma = movies[i].rfind(",");

      std::string time =movies[i].substr(0,firstComma);
      std::string rating = movies[i].substr(secondComma + 1);

      int titleLen = movies[i].size() -2 - time.size() - rating.size();
      std::string title = movies[i].substr(firstComma +1, titleLen);



      if(oldTitle != title){
      std::cout << "\n" << std::setw(44) <<std::left <<title.substr(0,44) << " | ";
      std::cout << std::setw(5) << std::right << rating << " | ";}
      std::cout << time << " ";
      oldTitle = title;
   }

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
