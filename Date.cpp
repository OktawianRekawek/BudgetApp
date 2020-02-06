#include "Date.h"

bool Date::isCorrectDate(string date) {
    if (!checkDateFormat(date)) {
        cout << "Data ma nieprawidlowy format!" << endl;
        return false;
    }
    if (!checkDate(date))
        return false;

    return true;
}

bool Date::checkDateFormat(string dateString) {

    if (dateString.length() != 10)
        return false;

    for (unsigned int i = 0; i < dateString.length(); i++) {

        if (i == 4 || i == 7) {
            if (dateString[i] != '-')
                return false;
        } else {
            if (!isdigit(dateString[i]))
                return false;
        }
    }

    return true;
}

bool Date::checkDate(string dateString) {
    string yearString, monthString, dayString;
    int year, month, day;

    string singleData = "";
    int singleDataNumber = 1;

    for (unsigned int charPosition = 0; charPosition < dateString.length(); charPosition++) {
        if (dateString[charPosition] != '-') {
            singleData += dateString[charPosition];
        } else {
            switch(singleDataNumber) {
            case 1:
                yearString = singleData;
                year = atoi(yearString.c_str());
                if (year < 2000) {
                    cout << "Wprowadzony rok jest nieprawidlowy!" << endl;
                    return false;
                }
                break;
            case 2:
                monthString = singleData;
                month = atoi(monthString.c_str());
                if (month > 12 || month < 1) {
                    cout << "Wprowadzony miesiac jest nieprawidlowy" << endl;
                    return false;
                }
                break;
            }
            singleData = "";
            singleDataNumber++;
        }
    }

    dayString = singleData;
    day = atoi(dayString.c_str());
    if (isCorrectDay(year, month, day))
        return true;

    cout << "Wprowadzony dzien miesiaca jest nieprawidlowy!" << endl;
    return false;
}

bool Date::isCorrectDay(int year, int month, int day) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31)
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30)
            return false;
        break;
    case 2:
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)) {
            if (day > 29)
                return false;
        } else if (day > 28)
            return false;
        break;
    }
    return true;
}

int Date::convertDateFromStringToInt(string dateString) {
    string dateWithoutSeparators = "";
    int date = 0;
    for (unsigned int i = 0; i < dateString.length(); i++) {
        if (dateString[i] != '-')
            dateWithoutSeparators += dateString[i];
    }
    date = atoi(dateWithoutSeparators.c_str());
    return date;
}

int Date::getThisYear() {

    time_t currentTime;
    struct tm * timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    return 2000 + timeInfo->tm_year - 100;
}

int Date::getThisMonth() {

    time_t currentTime;
    struct tm * timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    return timeInfo->tm_mon + 1;
}

int Date::getNumberOfMonthDays(int year, int month) {

    int numberOfDays = 0;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays = 31;
    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays = 30;
    case 2:
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            numberOfDays = 29;
        else
            numberOfDays = 28;
    }

    return numberOfDays;
}

int Date::getActualDate() {
    time_t currentTime;
    struct tm * timeInfo;

    int year, month, day;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    year = 2000 + timeInfo->tm_year - 100;
    month = timeInfo->tm_mon + 1;
    day = timeInfo->tm_mday;

    return year*10000+month*100+day;
}

int Date::getDate() {
    string dateString = "";
    do {
        cout << "Podaj date w formacie yyyy-mm-dd: ";
        dateString = SubsidiaryMethods::readLine();
    } while(!Date::isCorrectDate(dateString));
    return Date::convertDateFromStringToInt(dateString);
}

bool Date::compareDates(int firstDate, int secondDate){
    if (firstDate <= secondDate)
        return true;
    else
        return false;
}
