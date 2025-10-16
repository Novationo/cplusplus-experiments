#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
// #include <stdexcept> // for stod?

int main()
{
    std::string gemstone;
    std::cout << "Enter the name of the stolen gemstone: ";
    std::getline(std::cin >> std::ws, gemstone);

    std::cout << "Enter the location of the stolen " << gemstone << ": ";
    std::string location;
    std::getline(std::cin >> std::ws, location);

    std::cout << "\n\n";

    std::ifstream in; //creates object
    in.open("suspects.csv"); // opens specific ifle
    if(!in.is_open()) { // can also do !in, !in.good(), !in.fail()
        std::cout << "Error - file not found\n";
        return 2;
    }

    std::string id, title, firstname, lastname, gender, nationality, phone, height, shoesize;
    std::string vegetarian, vegan, staff, guest, team;

    std::string record;
    std::getline(in >> std::ws, record); //reading file until end of file

    while(std::getline(in >> std::ws, record)) {
        std::istringstream ss(record);
        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, firstname, ',');
        std::getline(ss, lastname, ',');
        std::getline(ss, gender, ',');
        std::getline(ss, nationality, ',');
        std::getline(ss, phone, ',');
        std::getline(ss, height, ',');
        std::getline(ss, shoesize, ',');
        std::getline(ss, vegetarian, ',');
        std::getline(ss, vegan, ',');
        std::getline(ss, staff, ',');
        std::getline(ss, guest, ',');
        std::getline(ss, team, '\n');

        if((gemstone == "Ruby") && gender == "Male" && shoesize == "10.5" && staff == "FALSE" && guest == "TRUE") {
            break;
        }
        else if((gemstone == "Sapphire") && firstname[0] == 'A' && !lastname.empty() && lastname[0] == 'H'){
            break;
        }
        else if(gemstone == "Onyx" && gender == "Female" && staff == "TRUE" && team == "Security"){
            break;
        }
        else if(gemstone == "Topaz" && (std::stod(height) >= 1.85) && gender == "Female"){
            break;
        }
        else if(gemstone == "Diamond" && (nationality == "China" || nationality == "Taiwan" || nationality == "Singapore")){
            break;
        }
        else if(gemstone == "Tanzanite" && gender == "Male" && (firstname.substr(0, 3) == "Oli" || lastname.substr(0, 3) == "Oli")){
            break;
        }
        else if(gemstone == "Pink Sapphire" && guest == "TRUE" && vegan == "TRUE" && (nationality == "American" || nationality == "Canadian" || nationality == "English" || nationality == "Australian")){
            break;
        }
        else if(gemstone == "Quartz" && vegetarian == "FALSE" && vegan == "FALSE" && nationality == "Denmark"){
            break;
        }
        else if(gemstone == "Emerald" && gender == "Female" && nationality == "France" && staff == "FALSE" && guest == "TRUE"){
            break;
        }
        else if(gemstone == "Amber" && gender == "Female" && (std::stod(shoesize) >= 6 && std::stod(shoesize) <= 7) && (nationality == "Peru" || nationality == "Chile" || nationality == "Argentina" || nationality == "Brazil" || nationality == "Venezuela")){
            break;
        }
        else if(gemstone == "Peridot" && gender == "Female" && guest == "TRUE" && nationality == "Ireland"){
            break;
        }
        else if(gemstone == "Amethyst" && (std::stod(height) >= 1.7 && std::stod(height) <= 1.8)
        && gender == "Male" && staff == "TRUE" && team == "Gardening"){
            break;
        }

    }

    in.close(); // close file/access

    std::cout << firstname + " " + lastname << " stole the " << gemstone << " from the " << location << ".\n";
    std::cout << "\n\n";
    return 0;
}
