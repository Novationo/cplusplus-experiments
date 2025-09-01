/*
Dylan Smith
Program Title: Meters to MPH
Program Summary: to demonstrate my understanding of advanced text output and arithmetic in c++.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    double raceTime; // time in seconds
    double speedMPH; 
    const double KM_PER_MI = 1.61;
    const double M_PER_KM = 1000.0;
    const double SEC_PER_HR = 3600.0;
    const double DISTANCE = 100.0; // distance in meters
    double testMPH;

    std::cout << "Enter Race Time: " << std::endl;
    std::cin >> raceTime;

    // testMPH = (100.0 / raceTime) * 3600.0 / 1.61 / 1000.0; // seconds, km, meter
    speedMPH = (DISTANCE / raceTime) * SEC_PER_HR / KM_PER_MI / M_PER_KM;
    
    std::cout << "Summary "<< DISTANCE << "-meter Dash" << std::endl;
    std::cout << "  Race Time: " << std::fixed << std::setprecision(2) << raceTime << " seconds" << std::endl;
    std::cout << "  Average Speed in MPH: " << std::fixed << std::setprecision(2) << speedMPH << "mph" << std::endl;

    // std::cout << "  Average Speed in MPH: " << std::fixed << std::setprecision(2) << testMPH << "mph" << std::endl;
    return 0;
    
}