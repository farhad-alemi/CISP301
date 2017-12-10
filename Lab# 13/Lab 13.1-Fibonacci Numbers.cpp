// Program      :       Lab 13.1-Fibonacci Numbers.cpp
// Author       :       Farhad Alemi
// Due Date     :       November 30th, 2017
// Description  :       Write a program that creates an array of integers named
//                      fibnum, fills it with Fibonacci numbers (i.e., fibnum[0]
//                      is 0, fibnum[1] is 1, fibnum[2] is 1, fibnum[3] is 2, 
//                      fibnum[4] is 3, etc.), then displays the numbers on the screen.

#include <iostream>
#include <iomanip>
 
#define SIZE 47             // The size of the array

int main()
{
    int fibnum[SIZE],       // The array created for storing the Fibonacci numbers
        i;                  // The index number of the array

    // Initializing the first two elements
    fibnum[0] = 0;
    fibnum[1] = 1;

    // Computing Fibonacci Numbers
    for (i = 2; i < SIZE; i++)
    {
        fibnum[i] = (fibnum[i - 1] + fibnum[i - 2]);
    }


    // Output array values
    std::cout << "Index No.          Fibonacci Number" << std::endl;
    std::cout << "=========          ================" << std::endl;
    for (i = 0; i < SIZE; i++)
    { 
        std::cout << std::left << std::setw(19) << i << fibnum[i] << std::endl;
    }
    std::cout << std::endl;
}