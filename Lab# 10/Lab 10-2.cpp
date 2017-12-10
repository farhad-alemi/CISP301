// Program      :   lab10-2.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 24, 2017
//Description   :   This program computes and displays the amount of a 15%, 18%,
//                  and 20% tip when the price of a meal is input by the user.

#include <iomanip>              // provides std::setprecision, std::setw
#include <iostream>             // provides std::cin, std::cout, std::endl, 
                                // std::fixed

#define LOW_TIP_PERCENT 0.15    // Low tip percent
#define MEDIUM_TIP_PERCENT 0.18 // Medium tip percent
#define HIGH_TIP_PERCENT 0.20   // High tip percent

int main()
{
    double meal_price,          // the price of meal
           lowtip_amount,       // the amount of lowest tip
           mediumtip_amount,    // the amount of medium tip
           hightip_amount;      // the amount of high tip

    // Input Section
    std::cout << "Please input the meal price: "; 
    std::cin >> meal_price;

    // Processsing Section
    lowtip_amount = meal_price * LOW_TIP_PERCENT;
    mediumtip_amount = meal_price * MEDIUM_TIP_PERCENT;
    hightip_amount = meal_price * HIGH_TIP_PERCENT;

    // Output Section
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Meal Price        : $" << std::setw (9) << meal_price << std::endl;
    std::cout << "Low Tip Amount    : $" << std::setw (9) << lowtip_amount << " (%" 
        << (LOW_TIP_PERCENT * 100) << ")" << std::endl;
    std::cout << "Medium Tip Amount : $" << std::setw (9) << mediumtip_amount 
        << " (%" << (MEDIUM_TIP_PERCENT * 100) << ")" << std::endl;
    std::cout << "High Tip Amount   : $" << std::setw (9) << hightip_amount << " (%" 
        << (HIGH_TIP_PERCENT * 100) << ")" << std::endl;
}