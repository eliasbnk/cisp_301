// Program:			Chirps to Temperature Calculator
// Author:			Ilya Babenko - w1793796
// Date:			02/09/2023 - Spring 2023 - T/Th @ 1pm
// Description: This program asks the user to enter an observed chirp rate,
//              then calculates and displays the approximate temperature.

#include <iostream>
#include <iomanip>
#include <cmath>

void input_chirps(int &chirps);
void compute_temperature(int chirps, int &temperature);
void display_results(int chirps, int temperature);

int main()
{
    int chirps;
    int temperature;
    input_chirps(chirps);
    compute_temperature(chirps, temperature);
    display_results(chirps, temperature);
    return 0;
}

void input_chirps(int &chirps)
{
    std::cout << "Enter observed number of chirps: ";
    std::cin >> chirps;
}
void compute_temperature(int chirps, int &temperature)
{
    temperature = (chirps / 4) + 40;
}
void display_results(int chirps, int temperature)
{
    std::cout << chirps << " chirps, approximates the temperature to be " << temperature << "°F" << std::endl;
}
