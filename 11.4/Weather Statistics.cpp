/*
 * Write a program that uses a structure to store the following weather 
 * data for a particular month:  
 * Total Rainfall
 * High Temperature
 * Low Temperature
 * Average Temperature
 * The program should have an array of 12 structures to hold weather data for
 * an entire year. When the program runs, it should ask the user to enter data
 * for each month. (The average temperature should be calculated.) Once the 
 * data are entered for all the months, the program should calculate and 
 * display the average monthly rainfall, the total rainfall for the year,
 * the highest and lowest temperatures for the year (and the months they
 * occurred in), and the average of all the monthly average temperatures.
 */
/* 
 * File:   Weather Statistics.cpp
 * Author: Nicolas Zavala
 *
 * Created on March 26, 2018, 11:53 AM
 */

#include <iostream>
#include <cstring>   // for strlen
#include <limits>    // for streamsize max(), double max/min
using std::cin;
using std::cout;
using std::cerr;

struct WeatherData {
    double total_rain;
    double hi_temp;
    double lo_temp;
    double avg_temp;
};

const char* MONTH_NAMES[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char* ERROR_TEMP_MSG =
"** Temperature must be between -100 and 140 degrees. Try again: ";
size_t ERROR_TEMP_MSG_LEN = strlen(ERROR_TEMP_MSG);

const char* ERROR_RAIN_MSG =
"** Rainfall amount must be greater than 0. Try again: ";
size_t ERROR_RAIN_MSG_LEN = strlen(ERROR_RAIN_MSG);
double getTemp(const char* name)
{
    double temp;
    cout << "Enter the " << name << ": ";

    do {
        cin >> temp;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while ((temp < -100 or temp > 140)
             and cerr.write(ERROR_TEMP_MSG, ERROR_TEMP_MSG_LEN));
    return temp;

}

int main()

{
    WeatherData year_data[12];
    double year_rainfall = 0;
    unsigned char lowest = 0;  // index of month with lowest temperature
    unsigned char highest = 0; // index of month with highest temperature
    double sum_avg_temps = 0;  // accumulates average temps, to be divided
    // data gathering loop
    for (int y = 0; y < 12; y++) {
        cout << "\nEntry: " << MONTH_NAMES[y] << '\n';
        cout << "Enter the Total Rainfall: ";
        do {
            cin >> year_data[y].total_rain;

            if (!cin.good()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (year_data[y].total_rain < 0 and
                 cerr.write(ERROR_RAIN_MSG, ERROR_RAIN_MSG_LEN));
        year_data[y].hi_temp = getTemp("Highest Temperature");
        year_data[y].lo_temp = getTemp("Lowest Temperature");
        year_data[y].avg_temp = getTemp("Average Temperature");

        //calculate statistics
        year_rainfall += year_data[y].total_rain;
        if (year_data[highest].hi_temp < year_data[y].hi_temp) highest = y;
        if (year_data[lowest].lo_temp > year_data[y].lo_temp)  lowest = y;
        sum_avg_temps += year_data[y].avg_temp;
    }

    // output results
    cout << "\n === Results ===\n";
    cout << "Average Monthly Rainfall: " << (year_rainfall / 12) << '\n';
    cout << "Total Yearly Rainfall: " << year_rainfall << '\n';
    cout << "Highest Temperature: " << year_data[highest].hi_temp << " ("
         << MONTH_NAMES[highest] << ")\n";
    cout << "Lowest Temperature: " << year_data[lowest].lo_temp << " ("
         << MONTH_NAMES[lowest] << ")\n";
    cout << "Average Monthly Temperature: " << (sum_avg_temps / 12) << "\n";

   return 0;

}

