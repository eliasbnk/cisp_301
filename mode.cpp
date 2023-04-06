#include <iostream>

#define MIN_RANGE 0
#define MAX_RANGE 10

void valid_numbers(std::string label, int &value)
{
    while (value < MIN_RANGE || value > MAX_RANGE)
    {
        std::cout << "Number invalid, enter a number between "
                  << MIN_RANGE << " and " << MAX_RANGE << "." << std::endl;
        std::cout << "Enter the " << label << " number: ";
        std::cin >> value;
    };
};

void input_numbers(std::string label, int &value)
{
    std::cout << "Enter the " << label << " number: ";
    std::cin >> value;
    valid_numbers(label, value);
};

void find_mode(int first, int second, int third, int &mode)
{
    if (first == second || first == third)
    {
        mode = first;
    }
    else if (second == third)
    {
        mode = second;
    }
};

void display_numbers(int first, int second, int third, int mode)
{
    if (mode != MIN_RANGE)
    {
        std::cout << "The mode of " << first << ", " << second << ", and "
                  << third << " is " << mode << std::endl;
    }
    else if (mode == MIN_RANGE &&
                 (first == MIN_RANGE && second == MIN_RANGE) ||
             (second == MIN_RANGE && third == MIN_RANGE) || (first == MIN_RANGE && third == MIN_RANGE))
    {
        std::cout << "The numbers " << first << ", " << second << ", and "
                  << third << " is " << mode << std::endl;
    }
    else
    {
        std::cout << "The numbers " << first << ", " << second << ", and "
                  << third << " don't have a mode." << std::endl;
    }
};

int main()
{
    int first, second, third;
    int mode = 0;

    input_numbers("first", first);
    input_numbers("second", second);
    input_numbers("third", third);

    find_mode(first, second, third, mode);

    display_numbers(first, second, third, mode);

    return 0;
};
