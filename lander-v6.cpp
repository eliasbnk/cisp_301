// Program    : Lunar Lander (v.6)
// Author     : Prof. Krofchok
// Date       : Spring 2023
// Description: This program simulates a lunar landing. It displays the initial
//              time, altitude of the capsule, velocity, and amount of fuel
//              remaining, then prompts the player to input the amount of
//              fuel to burn. The program calculates and displays the new time,
//              altitude, velocity, and fuel remaining. This is repeated until
//              the capsule lands on the surface, at which point an indication
//              of the smoothness of the landing is displayed.
//
//              This is a complete version of the game, using a variety of
//              loops and selection statements.

#include <iomanip>
#include <iostream>
#include <string>

#define INITIAL_ALTITUDE   700.0
#define INITIAL_VELOCITY  -100.0
#define INITIAL_FUEL       100.0
#define PI                 3.14159

void welcome();
void initialize(int &time, double &altitude, double &velocity, double &fuel);
void show_header();
void show_stats(int time, double altitude, double velocity, double fuel);
void input_burn(double fuel, double &burn);
void recalculate(double burn, int &time, double &altitude, double &velocity,
  double &fuel);
void absolute_value(double number, double &absval);
void show_landing_message(double speed);
void get_yesno(char &answer);

int main()
{
    int    time;        // time since start of game
    double altitude,    // altitude of player's capsule above moon
           velocity,    // velocity of capsule
           fuel,        // amount of fuel remaining in capsule
           burn,        // amount of fuel to burn during this turn
           speed;       // speed at time of landing
    char   play_again;  // does the player want to play again?

    // Set display of decimal numbers to one digit after decimal point
    std::cout << std::fixed << std::setprecision(1);

    welcome();
    do {

        initialize(time, altitude, velocity, fuel);

        // Main game loop
        show_header();
        show_stats(time, altitude, velocity, fuel);
        while (altitude > 0.0) {
            input_burn(fuel, burn);
            recalculate(burn, time, altitude, velocity, fuel);
            show_stats(time, altitude, velocity, fuel);
        }

        // Evaluate smoothness of landing (Note: Speed is the absolute value
        // of velocity)
        absolute_value(velocity, speed);
        show_landing_message(speed);

        // Play again?
        get_yesno(play_again);

    } while ((play_again == 'y') || (play_again == 'Y'));
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
    time     = 0;
    altitude = INITIAL_ALTITUDE;
    velocity = INITIAL_VELOCITY;
    fuel     = INITIAL_FUEL;
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
void show_stats(int time, double altitude, double velocity, double fuel)
{
    std::cout << std::setw(2) << time     << "  "
              << std::setw(8) << altitude << "  "
              << std::setw(8) << velocity << "  "
              << std::setw(6) << fuel     << "  ";
}

//
// An input module that reads a burn value from the user.
//
void input_burn(double fuel, double &burn)
{
    do {
        // (Note: The input prompt would normally be displayed here, but
        //   has been removed because the burn input is incorporated into
        //   the stats table)
        // std::cout << "Enter fuel to burn: ";
        std::cin >> burn;

        if (burn < 0) {
            std::cout << "You can't burn negative fuel!   ";
        }
        else if (burn > fuel) {
            std::cout << "You don't have that much fuel!  ";
        }
    } while ((burn < 0) || (burn > fuel));  // !!!
}

//
// A processing module that recalculates the player's time, altitude, velocity
// and fuel, given a burn value.
//
void recalculate(double burn, int &time, double &altitude, double &velocity,
  double &fuel)
{
    double acceleration;  // acceleration of capsule

    time = time + 1;
    fuel = fuel - burn;
    acceleration = (2.3 * burn) - ((burn * fuel) / 200.0)
                     - (2.0 * PI);
    velocity = velocity + acceleration;
    altitude = altitude + velocity - (acceleration / 2.0);
}

//
// A processing module that computes the absolute value of a given number.
//
void absolute_value(double number, double &absval)
{
    if (number >= 0) {
        absval = number;
    } else {
        absval = -number;
    }
}

//
// An output module that evaluates the smoothness of the player's landing, and
// displays a message based on their final speed.
//
void show_landing_message(double speed)
{
    std::string message;

    if (speed > 77) {
        message = "Your crash created a new crater";
    } else if (speed > 47) {
        message = "Crash!";
    } else if (speed > 29) {
        message = "Scrunch!";
    } else if (speed > 21) {
        message = "Crunch!";
    } else if (speed > 12) {
        message = "That was a very bumpy landing!";
    } else if (speed > 5) {
        message = "Too fast, but you landed safely";
    } else {
        message = "Nice landing!";
    }

    std::cout << std::endl << std::endl;
    std::cout << "***** " << message << " *****" << std::endl;
}

//
// An input module that asks the player if they want to play the game again.
//
void get_yesno(char &answer)
{
    std::cout << std::endl;
    std::cout << "Do you want to play again (Y/N)? ";
    std::cin >> answer;
}
