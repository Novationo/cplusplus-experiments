#include <iostream>
#include <string>
using namespace std;

class Animal {
   public:
      Animal();
      Animal(string animalType);
      Animal(string animalType, string animalColor, int animalAge);
      void Print();

   private:
      string type;
      string color;
      int age;
};

// Default constructor
Animal::Animal() {
   type = "Unknown";
   color = "None";
   age = -1;
}

Animal::Animal(string animalType) {
   type = animalType;
   color = "None";
   age = -1;
}

Animal::Animal(string animalType, string animalColor, int animalAge) {
   type = animalType;
   color = animalColor;
   age = animalAge;
}

void Animal::Print() {
   cout << "Animal: " << type << ", " << color << ", " << age << endl;
}

int main() {
   string animalType;
   string animalColor;
   int animalAge;

   cin >> animalType;
   cin >> animalColor;
   cin >> animalAge;

// thing to make it work
   Animal animal1;
   Animal animal2(animalType);
   Animal animal3(animalType,animalColor,animalAge);
//

   animal1.Print();
   animal2.Print();
   animal3.Print();

   return 0;
}
