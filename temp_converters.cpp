// Program: Convert Farenheits to Celsius
// Author: Ilya Babenko
// Date: Spring 2023 - T/Th @ 1pm

#include <iostream>
#include <iomanip>

void input_data(double &fahrenheit);
void perform_calculations(double fahrenheit, double &celsius);
void output_results(double celsius, double fahrenheit);
int main()
{
    double celsius, fahrenheit;
    input_data(fahrenheit);
    perform_calculations( fahrenheit, celsius);
    output_results(celsius,fahrenheit);
}

void input_data(double &fahrenheit){
    std::cout << std::setw(53) << "Farenheit to Celsius Converter" << std::endl << std::endl;
    std::cout << "Please provide the temperature in Farenheit to be converted to Celsius." << std::endl;
    std::cout << "Enter temp in F (ex: 32, 68, 98.6, 212): ";
    std::cin >> fahrenheit;
}

void perform_calculations(double fahrenheit, double &celsius )
{
    celsius = (5.0/9) * (fahrenheit - 32);
}

void output_results(double celsius, double fahrenheit) {
    std::cout << std::endl;
    std::cout << "Calculating..." << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed
              << std::setprecision(1) << fahrenheit << "F is " << celsius << "C" << std::endl;
}
