#include<iostream>
#include<string>
#include <iomanip>

void process_name(std::string first_name, std::string last_name, std::string &full_name)
{
    full_name = last_name + ", " + first_name;

}

void input_full_name(std::string &first_name, std::string &last_name)
{
std::cout << "Enter a person's first name: ";
std::cin >> first_name;
std::cout << "Enter a person's last name: ";
std::cin >> last_name;
}

void output_full_name(std::string full_name) {
    std::cout << std::endl;
    std::cout << "[" << full_name << "]" << std::endl;
    std::cout << std::endl;
    std::cout << "[1234567890123456789012345]" << std::endl;
    std::cout << std::endl;
    std::cout << "["
           << std::setw(25) << full_name
              << "]"
             << std::endl;
             std::cout << std::endl;
     std::cout << "["
           << std::right << std::setw(25) << full_name
              << "]"
             << std::endl;
             std::cout << std::endl;
    std::cout << "["
           << std::left << std::setw(25) << full_name
             << "]"
             << std::endl;
             std::cout << std::endl;
}

int main()
{
    std::string first_name, last_name, full_name;
    input_full_name(first_name, last_name);
    process_name(first_name, last_name, full_name);
    output_full_name(full_name);
    return 0;
}
