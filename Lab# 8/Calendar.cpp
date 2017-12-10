// Program    : Calender.cpp
// Author     : Farhad Alemi
// Due Date   : October 10th, 2017
// Description: This program that displays a monthly calendar. The user should 
//              be prompted to input a month number (1 = January, 2 = February, etc.) 
//              and a four-digit year between 1800 and 2099. The program will 
//              then display a calendar for the user’s month.

#include <iostream>
#include <iomanip>
#include <string>

#define MIN_YEAR 1800
#define MAX_YEAR 2099
#define MONTHS_PER_YEAR 12
#define DAYS_PER_WEEK 7
#define SATURDAY 6

int main()
{
    int         month,      // month number
                year,       // year number between 1800 and 2099
                dow,        // day-of-the-week number
                jdn,        // Julian Calendar day number
                a,          // Intermediate variable used in JDN calculation
                m,          // Intermediate variable used in JDN calculation
                y,          // Intermediate variable used in JDN calculation
                leap_days,  // Intermediate variable used in JDN calculation
                day,        // day of the month
                days,       // Number of days in a month
                length,     // the length of the row in the output
                n;          // length-of-the-row number
    char        yesno,      // the answer whether the user wants to rerun the program
                symbol;     // the symbol used in creating a row
    bool        leap_year;  // determines whether it is a leap year or not
    std::string month_string;

    do
    {
        do
        {
            // Input section
            std::cout << "Enter a month number (1-12): ";
            std::cin >> month;
            if ((month < 1) || (month > 12))
            {
                std::cout << "Please enter a month from 1 to 12 (January=1, February=2, etc.)" << std::endl;
            }
        }
        while ((month < 1) || (month > 12));
        do
        {
            std::cout << "Enter a year (" << MIN_YEAR << "-" << MAX_YEAR << "): ";
            std::cin >> year;
            if ((year < MIN_YEAR) || (year > MAX_YEAR))
            {
                std::cout << "Please enter a four-digit year from " << MIN_YEAR << " to " << MAX_YEAR << std::endl;
            }
        }
        while ((year < MIN_YEAR) || (year > MAX_YEAR));

            // Horizontal Rule

                // Horizontal Line
                n = 1;
                length = 20;
                symbol = '=';
                while (n <= length)
                {
                    std::cout << symbol;
                    n = n+1;
                }

                // end_line
                std::cout << std::endl;

        // Calendar Header

            // get_month_string
            if (month == 1)
            {
                month_string = "January";
            }
            else if (month == 2)
            {
                month_string = "February";
            }
            else if (month == 3)
            {
                month_string = "March";
            }
            else if (month == 4)
            {
                month_string = "April";
            }
            else if (month == 5)
            {
                month_string = "May";
            }
            else if (month == 6)
            {
                month_string = "June";
            }
            else if (month == 7)
            {
                month_string = "July";
            }
            else if (month == 8)
            {
                month_string = "August";
            }
            else if (month == 9)
            {
                month_string = "September";
            }
            else if (month == 10)
            {
                month_string = "October";
            }
            else if (month == 11)
            {
                month_string = "November";
            }
            else
            {
                month_string = "December";
            }
        std::cout << month_string << " " << year << std::endl;
        
        // Horizontal Rule

                // Horizontal Line
                n = 1;
                length = 20;
                symbol = '=';
                while (n <= length)
                {
                    std::cout << symbol;
                    n = n+1;
                }

                // end_line
                std::cout << std::endl;
        // Calendar Body

            // DOW
                
                // JDN
                    day = 1;
                    a = ((14 - month) / 12);
                    m = (month - 3) + (12 * a);
                    y = year + 4800 - a;
                    leap_days = (y / 4) - (y / 100) + (y / 400);
                    jdn = (day + (((153 * m) + 2) / 5) + (365*y) + leap_days -32045);

                dow = (jdn + 1) % DAYS_PER_WEEK;

            // Get Month Days
                if (month == 2)
                {
                
                    // Leap Year
                      if ((year % 4) == 0)
                      {
                          if ((year % 100) == 0)
                          {
                            if ((year % 400) == 0)
                            {
                                leap_year = true;
                            }
                            else
                            {
                                leap_year = false;
                            }
                          }
                          else
                          {
                            leap_year = true;
                          }
                      }
                      else
                      {
                        leap_year = false;
                      }

                    if (leap_year == true)
                    {
                        days = 29;
                    }
                    else
                    {
                        days = 28;
                    }
                }
                else
                {
                    if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
                    {
                        days = 30;
                    }
                    else
                    {
                    days = 31;
                    }
                }

                // Horizontal Line
                n = 1;
                length = 3 * dow;
                symbol = ' ';

                while (n <= length)
                {
                    std::cout << symbol;
                    n = n+1;
                }

            day = 1;
            while (day <= days)
            {
                if (day < 10)
                {
                    std::cout << " " << day;
                }
                else
                {
                    std::cout << day;
                }
                if (dow == SATURDAY)
                {
                    if (day < days)
                    {
                        // end_line
                        std::cout << std::endl;
                    }
                }
                else
                {
                std::cout << " ";
                }
                day = day + 1;
                dow = ((dow + 1 ) % DAYS_PER_WEEK);
            }
                // end_line
                    std::cout << std::endl;
            // Horizontal Rule

                // Horizontal Line
                n = 1;
                length = 20;
                symbol = '=';
                while (n <= length)
                {
                    std::cout << symbol;
                    n = n+1;
                }

                // end_line
                std::cout << std::endl;

            //Play Again
                do
                {
                    std::cout << std::endl;
                    std::cout << "Display another calendar? ";
                    std::cin >> yesno;

                    //convert lower-case to upper-case
                    if (yesno == 'y')
                    {
                        yesno = 'Y';
                    }
                    else if (yesno == 'n')
                    {
                        yesno = 'N';
                    }
                    if (yesno != 'Y' && yesno != 'N')
                    {
                        std::cout << "Please enter 'Y' for yes or 'N' for no" << std::endl;
                    }
                }
                while (yesno!= 'Y' && yesno != 'N');
    }
    while (yesno != 'N');
}