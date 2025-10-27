/*
 * Dylan Smith
 * Cryptography Encoding/Decoding
 * the purpose is to use functions to encode/decode a cryptographic message and challenge the learner (me) to rewrite code
 * from one language into another.
 */


#include <iostream>
#include <string>
#include <cstdlib> // srand and rand
#include <type_traits>

std::string encrypt(std::string input, int cryptKey);
std::string decrypt(std::string cipher, int cryptKey);


int main() {
    srand(23); // the seed value cannot be changed for the auto tests to pass
    std::string plaintext;
    int key;
    std::cout << "Enter a message to encrypt (plaintext) " << std::endl;
    //std::cin >> plaintext;
    std::getline(std::cin, plaintext);

    std::cout << "Input a key as a number between 1 and 10" << std::endl;
    std::cin >> key;

    std::cout << "Encrypting plaintext..." << std::endl;

    std::string ciphertext = encrypt(plaintext, key);

    std::cout << "Encrypted text: " << std::endl;
    std::cout << ciphertext << std::endl;

    std::cout << "Decrypting ciphertext..." << std::endl;
    std::cout << "Decrypted text: " << decrypt(ciphertext, key) << std::endl;
    /* Python Code - main program
    # Input...
    plaintext = input("Enter a message to encrypt (plaintext)")
    key = int(input("Input a key as a number between 1 and 10"))
    # Process...
    print("Encrypting plaintext...\n")
    ciphertext = encrypt(plaintext, key)
    # Output...
    print("Encrypted text: ")
    print(ciphertext)
    */

    std::cout << "\n\n";
    return 0;
}
/* Python Code: Encryption Function
# A basic encryption algorithm
# (Code as C++ and then review to reverse-engineer)
def encrypt(plaintext, key):
  alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
  ciphertext = ""
  for i in range(0,len(plaintext)):
    ciphertext = ciphertext + plaintext[i]
    for j in range (0,key):
      ciphertext = ciphertext + alphabet[randrange(0, len(alphabet))]
  return ciphertext
*/

std::string encrypt(std::string input, int cryptKey){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string ciphertext = "";

    for(int i=0; i < input.size(); i++){
        ciphertext = ciphertext + input[i];
        for(int i = 0; i < cryptKey; i++){
            ciphertext = ciphertext + alphabet[rand() % alphabet.size()];

        }
    }
    return ciphertext;
}

std::string decrypt(std::string cipher, int cryptKey){
    std::string decrypted = "";
    int step = cryptKey + 1;

        for (int i = 0; i < cipher.size(); i += step) {

            if (i < cipher.size()) {
                decrypted += cipher[i];
            }

        }

        return decrypted;


    return decrypted;
}
