#include <iostream>

int main() {
    int red;
    int green;
    int blue;
    int min = 0;

    std::cout << "Enter Red Value (0-255): " << std::endl;
    std::cin >>red;
    if (red < 0 || red >255){
        std::cout << "INPUT ERROR - Program Stop";
        return 1;
    }
    std::cout << "Enter Green Value (0-255): " << std::endl;
    std::cin >>green;
    if (green < 0 || green >255){
        std::cout << "INPUT ERROR - Program Stop";
        return 1;
    }
    std::cout << "Enter Blue Value (0-255): " << std::endl;
    std::cin >>blue;
    if (blue < 0 || blue >255){
        std::cout << "INPUT ERROR - Program Stop";
        return 1;
    }

    min = red;
    if (green < min) {
        min = green;
    }
    if (blue < min) {
        min = blue;
    }
    std::cout << min<<std::endl;

    red -= min;
    green -= min;
    blue -=min;

    std::cout << "RGB: (" << red << ", "<< green << ", "<< blue << ")" << std::endl;

    return 0;
}
