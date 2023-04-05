#include <iostream>

void input_number (int &number)
{
do {
    std::cout << std::endl;
    std::cout << "Enter a positive integer (zero to exit): ";
    std::cin >> number;
    if( number < 0){
        std::cout << "Only numbers greater than zero can be tested" << std::endl;
    };

} while (number < 0);
};

void output_numbers (int number)
{
    if (number > 0) {
     std::cout << "The Ulam sequence for " << number << " is: ";
    }

while (number > 1)
    {
   if (number % 2 == 0)
    {
        std::cout << number << " ";
        number /= 2;
    }
     else {

        std::cout << number << " ";
        number = (number * 3) + 1;
    }
    }
        if ( number == 1){
         std::cout << number;
        }
std::cout << std::endl;
};

int main () {
    int number = 0;
    do
    {

    input_number(number);

    output_numbers(number);

    } while (number != 0);
};
