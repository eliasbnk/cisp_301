// Program    : Digit Sum
// Author     : Ilya Babenko
// Date       : Spring 2023
// Description: This program extracts place values from a given whole number.

#include <iostream>
#include <iomanip>

void input_data(int &whole_number);
void perform_calculations(int whole_number, int &ones, int &tens, int &hundreds, int &thousands, int &total);
void output_results(int whole_number, int ones, int tens, int hundreds, int thousands, int total);

int main()
{
    int ones, tens, hundreds, thousands, total;
    int whole_number;
    input_data(whole_number);
    perform_calculations(whole_number, ones, tens,
                         hundreds, thousands, total);
    output_results(whole_number, ones, tens, hundreds,
                   thousands, total);
    return 0;
}

//
// An input module that recieves the total amount user has.
//

void input_data(int &whole_number)
{
    std::cout << "Enter a whole number (0-9999): ";
    std::cin >> whole_number;
};

//
// A processing module that computes the minimum amount of dollar bills and coins required to make the given total.
//

void perform_calculations(int whole_number, int &ones, int &tens, int &hundreds, int &thousands, int &total)
{

    int rth, rh, rt, ro;
    rth = whole_number % 1000;
    thousands = (whole_number - rth) / 1000;
    rh = rth % 100;
    hundreds = (rth - rh) / 100;
    rt = rh % 10;
    tens = (rh - rt) / 10;
    ro = rt % 1;
    ones = (rt - ro) / 1;
    total = thousands + hundreds + tens + ones;
};

//
// An output module that displays to the user the computed amount of dollar bills and coins required to make the given total.
//

void output_results(int whole_number, int ones, int tens, int hundreds, int thousands, int total)
{
    std::cout << "Ones digit : " << ones << std::endl;
    std::cout << "Tens digit : " << tens << std::endl;
    std::cout << "Hundreds digit : " << hundreds << std::endl;
    std::cout << "Thousands digit : " << thousands << std::endl;
    std::cout << std::endl;
    std::cout << "The sum of the digits in the number " << whole_number << " is " << total << std::endl;
};
