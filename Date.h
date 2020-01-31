#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

class Date {

public:

    static bool checkDate(string);
    static bool isCorrectDay(int, int, int);
    static bool checkDateFormat(string);
};

#endif // DATE_H
