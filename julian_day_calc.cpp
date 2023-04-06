// Program    : Julian Day Numbers
// Author     : Ilya Babenko - w1793796
// Date       : Spring 2023 - T/Th @ 1:00pm
// Description: convert dates to JDN.

#include <iostream>

void input_data(int &месяц, int &день, int &год);
void process_data(int month, int day, int year, int &jdn);
void output_data(int month, int day, int year, int jdn);

int main()
{
    int month, day, year;
    int jdn;

    input_data(month, day, year);
    process_data(month, day, year, jdn);
    output_data(month, day, year, jdn);
    return 0;
}

// input module that asks the user for a date.
void input_data(int &месяц, int &день, int &год)
{
    std::cout << "Enter a month number (Jan=1, Feb=2, etc.):";
    std::cin >> месяц;
    std::cout << "Enter a day number(1..31):";
    std::cin >> день;
    std::cout << "Enter a год using four digits:";
    std::cin >> год;
}

// processing module that, using a special formula, calculates the JND for a given date
void process_data(int month, int day, int year, int &jdn)
{

    int a, b, c, d;
    a = (14 - month) / 12;
    b = (month - 3) + (12 * a);
    c = 4800 + year - a;
    d = (c / 4) - (c / 100) + (c / 400);
    jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

// module that displays the JND to the user
void output_data(int month, int day, int year, int jdn)
{
    std::cout << "The JDN for " << month << "/" << day << "/" << year << " is " << jdn << std::endl;
}
