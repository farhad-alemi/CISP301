// Program      :      Lab 13.3.cpp
// Author       :      Farhad Alemi
// Due Date     :      November 30, 2017
// Description  :      This program asks the user to enter a number, then displays
//                     the number of times each digit appears in the number

#include <iostream>
#include <iomanip>

#define SIZE 10         // number of base-10 digits

int main()
{
    int i,              // index number for the array
        n[SIZE],        // the array in which the number of repeated digits
                        // is stored
        digit,          // the digit being processed
        number;         // the number input by the user

    do
    {
        // Array initialization
        for (i = 0; i < SIZE; i++)
        {
            n[i] = 0;
        }

        // Input Section
        std::cout << "Enter a number (any negative number to exit): ";
        std::cin >> number;

        // check number of repeated digits
        if (number != 0)
        {
            while (number > 0)
            {
                digit = number % 10;
                n[digit] = n[digit] + 1;
                number = number / 10;
            }
        }
        else
        {
            n[0] = 1;
        }
        
        // Output Section
        if (number >= 0)
        {
            std::cout << "Digit:  ";
            for (i = 0; i < SIZE; i++)
            {
                std::cout << i << "  ";
            }
            std::cout << std::endl << "Count:  ";
            for (i = 0; i < SIZE; i++)
            {
                std::cout << n[i] << "  ";
            }
            std::cout << std::endl << std::endl;
        }
    }
    while (number >= 0);
}