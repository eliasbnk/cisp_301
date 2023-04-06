// Program    : Lunar Lander (v.4)
// Author     : Prof. Krofchok
// Date       : Spring 2023
// Description: This program simulates a lunar landing. It displays the initial
//              time, altitude of the capsule, velocity, and amount of fuel
//              remaining, then prompts the player to input the amount of
//              fuel to burn. The program calculates and displays the new time,
//              altitude, velocity, and fuel remaining. This is repeated until
//              the capsule lands on the surface, at which point an indication
//              of the smoothness of the landing is displayed (except that we
//              don't yet know how to give the player another turn).
//
//              This version uses a selection statement to ensure that a burn
//              value entered by the user is within range.

#include <iomanip>
#include <iostream>

#define INITIAL_ALTITUDE 700.0
#define INITIAL_VELOCITY -100.0
#define INITIAL_FUEL 100.0
#define PI 3.14159

void welcome();
void initialize(int &time, double &altitude, double &velocity, double &fuel);
void show_header();
void show_stats(int time, double altitude, double velocity, double fuel, double &burn);
void recalculate(double burn, int &time, double &altitude, double &velocity,
                 double &fuel);

int main()
{
    int time;        // time since start of game
    double altitude, // altitude of player's capsule above moon
        velocity,    // velocity of capsule
        fuel,        // amount of fuel remaining in capsule
        burn;        // amount of fuel to burn during this turn

    // Set display of decimal numbers to one digit after decimal point
    std::cout << std::fixed << std::setprecision(1);

    welcome();
    initialize(time, altitude, velocity, fuel);
    show_header();
    do
    {
        if (fuel > 0.0)
        {

            show_stats(time, altitude, velocity, fuel, burn);
            recalculate(burn, time, altitude, velocity, fuel);
        }
        else if (fuel == 0.0)
        {
        }

    } while (fuel > 0.0 || fuel == 0.0);
}

//
// An output module that displays a welcome message to the user.
//
void welcome()
{
    std::cout << "Welcome to the extremely awesome Lunar Lander game!!!"
              << std::endl;
}

//
// A processing module that initializes the player's time, altitude, velocity
// and fuel.
//
void initialize(int &time, double &altitude, double &velocity, double &fuel)
{
    time = 0;
    altitude = INITIAL_ALTITUDE;
    velocity = INITIAL_VELOCITY;
    fuel = INITIAL_FUEL;
}

//
// An output module that displays the data table header on the screen.
//
void show_header()
{
    std::cout << std::endl;
    std::cout << " T  Altitude  Velocity   Fuel   Burn?" << std::endl;
    std::cout << "==  ========  ========  ======  =====" << std::endl;
}

//
// An output module that shows the player's current time, altitude, velocity
// and fuel.
//
void show_stats(int time, double altitude, double velocity, double fuel, double &burn)
{

    do
    {
        std::cout << std::setw(2) << time << "  "
                  << std::setw(8) << altitude << "  "
                  << std::setw(8) << velocity << "  "
                  << std::setw(6) << fuel << "  ";
        std::cin >> burn;

        if ((burn < 0) || (burn > fuel))
        {
            std::cout << "*** You can't do that"
                      << "Burning no fuel."
                      << std::endl;
        }
    } while (burn < 0 || burn > fuel);
}

//
// An input module that reads a burn value from the user.
//

//
// A processing module that recalculates the player's time, altitude, velocity
// and fuel, given a burn value.
//
void recalculate(double burn, int &time, double &altitude, double &velocity,
                 double &fuel)
{
    double acceleration; // acceleration of capsule

    time = time + 1;
    fuel = fuel - burn;
    acceleration = (2.3 * burn) - ((burn * fuel) / 200.0) - (2.0 * PI);
    velocity = velocity + acceleration;
    altitude = altitude + velocity - (acceleration / 2.0);
}
