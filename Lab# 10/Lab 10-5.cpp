// Program      :   lab10-5.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 24, 2017
// Description  :   This program converts a total number of seconds input by 
//                  the user into hours, minutes, and seconds.

#include <iostream>     // provides std::cin, std::cout, std::endl, std::fixed
#include <iomanip>      // provides std::setprecision, std::setw

int main()
{
    int tseconds,       // The total nuber of seconds input by the user
        hours,          // The total number of hours
        minutes,        // The total number of minutes
        seconds;        // The total number of seconds

    // Input section
    std::cout << "Enter the total seconds: ";
    std::cin >> tseconds;

    // Processing section
    hours = tseconds / 3600;
    minutes = (tseconds % 3600) / 60;
    seconds = (tseconds % 3600) % 60;

    // Output section
    std::cout << "Total Seconds: " << tseconds << std::endl;
    std::cout << "The total time is: " << hours << " hour(s), " << minutes 
        << " minute(s), and " << seconds << " second(s)." << std::endl;
}