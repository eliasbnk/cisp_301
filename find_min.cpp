#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Item          Qty     Price     Total" << std::endl;
    std::cout << "=========   =====   =======   =======" << std::endl;
    std::cout << std::left << std::setw(9) << "iPad Air"
              << "   " << std::right << std::setw(5) << "3"
              << "   " << std::setw(7) << "369.99"
              << "   " << std::setw(7) << "1109.37" << std::endl;
}
