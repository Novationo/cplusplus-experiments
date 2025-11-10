#include <iostream>
#include <string>
using namespace std;

class Animal {
   public:
      Animal();
      Animal(string animalType);
      void Print();

   private:
      string type;
};

// Default constructor
Animal::Animal() {
   type = "Undefined";
}

Animal::Animal(string animalType){
      type = animalType;
   }


void Animal::Print() {
   cout << "Animal: " << type << endl;
}

int main() {
   string animalType;

   cin >> animalType;

   Animal emptyAnimal;
   Animal animal1(animalType);

   emptyAnimal.Print();
   animal1.Print();

   return 0;
}
