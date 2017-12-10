// Program      :   Lab 10-1.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 24, 2017
// Description  :   This program calculates and displays the perimeter and area
//                  of a circle when the radius is input.

#include <iomanip>      // provides std::setprecision, std::setw
#include <iostream>     // provides std::cin, std::cout, std::endl,
                        // std::fixed

#define PI 3.14159      // it is an approximate value for PI

int main ()
{
    double radius,           // it is the radius input by the user
           perimeter,        // the perimiter of the circle
           area;             // the area of the circle

    // Input Section
    std::cout << "Please input the radius: ";
    std::cin >> radius;

    // Processing Section
    perimeter = 2 * PI * radius;
    area = PI * radius * radius;

    // Output Section
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "The perimeter of the circle is: " << perimeter << std::endl;
    std::cout << "The area of the circle is: " << area << std::endl;
}