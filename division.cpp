// Program    : Division Experiments
// Author     : Ilya Babenko
// Date       : Spring 2023
// Description: This program demonstrates various division results when
//              using integers and floats.

#include <iostream>
#include <iomanip>

int main()
{
    double x, y, z;     // some floats
    int    m, n, q, r;  // some integers

    std::cout << std::fixed << std::setprecision(3);

    // Experiment #1: Division with literal floats
    std::cout << "1 : " << (23.0 / 4.0) << std::endl;

    // Experiment #2: Division with literal integers
    std::cout << "2 : " << (23 / 4) << std::endl;

    // Experiment #3: Division with float variables
    x = 23.0;
    y = 4.0;
   std::cout << "3 : " << (x / y) << std::endl;

    // Experiment #4: Division with integer variables
    m = 23;
    n = 4;
    std::cout << "4 : " << (m / n) << std::endl;

    // Experiment #5: Division with mixed types
 std::cout << "5a: " << (23 / 4.0) << std::endl;
   std::cout << "5b: " << (23.0 / 4) << std::endl;
   std::cout << "5c: " << (m / y) << std::endl;
std::cout << "5d: " << (x / n) << std::endl;

    // Experiment #6: Assignment with integer division
    q = m / n;
    z = m / n;
  std::cout << "6a: " << q << std::endl;
std::cout << "6b: " << z << std::endl;

    // Experiment #7: Assignment with float division
    z = x / y;
    q = x / y;
   std::cout << "7a: " << z << std::endl;
     std::cout << "7b: " << q << std::endl;

    // Experiment #8: Integer quotient and remainder
    q = m / n;
    r = m % n;
    std::cout << "8a: " << q << std::endl;
   std::cout << "8b: " << r << std::endl;
}
