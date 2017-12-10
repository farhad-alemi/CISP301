// Program      :   Payroll.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 26, 2017
// Description  :   This program computes the weekly gross and net pay for an 
//                  employee. The inputs for the program are the employee’s name,
//                  number of hours worked, and hourly rate of pay. Assume that 
//                  deductions are taken for tax withholding (30% of gross pay)
//                  and parking ($10 per week). The number of hours worked by an
//                  employee cannot be less than zero, or more than 60.0 hours;
//                  their hourly rate also cannot be less than zero, or more 
//                  than $99.99. Regular hours are those worked up to and including
//                  the first 40 hours per week. Overtime hours are those worked
//                  in excess of the first 40 hours per week. Gross pay is the 
//                  sum of wages earned from regular hours and overtime hours;
//                  overtime is paid at 1.5 times the regular rate.

#include <iostream>         // provides std::cin, std::cout, std::fixed, std::endl
#include <iomanip>          // provides std::setprecision, std:setw
#include <string>           // provides std::string

#define TAX_RATE 0.30
#define PARKING_FEES 10.00
#define REGULAR_HOURS_LIMIT 40.00
#define MAX_HOURS_LIMIT 60.00
#define MAX_HOURLY_RATE 99.99

int main()
{
    std::string first_name, // employee's first name   
                last_name,  // employee's last name
                full_name;  // employee's full name in [Last name, First name] format
    double hours,           // number of hours worked
           hourly_rate,     // the hourly rate of pay
           regular_hours,   // number of regular hours worked
           overtime_hours,  // number of overtime hours worked
           gross_pay,       // employee gross pay
           tax,             // tax amount
           net_pay;         // the net amount to be paid to the emplyee
    char   run_again;       // The answer whether the user wants to rerun the program

    // Welcome message
    std::cout << "Welcome to Payroll Calculator" << std::endl;
    std::cout << std::endl;

    // Input section
    do
    {
        std::cout << "Enter employee's first name: ";
        std::cin >> first_name;
        std::cout << "Enter employee's last name: ";
        std::cin >> last_name;
        std::cout << "Enter number of hours worked: ";
        std::cin >> hours;
        while (hours < 0 || hours > MAX_HOURS_LIMIT)
        {
            std::cout << "The number of hours worked must be between 0.00 and "
                << MAX_HOURS_LIMIT << std::endl;
            std::cout << std::endl;
            std::cout << "Enter number of hours worked: ";
            std::cin >> hours;
        }
        std::cout << "Enter hourly pay rate: ";
        std::cin >> hourly_rate;
        while (hourly_rate < 0 || hourly_rate > MAX_HOURLY_RATE)
        {
            std::cout << "The hourly rate must be between 0.00 and " 
                << MAX_HOURLY_RATE << std::endl;
            std::cout << std::endl;
            std::cout << "Enter hourly rate: ";
            std::cin >> hourly_rate;
        }

        // Full name concatenation
        full_name = last_name + ", " + first_name;

        // Overtime calculation
        if (hours <= REGULAR_HOURS_LIMIT)
        {
            regular_hours = 1.0 * hours;
            overtime_hours = 0.0;
        }
        else
        {
            regular_hours = REGULAR_HOURS_LIMIT;
            overtime_hours = hours - REGULAR_HOURS_LIMIT;
        }

        // Processing section
        gross_pay = (regular_hours * hourly_rate) + (overtime_hours * hourly_rate * 1.5);
        tax = TAX_RATE * gross_pay;
        net_pay = gross_pay - tax - PARKING_FEES;

        // Output section
        std::cout << std::fixed << std::setprecision (2);
        std::cout << std::endl;
        std::cout << "12345678901234567890##21.00##21.00##321.00##4321.00##321." 
            << "00##321.00##4321.00" << std::endl;
        std::cout << "                      Reg.   Ovt.   Hourly  Gross        " 
            << "            Net" << std::endl;
        std::cout << "Name                  Hours  Hours  Rate    Pay      Taxes" 
            << "   Deduct  Pay" << std::endl;
        std::cout << "====================  =====  =====  ======  =======  ======"
            << "  ======  =======" << std::endl;
        std::cout << std::left << std::setw(20) << full_name << "  " << std::right
            << std::setw(5) << regular_hours << "  " << std::setw (5) << overtime_hours 
            << "  " << std::setw(6) << hourly_rate << "  " << std::setw(7) << gross_pay 
            << "  " << std::setw(6) << tax << "  " << std::setw(6) << PARKING_FEES 
            << "  " << std::setw(7) << net_pay << std::endl;
        std::cout << std::endl;
        
        // Run-Again section
        std::cout << "Process another employee (Y/N)? ";
        std::cin >> run_again;
        while (run_again != 'n' && run_again != 'N' && run_again != 'y' && 
            run_again != 'Y')
        {
            std::cout << "Please type 'Y' for yes or 'N' for no" << std::endl;
            std::cout << std::endl;
            std::cout << "Process another employee (Y/N)? ";
            std::cin >> run_again;
        }
        std::cout << std::endl;
    }
    while (run_again != 'n' && run_again != 'N');
}