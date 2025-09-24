#include <iostream>

using namespace std;

int main(){
    cout << "Hello, Enter a letter: ";
    char letter;
    cin >> letter;
    cout << "Letter + 1 Was: " << letter + 1 << "\n";
    // This will output the ASCII value of the letter + 1
    cout << (char)(letter) << " + 1";




    return 0;
}