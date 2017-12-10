// Program      :   lab10-4.cpp
// Autho        :   Farhad Alemi
// Due Date     :   October 24, 2017
// Description  :   This program converts a temperature input in degrees
//                  Celsius to degrees Fahrenheit and Kelvins, and displays all
//                  three values.

#include <iomanip>      // provides std::setprecision, std::setw
#include <iostream>     // provides std::cin, std::cout, std::endl, 
                        //   std::fixed

int main()
{
    double celsius,     // The tempretaure input in degrees Celsius
           fahrenheit,  // The temperature in degrees Fahrenheit
           kelvin;      // The tempreture in Kelvins

    // Input section
    std::cout << "Enter temperature in degrees Celsius: ";
    std::cin >> celsius;

    // Processing section
    fahrenheit = ((9.0 / 5.) * celsius) + 32;
    kelvin = celsius + 273.15;

    // Output section
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Temperature in degrees Celsius    : " << std::setw(6) 
        << 1.0 * celsius << std::endl;
    std::cout << "Temperature in degrees Fahrenheit : " << std::setw(6) 
        << fahrenheit << std::endl;
    std::cout << "Temperature in Kelvins            : " << std::setw(6) 
        << kelvin << std::endl;
}