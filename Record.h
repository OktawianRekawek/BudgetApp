#ifndef RECORD_H
#define RECORD_H

#include <iostream>

using namespace std;

class Record {
    int recordID;
    int userID;
    int date;
    string item;
    double amount;

public:
    void setRecordID(int);
    void setUserID(int);
    void setDate(int);
    void setItem(string);
    void setAmount(double);

    int getRecordID();
    int getUserID();
    int getDate();
    string getItem();
    double getAmount();

    friend bool operator< (const Record& a, const Record& b);
};
#endif // RECORD_H
