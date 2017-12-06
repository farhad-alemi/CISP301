// Program      :   Lab# 14.cpp
// Author       :   Farhad Alemi
// Due Date     :   December 5, 2017
// Description  :   This program computes the weekly gross and net pay for an 
//                  employee. The inputs for the program are the employee’s name,
//                  number of hours worked, and hourly rate of pay. Assume that 
//                  deductions are taken for tax withholding (30% of gross pay).
//                  If the employee uses the parking garage, $10.00 is deducted
//                  from their weekly check and they cannot participate in the 
//                  transit program. If the employee participates in the transit
//                  program, $5.00 is deducted from their weekly check. If the 
//                  employee does neither, nothing additional is deducted from 
//                  their weekly check. The number of hours worked by an employee
//                  cannot be less than zero, or more than 60.0 hours; their hourly
//                  rate also cannot be less than zero, or more than $99.99. Regular
//                  hours are those worked up to and including the first 40 hours
//                  per week. Overtime hours are those worked in excess of the 
//                  first 40 hours per week. Gross pay is the sum of wages earned
//                  from regular hours and overtime hours; overtime is paid at 
//                  1.5 times the regular rate.

#include <iostream>         // provides std::cin, std::cout, std::fixed, std::endl
#include <iomanip>          // provides std::setprecision, std::setw
#include <string>           // provides std::string

#define TAX_RATE 0.30               // tax rate in decimal form
#define PARKING_FEES 10.00          // parking garage fees
#define TRANSIT_FEES 5.00           // transit fees
#define REGULAR_HOURS_LIMIT 40.00   // the limit for the regular hours
#define MAX_HOURS 60.00             // the number of maximum hours that an employee
                                    // can work
#define MAX_RATE 99.99              // maximum hourly rate
#define SIZE 20                     // the size of the array being used

void input_employee_data(std::string &full_name, double &hours, double &hourly_rate,
    double &deductions);
std::string join_name(std::string first_name, std::string last_name);
void split_hours(double hours, double &regular_hours, double &overtime_hours);
double calculate_gross_pay(double regular_hours, double overtime_hours, double
    hourly_rate);
double calculate_tax(double gross_pay, double tax_rate);
double calculate_net_pay(double gross_pay, double tax, double deductions);
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double
    deductions, double net_pay);
char get_yesno(std::string question);
double calculate_deductions();
double input_bounded_value(std::string description, double min_value, double max_value);

int main()
{
    std::string full_name,                // employee's full name in [last name,
                                          // first name] format
                description,              // the prompt displayed to the user
                employees_name[SIZE];     // the array for storing employees' names
    double      hours,                    // number of hours worked
                hourly_rate,              // the hourly rate of pay
                regular_hours,            // number of regular hours worked
                overtime_hours,           // number of overtime hours worked
                gross_pay,                // employee gross pay
                tax,                      // tax amount
                net_pay,                  // the net amount to be paid to the employee
                deductions,               // the amount to be deducted from employee's
                                          // paycheck
                total_gross_pay,          // the total gross pay calculated for 
                                          // all employees without using arrays
                employees_gross_pay[SIZE],// the array for storing employees' gross pays
                total_array_gross,        // the total gross pay calculated by 
                                          // using arrays
                min_gross_pay,            // minimum gross pay
                max_gross_pay;            // maximum gross pay
    char        answer;                   // the answer whether the user wants to 
                                          // rerun the program
    int         counter,                  // this variable counts the number of
                                          // employees processed
                i;                        // index number for the arrays

    // Welcome message
    std::cout << "Welcome to Payroll Calculator" << std::endl;
    std::cout << std::endl;
    
    // Initialization
    counter = 0;
    total_gross_pay = 0;
    total_array_gross = 0;
    
    do
    {
        input_employee_data(full_name, hours, hourly_rate, deductions);
        split_hours(hours, regular_hours, overtime_hours);
        gross_pay = calculate_gross_pay(regular_hours, overtime_hours, hourly_rate);
        tax = calculate_tax(gross_pay, TAX_RATE);
        net_pay = calculate_net_pay(gross_pay, tax, deductions);
        output_payroll_data(full_name, regular_hours, overtime_hours, hourly_rate,
            gross_pay, tax, deductions, net_pay);
        answer = get_yesno("Process another employee (Y/N)? ");
        std::cout << std::endl;
        employees_name[counter] = full_name;
        employees_gross_pay[counter] = gross_pay;
        counter = counter + 1;
        total_gross_pay = total_gross_pay + gross_pay;
    }
    while ((counter < SIZE) && (answer != 'n') && (answer != 'N'));
    std::cout << "Employees processed: " << counter << std::endl;
    std::cout << "Total gross pay: $" << total_gross_pay << std::endl;
    std::cout << std::endl << std::endl;

    // Table Output Section
    std::cout << "12345678901234567890##54321.00" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "   Employee Payroll Summary" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << std::endl;
    std::cout << "                      Gross" << std::endl;
    std::cout << "Name                  Pay" << std::endl;
    std::cout << "====================  ========" << std::endl;
    for (i=0; i < counter; i++)
    {
        std::cout << std::left << std::setw(20) << employees_name[i] << "  " 
            << std::right << std::setw(8) << employees_gross_pay[i] << std::endl;
    }
    std::cout << std::endl;
    for (i=0; i < counter; i++)
    {
        total_array_gross = total_array_gross + employees_gross_pay[i];
    }

    // Initialize minimum and maximum gross pays to those of the first employee
    max_gross_pay = employees_gross_pay[0];
    min_gross_pay = employees_gross_pay[0];

    for (i = 1; i < counter; i++)
    {
        if (employees_gross_pay[i] > max_gross_pay)
        {
            max_gross_pay = employees_gross_pay[i];
        }
        if (employees_gross_pay[i] < min_gross_pay)
        {
            min_gross_pay = employees_gross_pay[i];
        }
    }
    std::cout << "Total gross pay  : $" << std::setw(8) << total_array_gross
        << std::endl;
    std::cout << "Average gross pay: $" << std::setw(8) << (total_array_gross
        / counter) << std::endl;
    std::cout << "Minimum gross pay: $" << std::setw(8) << min_gross_pay << std::endl;
    std::cout << "Maximum gross pay: $" << std::setw(8) << max_gross_pay << std::endl;
    std::cout << std::endl;
}


//
// An input module that reads the employee's name, hours, and hourly pay rate 
// from the user. The module prompts the user to enter the employee's first and 
// last names, but provides a concatenated full name in the form “Last, First”.
//
void input_employee_data(std::string &full_name, double &hours, double &hourly_rate,
    double &deductions)
{
    std::string first_name, // employee's first name   
                last_name;  // employee's last name
    
    std::cout << "Enter employee's first name: ";
    std::cin >> first_name;
    std::cout << "Enter employee's last name: ";
    std::cin >> last_name;
    full_name = join_name(first_name, last_name);
    hours = input_bounded_value("number of hours worked", 0, MAX_HOURS);
    hourly_rate = input_bounded_value("hourly pay rate", 0, MAX_RATE);
    deductions = calculate_deductions();
}


//
// Full name concatenation
// A processing module that concatenates an employee's first and last names to a full
// name in the form "Last, First".
//
std::string join_name(std::string first_name, std::string last_name)
{
    std::string full_name;  // employee's full name in [Last name, First name] format
    full_name = last_name + ", " + first_name;
    return full_name;
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
double calculate_gross_pay(double regular_hours, double overtime_hours, double
    hourly_rate)
{
    double gross_pay;       // employee gross pay
    gross_pay = (regular_hours * hourly_rate) + (overtime_hours * hourly_rate * 1.5);
    return gross_pay;
}


//
// A processing module that calculates the tax on an employee's gross pay.
// (Note: A tax rate value must be passed into this module using the call).
//
double calculate_tax(double gross_pay, double tax_rate)
{
    double tax;             // tax amount
    tax = tax_rate * gross_pay;
    return tax;
}

//
// A processing module that calculates employee's net pay.
//
double calculate_net_pay (double gross_pay, double tax, double deductions)
{ 
    double net_pay;         // the net amount to be paid to the employee
    net_pay = gross_pay - tax - deductions;
    return net_pay;
}


//
// An output module that displays formatted payroll data for an employee,
// including headers.
//
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double
    deductions, double net_pay)
{
    std::cout << std::fixed << std::setprecision (2);
    std::cout << std::endl;
    std::cout << "                      Reg.   Ovt.   Hourly  Gross        " 
        << "             Net" << std::endl;
    std::cout << "Name                  Hours  Hours  Rate    Pay      Taxes " 
        << "   Deduct  Pay" << std::endl;
    std::cout << "====================  =====  =====  ======  =======  ======="
        << "  ======  =======" << std::endl;
    std::cout << std::left << std::setw(20) << full_name << "  " << std::right
        << std::setw(5) << regular_hours << "  " << std::setw (5) << overtime_hours 
        << "  " << std::setw(6) << hourly_rate << "  " << std::setw(7) << gross_pay 
        << "  " << std::setw(7) << tax << "  " << std::setw(6) << deductions 
        << "  " << std::setw(7) << net_pay << std::endl;
    std::cout << std::endl;
}


//
// An input module that prompts the user to answer a yes/no question, providing
// a validated answer via the out parameter.
//
char get_yesno(std::string question)
{
    char   answer;          // the answer whether the user wants to rerun the program
    std::cout << question;
    std::cin >> answer;
    while (answer != 'n' && answer != 'N' && answer != 'y' && 
        answer != 'Y')
    {
        std::cout << "Please type 'Y' for yes or 'N' for no" << std::endl;
        std::cout << std::endl;
        std::cout << question;
        std::cin >> answer;
    }
    return answer;
}


//
// This module calculates the amount of deductions based on employee's transport
// option
//
double calculate_deductions()
{
    double deductions;      // the amount to be deducted from employee's paycheck
    char   answer;          // the answer whether the user uses a certain type
                            // of transportation

    answer = get_yesno("Does the employee use the parking garage (Y/N)? ");
    if ((answer == 'Y') || (answer == 'y'))
    {
        deductions = PARKING_FEES;
    }
    else
    {
        answer = get_yesno("Does the employee participate in the transit progra"
           "m (Y/N)? ");
        if ((answer == 'Y') || (answer == 'y'))
        {
            deductions = TRANSIT_FEES;
        }
        else
        {
            deductions = 0.0;
        }
    }
    return deductions;
}


//
// An input module that reads a value from the user and validates that it is within
// a specific range. The user is prompted to enter a numeric value as described by
// the 'description' parameter (e.g., "number of hours worked"). Once the number 
// entered by the user is between 'min_value' and 'max_value', it is returned via 
// the 'value' parameter.
//
double input_bounded_value(std::string description, double min_value, double 
    max_value)
{
    double value;           // the validated user input (e.g., hours and hourly rate)
    std::cout << "Enter " << description << ": ";
    std::cin >> value;
    while (value < min_value || value > max_value)
    {
        std::cout << "The " << description << " must be between " << min_value << 
            " and " << max_value << std::endl;
        std::cout << std::endl;
        std::cout << "Enter " << description << ": ";
        std::cin >> value;
    }
    return value;
}