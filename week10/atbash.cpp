/*
https://www.101computing.net/atbash-cipher-algorithm/
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

std::string atBash(const std::string& message);

int main() {
  std::ofstream writeFS;
  std::string message = "Hello World!";

  std::string cipher = atBash(message);

  std::cout << "Message: " << message << "\n";
  std::cout << " Cipher: " << cipher << "\n\n";


  std::string message2;
  getline(std::cin, message2);
  cipher = atBash(message2);

  writeFS.open("secrets.txt");
  writeFS << cipher << std::endl;
  writeFS.close();


  return 0;
}



std::string atBash(const std::string& message) {
  std::string cipher;
  for(char c: message){ //cpp 11 warning
    int asciiC = c;
    char cipherC;
    if(isupper(c))
      cipherC = (25 - (asciiC - 65)) + 65;
    else if(islower(c))
      cipherC = (25 - (asciiC - 97)) + 97;
    else if(isdigit(c))
      cipherC = (9 - (asciiC - 48)) + 48;
    else
      cipherC = c;
    cipher += (char)cipherC;
  }
  return cipher;
}
