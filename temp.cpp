#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Saturday {
   public:
      void SetWeather(string saturdayWeather);      
      void SetHumidity(double saturdayHumidity);      
      string GetWeather() const;     
      double GetHumidity() const;        
   private:
      string weather;
      double humidity;
};

void Saturday::SetWeather(string saturdayWeather) {
   weather = saturdayWeather;
}

void Saturday::SetHumidity(double saturdayHumidity) {
   humidity = saturdayHumidity;
}

Saturday::GetWeather() const{
   return weather;
   }
Saturday::GetHumidity() const{
   return humidity;
   }