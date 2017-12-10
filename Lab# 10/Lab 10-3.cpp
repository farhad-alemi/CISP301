// Program      :   lab10-3.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 24, 2017
// Description  :   This program computes the sum, difference, product, 
//                  integer quotient, integer remainder, and floating-point
//                  quotient of the two inputs and displays them in a specific format.

#include <iomanip>          // provides std::setprecision, std::setw
#include <iostream>         // provides std::cin, std::cout, std::endl, std::fixed

int main()
{
    int first_integer,      // The first integer input by the user
        second_integer,     // The second integer input by the user
        sum,                // The sum of the two integers
        difference,         // The difference of the two integers
        product,            // the product of the two integers
        integer_quotient,   // The integer quotient of the two integers
        integer_remainder;  // The integer remainder of the two integers
    double float_quotient;  // The decimal quotient of the two integers

    // Input section
    std::cout << "Enter first integer: ";
    std::cin >> first_integer;
    std::cout << "Enter second integer: ";
    std::cin >> second_integer;

    // Processing section
    sum = first_integer + second_integer;
    difference = first_integer - second_integer;
    product = first_integer * second_integer;
    integer_quotient = first_integer / second_integer;
    integer_remainder = first_integer % second_integer;
    float_quotient = 1.0 * first_integer / second_integer;

    // Output section
    std::cout << std::fixed << std::setprecision(4);
    std::cout << first_integer << " + " << second_integer << " = " << sum 
        << std::endl;
    std::cout << first_integer << " - " << second_integer << " = " << difference
        << std::endl;
    std::cout << first_integer << " * " << second_integer << " = " << product
        << std::endl;
    std::cout << "[" << first_integer << " / " << second_integer << "]" 
        << " = " << integer_quotient << std::endl;
    std::cout << first_integer << " MOD " << second_integer << " = "
        << integer_remainder << std::endl;
    std::cout << first_integer << " / " << second_integer << " = " 
        << float_quotient << std::endl;
}