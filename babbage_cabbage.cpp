/*
Program Name: Babbage's Cabbage's
Author: Ilya Babenko - w1793796
Date: 04/01/2023 - T/Th @ 1pm
Description: This program calculates the gross pay, taxes,
and net pay for an employee based on their hours worked and
hourly pay rate. It also includes a parking fee deduction.
*/

#include <iostream>
#include <iomanip>
#include <string>

#define MIN_PAY_RATE 7.25
#define MAX_PAY_RATE 44.99
#define MIN_WORK_HOURS 20
#define REG_HOURS_CUTOFF 40
#define OVERTIME_HOURS_CUTOFF 60
#define OVERTIME_PAY_RATE 1.5
#define TAX_RATE 0.28
#define PARKING_FEE 7.50

// Module for getting the partial name of an employee
void input_partial_name(std::string label, std::string &name)
{
    std::cout << "Enter employee's " + label + " name: ";
    std::cin >> name;
};

// Module for joining the first and last names of an employee
void join_names(std::string first_name, std::string last_name, std::string &full_name)
{
    full_name = last_name + ", " + first_name;
};

void split_hours(double hours, double &regular_hours, double &overtime_hours)
{
    if (hours <= REG_HOURS_CUTOFF)
    {
        regular_hours = hours;
        overtime_hours = 0;
    }
    else
    {
        regular_hours = REG_HOURS_CUTOFF;
        overtime_hours = hours - REG_HOURS_CUTOFF;
    };
};

// Module for calculating gross pay
void calc_gross_pay(double regular_hours, double overtime_hours, double hourly_rate,
                    double &gross_pay)
{
    gross_pay = (regular_hours * hourly_rate) +
                (overtime_hours * (hourly_rate * OVERTIME_PAY_RATE));
};

void calc_taxes(double gross_pay, double &taxes)
{
    taxes = TAX_RATE * gross_pay;
};

// Module for calculating net pay and tax withholdings
void calc_net_pay(double gross_pay, double &net_pay, double taxes)
{
    net_pay = gross_pay - taxes - PARKING_FEE;
};

// Module for outputting employee information
void output(std::string full_name, double regular_hours, double overtime_hours,
            double hourly_rate, double gross_pay, double taxes, double net_pay)
{
    std::cout << std::endl;

    std::cout << "                      Reg    Ovt    Hourly  Gross                    Net"
              << std::endl;

    std::cout << "Name                  Hours  Hours  Rate    Pay      Taxes   Deduct  Pay"
              << std::endl;

    std::cout << "====================  =====  =====  ======  =======  ======  ======  ======="
              << std::endl;

    std::cout << std::left << std::setw(20)
              << full_name << "  "
              << std::right << std::fixed
              << std::setprecision(2)
              << std::setw(5) << regular_hours << "  " << std::setw(5)
              << overtime_hours << "  " << std::setw(6)
              << hourly_rate << "  " << std::setw(7)
              << gross_pay << "  "
              << std::setw(6) << taxes << "  "
              << std::setw(6)
              << PARKING_FEE << "  " << std::setw(7)
              << net_pay << std::endl;
};

void input_bounded_value(std::string description, double min_value, double max_value, double &value)
{
    do
    {
        std::cout << "Enter " << description << ": ";
        std::cin >> value;

        if (value < min_value || value > max_value)
        {
            std::cout << "The " << description
                      << " must be between "
                      << min_value << " and " << max_value << "." << std::endl;
            std::cout << std::endl;
        }

    } while (value < min_value || value > max_value);
};

// Module for getting input from the user
void input(std::string &full_name, double &hours, double &hourly_rate)
{

    std::string first_name, last_name;

    input_partial_name("first", first_name);

    input_partial_name("last", last_name);

    join_names(first_name, last_name, full_name);

    input_bounded_value(
        "number of hours worked",
        MIN_WORK_HOURS,
        OVERTIME_HOURS_CUTOFF,
        hours);

    input_bounded_value(
        "hourly pay rate",
        MIN_PAY_RATE,
        MAX_PAY_RATE,
        hourly_rate);
};

int main()
{
    char answer = 'N';

    std::string full_name;

    double hours, regular_hours, overtime_hours,
        hourly_rate, gross_pay, taxes, net_pay;
    do
    {
        std::cout << std::endl;

        input(full_name, hours, hourly_rate);

        split_hours(hours, regular_hours, overtime_hours);

        calc_gross_pay(regular_hours, overtime_hours, hourly_rate, gross_pay);

        calc_taxes(gross_pay, taxes);

        calc_net_pay(gross_pay, net_pay, taxes);

        output(full_name, regular_hours, overtime_hours, hourly_rate, gross_pay, taxes, net_pay);

        std::cout << std::endl;

        std::cout << "Process another employee (Y/N)? ";

        std::cin >> answer;

        while (answer != 'N' && answer != 'n' && answer != 'y' && answer != 'Y')
        {
            std::cout << "Please type 'Y' for yes or 'N' for no" << std::endl;

            std::cout << std::endl;

            std::cout << "Process another employee (Y/N)? ";

            std::cin >> answer;
        };

    } while (answer == 'y' || answer == 'Y');
};
