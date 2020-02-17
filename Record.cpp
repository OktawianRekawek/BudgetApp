#include "Record.h"


void Record::setUserID(int newUserID) {
    if (newUserID >= 0)
        userID = newUserID;
}

void Record::setDate(int newDate) {
    date = newDate;
}

void Record::setItem(string newItem) {
    item = newItem;
}

void Record::setAmount(double newAmount) {
    amount = newAmount;
}

int Record::getUserID() {
    return userID;
}
int Record::getDate() {
    return date;
}

string Record::getItem() {
    return item;
}

double Record::getAmount() {
    return amount;
}

bool operator< (const Record& a, const Record& b) {
    return a.date < b.date;
}
