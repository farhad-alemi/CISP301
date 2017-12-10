// Program      :   Payroll.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 26th, 2017
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

void input_employee_data(std::string &full_name, double &hours, double &hourly_rate);
void join_name(std::string first_name, std::string last_name, std::string &full_name);
void split_hours(double hours, double &regular_hours, double &overtime_hours);
void calculate_gross_pay(double regular_hours, double overtime_hours, double
    hourly_rate, double &gross_pay);
void calculate_tax(double gross_pay, double tax_rate, double &tax);
void calculate_net_pay (double gross_pay, double tax, double deductions, double &net_pay);
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double deductions,
    double net_pay);
void get_yesno(std::string question, char &answer);

int main()
{
    std::string full_name,  // employee's full name in [Last name, First name] format
                question;   // The prompt whether the user wants to rerun the program
    double hours,           // number of hours worked
           hourly_rate,     // the hourly rate of pay
           regular_hours,   // number of regular hours worked
           overtime_hours,  // number of overtime hours worked
           gross_pay,       // employee gross pay
           tax,             // tax amount
           net_pay;         // the net amount to be paid to the emplyee
    char   answer;          // The answer whether the user wants to rerun the program

    // Welcome message
    std::cout << "Welcome to Payroll Calculator" << std::endl;
    std::cout << std::endl;

    do
    {
        input_employee_data(full_name, hours, hourly_rate);
        split_hours(hours, regular_hours, overtime_hours);
        calculate_gross_pay(regular_hours, overtime_hours, hourly_rate, gross_pay);
        calculate_tax(gross_pay, TAX_RATE, tax);
        calculate_net_pay(gross_pay, tax, PARKING_FEES, net_pay);
        output_payroll_data(full_name, regular_hours, overtime_hours, hourly_rate,
            gross_pay, tax, PARKING_FEES, net_pay);
        get_yesno(question, answer);
    }
    while (answer != 'n' && answer != 'N');
}


//
// An input module that reads the employee's name, hours, and hourly pay rate 
// from the user. The module prompts the user to enter the employee's first and 
// last names, but provides a concatenated full name in the form “Last, First”.
//
void input_employee_data(std::string &full_name, double &hours, double &hourly_rate)
{
    std::string first_name, // employee's first name   
                last_name;  // employee's last name
    
    std::cout << "Enter employee's first name: ";
    std::cin >> first_name;
    std::cout << "Enter employee's last name: ";
    std::cin >> last_name;
    join_name(first_name, last_name, full_name);
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
}


//
// Full name concatenation
// A processing module that concatenates an employee's first and last names to a full
// name in the form "Last, First".
//
void join_name(std::string first_name, std::string last_name, std::string &full_name)
{
    full_name = last_name + ", " + first_name;
}


//
// A processing module that splits the total number of hours worked by an 
// employee into regular and overtime hours.
//
void split_hours(double hours, double &regular_hours, double &overtime_hours)
{

    if (hours <= REGULAR_HOURS_LIMIT)
    {
        regular_hours = hours;
        overtime_hours = 0.0;
    }
    else
    {
        regular_hours = REGULAR_HOURS_LIMIT;
        overtime_hours = hours - REGULAR_HOURS_LIMIT;
    }
}


//
// A processing module that calculates an employee's gross pay, given the number
// of hours worked (regular and overtime) and hourly rate.
//
void calculate_gross_pay(double regular_hours, double overtime_hours, double
    hourly_rate, double &gross_pay)
{
    gross_pay = (regular_hours * hourly_rate) + (overtime_hours * hourly_rate * 1.5);
}


//
// A processing module that calculates the tax on an employee's gross pay.
// (Note: A tax rate value must be passed into this module using the call.
//
void calculate_tax(double gross_pay, double tax_rate, double &tax)
{
    tax = tax_rate * gross_pay;
}

//
//A processing module that calculates the tax on an employee's gross pay.
// (Note: A tax rate value must be passed into this module using the call.
//
void calculate_net_pay (double gross_pay, double tax, double deductions, double
    &net_pay)
{ 
    net_pay = gross_pay - tax - deductions;
}


//
// An output module that displays formatted payroll data for an employee,
// including headers.
//
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double deductions,
    double net_pay)
{
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
}


//
// An input module that prompts the user to answer a yes/no question, providing
//a validated 'Y' or 'N' (only) via the out parameter.
//
void get_yesno(std::string question, char &answer)
{
    std::cout << "Process another employee (Y/N)? ";
    std::cin >> answer;
    while (answer != 'n' && answer != 'N' && answer != 'y' && 
        answer != 'Y')
    {
        std::cout << "Please type 'Y' for yes or 'N' for no" << std::endl;
        std::cout << std::endl;
        std::cout << "Process another employee (Y/N)? ";
        std::cin >> answer;
    }
    std::cout << std::endl;
}