#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <string>

#include "SubsidiaryMethods.h"

using namespace std;

class Date {


public:

    static bool checkDate(string);
    static bool isCorrectDay(int, int, int);
    static bool checkDateFormat(string);
    static bool isCorrectDate(string);
    static int convertDateFromStringToInt(string);
    static string convertDateFromIntToString(int);
    static int getThisYear();
    static int getThisMonth();
    static int getNumberOfMonthDays(int, int);
    static int getActualDate();
    static int getDate();
    static bool compareDates(int, int);
    static void displayDate(int);
};

#endif // DATE_H
