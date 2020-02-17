#ifndef SUBSIDIARYMETHODS_H
#define SUBSIDIARYMETHODS_H


#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class SubsidiaryMethods {

public:
    static string readLine();
    static double readDoubleNumber();
    static char readChar();
    static string convertDoubleToString(double);
};

#endif // SUBSIDIARYMETHODS_H
