// Program      :   Lab# 15.cpp
// Author       :   Farhad Alemi
// Due Date     :   December 8, 2017
// Description  :   This program computes the weekly gross and net pay for an 
//                  employee. The inputs for the program are the employee’s name,
//                  number of hours worked, hourly rate of pay, and deductions.
//                  The inputs are provided by an input file stream. Outputs are
//                  a text file and an HTML file. Regular hours are those worked
//                  up to and including the first 40 hours per week. Overtime  
//                  hours are those worked in excess of the first 40 hours per week.
//                  Gross pay is the sum of wages earned from regular hours and
//                  1.5 times the regular rate.

#include <iostream>         // provides std::cin, std::cout, std::fixed, std::endl
#include <iomanip>          // provides std::setprecision, std::setw
#include <string>           // provides std::string
#include <cstdlib>          // provides exit
#include <fstream>          // provides std::ofstream, std::ifstream

#define TAX_RATE 0.30               // tax rate in decimal form
#define REGULAR_HOURS_LIMIT 40.00   // the limit for the regular hours
#define SIZE 20                     // the size of the arrays being used

void input_employee_data(std::string &full_name, double &hours, double &hourly_rate,
    double &deductions, std::ifstream &input_file);
std::string join_name(std::string first_name, std::string last_name);
void split_hours(double hours, double &regular_hours, double &overtime_hours);
double calculate_gross_pay(double regular_hours, double overtime_hours, double
    hourly_rate);
double calculate_tax(double gross_pay, double tax_rate);
double calculate_net_pay(double gross_pay, double tax, double deductions);
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double
    deductions, double net_pay, std::ofstream &output_file, std::ofstream &summary);
void sort_employees(std::string employees_name[], double employees_gross_pay[],
    int counter);

int main()
{
    std::string   full_name,                // employee's full name in [last name,
                                            // first name] format
                  employees_name[SIZE];     // the array for storing employees' names
    double        hours,                    // number of hours worked
                  hourly_rate,              // the hourly rate of pay
                  regular_hours,            // number of regular hours worked
                  overtime_hours,           // number of overtime hours worked
                  gross_pay,                // employee gross pay
                  tax,                      // tax amount
                  net_pay,                  // the net amount to be paid to the employee
                  deductions,               // the amount to be deducted from 
                                            // employee's paycheck
                  total_gross_pay,          // the total gross pay calculated for 
                                            // all employees without using arrays
                  employees_gross_pay[SIZE],// the array for storing employees' gross pays
                  total_array_gross,        // the total gross pay calculated by 
                                            // using arrays
                  min_gross_pay,            // minimum gross pay
                  max_gross_pay,            // maximum gross pay
                  avg_gross_pay;            // the average gross pay among all employees
    int           counter,                  // the number of employees processed
                  i;                        // index number for the arrays
    std::ifstream input_file;               // input stream for reading from a file
    std::ofstream output_file,              // output stream for writing to a text file
                  summary;                  // output stream for writing to an HTML file


    // Check whether input and output files can be opened
    input_file.open("c:\\temp\\empdata.txt");
    if (!input_file.is_open())
    {
        std::cout << "Cannot open input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    output_file.open("c:\\temp\\report.txt");
    if (!output_file.is_open())
    {
        std::cout << "Cannot open text output file" << std::endl;
        exit(EXIT_FAILURE);
    }
    summary.open("c:\\temp\\summary.html");
    if (!summary.is_open())
    {
        std::cout << "Cannot open HTML output file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Initialization
    counter = 0;
    total_gross_pay = 0;
    total_array_gross = 0;

    // Text file header
    output_file << std::fixed << std::setprecision (2);
    output_file << "                      Reg.   Ovt.   Hourly  Gross        " 
        << "             Net" << std::endl;
    output_file << "Name                  Hours  Hours  Rate    Pay      Taxes " 
        << "   Deduct  Pay" << std::endl;
    output_file << "====================  =====  =====  ======  =======  ======="
        << "  ======  =======" << std::endl;

    // HTML file header
    summary << std::fixed << std::setprecision (2);
    summary << "<!doctype html>" << std::endl;
    summary << "<html lang='en'>" << std::endl;
    summary << "<head>" << std::endl;
    summary << "    <meta charset='utf_8'/>" << std::endl;
    summary << "    <title>Payroll</title>" << std::endl;
    summary << "    <style>" << std::endl;
    summary << "        table, th, td { border: 1px solid black }" << std::endl;
    summary << "        th, td { padding: 5px }" << std::endl;
    summary << "        th { text-align: left }" << std::endl;
    summary << "        td { text-align: right }" << std::endl;
    summary << "    </style>" <<std::endl;
    summary << "</head>" << std::endl;
    summary << "<body>" << std::endl;
    summary << "    <h1>Employee Payroll</h1>" << std::endl;
    summary << "    <table>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Name</th>" << std::endl;
    summary << "            <th>Regular Hours</th>" << std::endl;
    summary << "            <th>Overtime Hours</th>" << std::endl;
    summary << "            <th>Hourly Rate</th>" << std::endl;
    summary << "            <th>Gross Pay</th>" << std::endl;
    summary << "            <th>Taxes</th>" << std::endl;
    summary << "            <th>Deductions</th>" << std::endl;
    summary << "            <th>Net Pay</th>" << std::endl;
    summary << "        </tr>" << std::endl;
    
    // Reading first line of data
    input_employee_data(full_name, hours, hourly_rate, deductions, input_file);

    while ((counter < SIZE) && (!input_file.eof()))
    {
        split_hours(hours, regular_hours, overtime_hours);
        gross_pay = calculate_gross_pay(regular_hours, overtime_hours, hourly_rate);
        tax = calculate_tax(gross_pay, TAX_RATE);
        net_pay = calculate_net_pay(gross_pay, tax, deductions);
        output_payroll_data(full_name, regular_hours, overtime_hours, hourly_rate,
            gross_pay, tax, deductions, net_pay, output_file, summary);
        employees_name[counter] = full_name;
        employees_gross_pay[counter] = gross_pay;
        counter = counter + 1;
        total_gross_pay = total_gross_pay + gross_pay;
        input_employee_data(full_name, hours, hourly_rate, deductions, input_file);
    }

    // Screen display summary
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Employees processed: " << counter << std::endl;
    std::cout << "Total gross pay: $" << total_gross_pay << std::endl;
    std::cout << std::endl;

    // Text file output section
    output_file << std::endl << std::endl;
    output_file << "==============================" << std::endl;
    output_file << "   Employee Payroll Summary" << std::endl;
    output_file << "==============================" << std::endl;
    output_file << std::endl;
    output_file << "                      Gross" << std::endl;
    output_file << "Name                  Pay" << std::endl;
    output_file << "====================  ========" << std::endl;

    // HTML output section
    summary << "    </table>" << std::endl;
    summary << "    </br>" << std::endl;
    summary << "    </br>" << std::endl;
    summary << "    <h2>Employee Payroll Summary</h2>" << std::endl;
    summary << "    <table>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Name</th>" << std::endl;
    summary << "            <th>Gross Pay</th>" << std::endl;
    summary << "        </tr>" << std::endl;
    
    // Call to sorting procedure
    sort_employees(employees_name, employees_gross_pay, counter);

    for (i=0; i < counter; i++)
    {
        output_file << std::left << std::setw(20) << employees_name[i] << "  " 
            << std::right << std::setw(8) << employees_gross_pay[i] << std::endl;
        summary << "        <tr>" << std::endl;
        summary << "            <td style='text-align: left'>" << employees_name[i]
            << "</td>" << std::endl;
        summary << "            <td>$ " << employees_gross_pay[i] << "</td>"
            << std::endl;
        summary << "        </tr>" << std::endl;
    }
    output_file << std::endl;
    summary << "    </table>" << std::endl;
    summary << "    </br>" << std::endl;
    for (i=0; i < counter; i++)
    {
        total_array_gross = total_array_gross + employees_gross_pay[i];
    }

    // Initialize minimum and maximum gross pays to those of the first employee
    if (counter != 0)
    {
        max_gross_pay = employees_gross_pay[0];
        min_gross_pay = employees_gross_pay[0];
        avg_gross_pay = total_array_gross / counter;
    }
    else
    {
        max_gross_pay = 0;
        min_gross_pay = 0;
        avg_gross_pay = 0;
    }
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

    // Text output file summary
    output_file << "Total gross pay  : $" << std::setw(8) << total_array_gross
        << std::endl;
    output_file << "Average gross pay: $" << std::setw(8) << avg_gross_pay
        << std::endl;
    output_file << "Minimum gross pay: $" << std::setw(8) << min_gross_pay
        << std::endl;
    output_file << "Maximum gross pay: $" << std::setw(8) << max_gross_pay
        << std::endl;

    // HTML output file summary
    summary << "    <table>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Total Gross Pay</th>" << std::endl;
    summary << "            <td>$ " << total_array_gross << "</td>" << std::endl;
    summary << "        </tr>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Average Gross Pay</th>" << std::endl;
    summary << "            <td>$ " << avg_gross_pay << "</td>" << std::endl;
    summary << "        </tr>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Minimum Gross Pay</th>" << std::endl;
    summary << "            <td>$ " << min_gross_pay << "</td>" << std::endl;
    summary << "        </tr>" << std::endl;
    summary << "        <tr>" << std::endl;
    summary << "            <th>Maximum Gross Pay</th>" << std::endl;
    summary << "            <td>$ " << max_gross_pay << "</td>" << std::endl;
    summary << "        </tr>" << std::endl;
    summary << "    </table>" << std::endl;

    // Closing HTML tags
    summary << "</body>" << std::endl;
    summary << "</html>" << std::endl;

    // Closing file streams
    input_file.close();
    output_file.close();
    summary.close();
}


//
// An input module that reads the employee's name, hours, hourly pay rate and 
// deductions from the input file. The module reads the first and last names
// separately but provides a concatenated full name in the form “last, first”.
//
void input_employee_data(std::string &full_name, double &hours, double &hourly_rate, 
    double &deductions, std::ifstream &input_file)
{
    std::string first_name, // employee's first name   
                last_name;  // employee's last name

    input_file >> first_name >> last_name >> hours >> hourly_rate >> deductions;
    full_name = join_name(first_name, last_name);
}


//
// Full name concatenation
// A processing module that concatenates an employee's first and last names to
// a full name in the form "last, first".
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
double calculate_net_pay(double gross_pay, double tax, double deductions)
{ 
    double net_pay;         // the net amount to be paid to the employee
    net_pay = gross_pay - tax - deductions;
    return net_pay;
}


//
// An output module that displays formatted payroll data for an employee.
//
void output_payroll_data(std::string full_name, double regular_hours, double
    overtime_hours, double hourly_rate, double gross_pay, double tax, double
    deductions, double net_pay, std::ofstream &output_file, std::ofstream &summary)
{
    // Text file output
    output_file << std::left << std::setw(20) << full_name << "  " << std::right
    << std::setw(5) << regular_hours << "  " << std::setw (5) << overtime_hours 
    << "  " << std::setw(6) << hourly_rate << "  " << std::setw(7) << gross_pay 
    << "  " << std::setw(7) << tax << "  " << std::setw(6) << deductions 
    << "  " << std::setw(7) << net_pay << std::endl;

    // HTML file output
    summary << "        <tr>" << std::endl;
    summary << "            <td style='text-align: left'>" << full_name << "</td>"
        << std::endl;
    summary << "            <td>" << regular_hours << "</td>" << std::endl;
    summary << "            <td>" << overtime_hours << "</td>" << std::endl;
    summary << "            <td>" << hourly_rate << "</td>" << std::endl;
    summary << "            <td>" << gross_pay << "</td>" << std::endl;
    summary << "            <td>" << tax << "</td>" << std::endl;
    summary << "            <td>" << deductions << "</td>" << std::endl;
    summary << "            <td>" << net_pay << "</td>" << std::endl;
    summary << "        </tr>" << std::endl;
}


// This procedure sorts the data in the "Employee Payroll Summary" table in 
// descending order based on employees' gross pay
//
void sort_employees(std::string employees_name[], double employees_gross_pay[],
    int counter)
{
    int         i,                  // general counter for comparing adjacent 
                                    // elements
                pass;               // pass counter
    bool        swaps;              // denotes if the elements were swapped 
                                    // during a pass
    std::string temp_name;          // facilitates the swapping of adjacent names
    double      temp_gross;         // facilitates the swapping of adjacent gross pays

    swaps = true;
    for (pass = 1; (pass < counter) && swaps; pass++)
    {
        swaps = false;

        for (i = 0; i < (counter - pass); i++)
        {
            if (employees_gross_pay[i] < employees_gross_pay[i+1])
            {
                temp_name = employees_name[i];
                temp_gross = employees_gross_pay[i];
                employees_name[i] = employees_name[i+1];
                employees_gross_pay[i] = employees_gross_pay[i+1];
                employees_name[i+1] = temp_name;
                employees_gross_pay[i+1] = temp_gross;

                swaps = true;
            }
        }
    }
}