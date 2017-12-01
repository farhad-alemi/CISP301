// Program      :       Lab 13.2.cpp
// Author       :       Farhad Alemi
// Due Date     :       November 30th, 2017
// Description  :       The program asks the user to enter a number, then displays
//                      the message “Repeated digits!” if the number entered 
//                      contains one or more repeated digits. When there are no
//                      repeated digits, the program displays: "No repeated digits"

#include <iostream>
#define DIGITS 10               // number of Base 10 digits

int main()
{
    int number,                 // number input by the user
        digit,                  // digit of the number being processed
        digit_tally[DIGITS],    // tracks digits seen
        i,                      // general array-element counter
        count;                  // the number of repeated digits

    do
    {
        // Initialize digit tally to all zeroes, indicating that no
        // repeated digits have been found
        for (i = 0; i < DIGITS; i++)
        {
            digit_tally[i] = 0;
        }

        // Initialize the number of repeated digits
        count = 0;

        // Read a number from the user
        std::cout << "Enter a number (any negative number to exit): ";
        std::cin >> number;

        // Check for repeated digits
        while (number > 0)
        {
            digit = number % 10;
            digit_tally[digit] = digit_tally[digit] + 1;
            number = number / 10;            
        }

        // Count the number of repeated digits
        for (i = 0; i < DIGITS; i++)
        {
            if ((digit_tally[i] > 1))
                {
                    count = count + 1;
                }
        }

        // Output Repeated Digits
        if (count > 0)
        {
            std::cout << "Repeated Digits: ";
            for (i = 0; i < DIGITS; i++)
                {
                    if ((digit_tally[i] > 1))
                    {
                        std::cout << i << " ";
                    }
                }
        }
        else if (number == 0)
        {
            std::cout << "No Repeated Digits";
        }
        std::cout << std::endl;
    }
    while (number >= 0);
}