// Program    : Date and Time
// Author     : Ilya Babenko
// Course     : CISP 301/Krofchok (Spring 2023)
// Description: Displays the current date and time.

#define _CRT_SECURE_NO_WARNINGS  // Disables Visual Studio warning about using
                                 //   the localtime() module
#include <ctime>
#include <iostream>
#include <string>

void get_datetime(int &year, int &month, int &day, int &hour, int &minute);
void compute_jdn(int year, int month, int day, int &jdn);
void compute_dow(int year, int month, int day, int &dow);
void get_month_name(int month, std::string &month_name);
void get_weekday_name(int dow, std::string &weekday_name);
void display_date(int year, int month, int day);
void display_time(int hour, int minute);
void display_hour(int hour);
void display_minute(int minute);
void display_ampm(int hour);

int main()
{
    int year,  // current year
    month,    // current month number (1..12)
        day,  // current day (1..31)
        hour, // current hour (0..23)
        minute; // current minute (0..59)

    get_datetime(year, month, day, hour, minute);

    // Display current date
    std::cout << "Today's date is ";
    display_date(year, month, day);
    std::cout << std::endl;

    // Display current time
    std::cout << "The current time is ";
    display_time(hour, minute);
    std::cout << std::endl;

}

//
// An input module that obtains the current date and time components from
// the system clock. The year is a four-digit integer accurate for years
// since 1900, the month an integer from 1 to 12, the day an integer from
// 1 to 31, the hour an integer from 0 to 23, and the minute an integer
// from 0 to 59.
//
void get_datetime(int &year, int &month, int &day, int &hour, int &minute)
{
    time_t now = time(NULL);
    struct tm *tm_ptr = localtime(&now);

    year = 1900 + tm_ptr->tm_year;
    month = 1 + tm_ptr->tm_mon;
    day = tm_ptr->tm_mday;
    hour = tm_ptr->tm_hour;
    minute = tm_ptr->tm_min;
}

// **************************************************************************
// ** DO NOT CHANGE ANY LINES ABOVE THIS POINT, EXCEPT TO ADD YOUR NAME ON **
// ** LINE 2. ANY OTHER CHANGES ABOVE THIS POINT WILL BE REMOVED WHEN YOUR **
// ** PROGRAM IS GRADED.                                                   **
// **************************************************************************

//
// module displays the date in the format "Weekday, Month Day, Year"
//
void display_date(int year, int month, int day)
{
    int dow;
    std::string month_name, weekday_name;
    compute_dow(year, month, day, dow);
    get_month_name(month, month_name);
    get_weekday_name(dow, weekday_name);
    std::cout << weekday_name << ", " << month_name << " " << day << ", " << year;
}

//  module displays the time in 12-hour format
void display_time(int hour, int minute)
{
    display_hour(hour);
    display_minute(minute);
    display_ampm(hour);
}

// module computes the Julian Day Number (JDN) for a given year, month, and day
void compute_jdn(int year, int month, int day, int &jdn){
int a, b, c, d;
 a = (14 - month) / 12;
 b = (month - 3) + (12 * a);
 c = 4800 + year - a;
 d = (c / 4) - (c / 100) + (c / 400);
 jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

// module computes the day of the week (0-6, where 0 is Sunday and 6 is Saturday) for a given year, month, and day
void compute_dow(int year, int month, int day, int &dow){
 int jdn;
 compute_jdn(year, month, day, jdn);
 dow = (jdn + 1) % 7;
}

// module gets the name of the month corresponding to a given month number
void get_month_name(int month, std::string &month_name) {
    switch(month) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
    }
}

// module gets the name of the day of the week corresponding to a given day of the week number
void get_weekday_name(int dow, std::string &weekday_name){
    switch(dow) {
        case 0:
            weekday_name = "Sunday";
            break;
        case 1:
            weekday_name = "Monday";
            break;
        case 2:
            weekday_name = "Tuesday";
            break;
        case 3:
            weekday_name = "Wednesday";
            break;
        case 4:
            weekday_name = "Thursday";
            break;
        case 5:
            weekday_name = "Friday";
            break;
        case 6:
            weekday_name = "Saturday";
        }
}

//module displays the hour in 12-hour format, adjusting for midnight (0 hours) and converting from 24-hour format
void display_hour(int hour){
    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }
     std::cout << hour << ":";
}


// module displays the minute, adding a leading zero if necessary
void display_minute(int minute){
if(minute <= 9) {
    std::cout << "0" << minute;
} else{
    std::cout << minute;
}
}

// module displays "a.m." or "p.m." depending on whether the hour is before or after noon
void display_ampm(int hour){
if(hour >= 12) {
    std::cout << " p.m.";
} else{
    std::cout << " a.m.";
}
}
