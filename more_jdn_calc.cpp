// Program    : Julian Day Numbers, Day of Week, and Date Difference
// Author     : Ilya Babenko - w1793796
// Date       : Spring 2023 - T/Th @ 1:00pm
// Description: calculates and displays various pieces of information
//              related to a person's birthday and the current date.



#include <iostream>

// module prompts the user to enter a month, day, and year for a date
void get_date(int& year, int& month, int& day) {
    std::cout << "Enter month number (Jan=1, Feb=2, etc.): ";
    std::cin >> month;
    std::cout << "Enter day number: ";
    std::cin >> day;
    std::cout << "Enter year using four digits: ";
    std::cin >> year;
    std::cout << std::endl;
}

// module calculates the Julian day number for a given date
void compute_jdn(int year, int month, int day, int& jdn) {
    int a, b, c, d;
    a = (14 - month) / 12;
    b = (month - 3) + (12 * a);
    c = year + 4800 - a;
    d = (c / 4) - (c / 100) + (c / 400);
    jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

// module calculates the day of the week for a given date
void compute_dow(int year, int month, int day, int& dow) {
    int jdn;
    compute_jdn(year, month, day, jdn);
    dow = (jdn + 1) % 7;
}


// module calculates the number of days between two JDNs
void compute_days(int jdn1, int jdn2, int& days_between) {
    days_between = jdn2 - jdn1;
}

// module print a date in the format "month/day/year"
void display_date(int year, int month, int day) {
    std::cout << month << "/" << day << "/" << year;
}

// module prints several pieces of information about the user's birthday and the current date
void display_results(int today_year, int today_month, int today_day, int today_jdn, int birthday_year, int birthday_month, int birthday_day, int birthday_jdn, int birthday_dow, int days_between) {
    std::cout << "The JDN for ";
    display_date(today_year, today_month, today_day);
    std::cout << " is " << today_jdn << std::endl;
    std::cout << "The JDN for your birthday on ";
    display_date(birthday_year, birthday_month, birthday_day);
    std::cout << " was " << birthday_jdn << std::endl;
    std::cout << "The DOW on your birthday was " << birthday_dow << " (0=Sun, 1=Mon, etc.)" << std::endl;
    std::cout << "It has been " << days_between << " days since you were born" << std::endl;
}

int main() {
    int today_year, today_month, today_day, today_jdn;
    int birthday_year, birthday_month, birthday_day, birthday_jdn;
    int birthday_dow, days_between;

    std::cout << "For today's date..." << std::endl;
    get_date(today_year, today_month, today_day);

    std::cout << "For your birthday..." << std::endl;
    get_date(birthday_year, birthday_month, birthday_day);

    compute_jdn(today_year, today_month, today_day, today_jdn);
    compute_jdn(birthday_year, birthday_month, birthday_day, birthday_jdn);

    compute_dow(birthday_year, birthday_month, birthday_day, birthday_dow);

    compute_days(birthday_jdn, today_jdn, days_between);

    display_results(today_year, today_month, today_day, today_jdn, birthday_year, birthday_month, birthday_day, birthday_jdn, birthday_dow, days_between);

    return 0;
}
