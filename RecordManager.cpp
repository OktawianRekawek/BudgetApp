#include "RecordManager.h"

RecordManager::RecordManager(string fileName, int loggedUserID)
    : LOGGED_USER_ID(loggedUserID), recordsFile(fileName) {
    records = recordsFile.readLoggedUserRecordsFromFile(LOGGED_USER_ID);
    sortByDate();
    recordsSummary = 0;
}

RecordManager::~RecordManager() {
}

void RecordManager::addRecord() {
    Record record;

    record = passNewRecordData();

    records.push_back(record);
    sortByDate();
    recordsFile.saveRecordInFile(record);
}

Record RecordManager::passNewRecordData() {
    Record record;
    char character;
    int date = 0;
    string item = "", dateString = "";
    double amount = 0;

    if (records.empty())
        record.setRecordID(1);
    else
        record.setRecordID(records[records.size()].getRecordID() + 1);
    record.setUserID(LOGGED_USER_ID);

    cout << "Czy wpisz dotyczy dnia dzisiejszego?" << endl;
    cout << "Potwierdz naciskajac klawisz 't': " << endl;
    character = SubsidiaryMethods::readChar();
    if (character == 't') {
        date = Date::getActualDate();
    } else {
        date = Date::getDate();
    }
    record.setDate(date);

    cout << "Podaj nazwe: ";
    item = SubsidiaryMethods::readLine();
    record.setItem(item);

    cout << "Podaj wartosc: ";
    amount = SubsidiaryMethods::readDoubleNumber();
    record.setAmount(amount);

    return record;
}

void RecordManager::displayRecord(Record record) {
    int date = record.getDate();
    cout.width(5);
    cout << record.getRecordID() << " | ";
    Date::displayDate(date);
    cout << " | ";
    cout.width(10);
    cout << fixed << setprecision(2);
    cout << record.getAmount() << " | ";
    cout << record.getItem() << endl;
}

void RecordManager::displayAllRecords() {
    recordsSummary = 0;
    cout << " ID    Data       Wartosc      Nazwa" << endl;
    cout << "------------------------------------------" << endl;
    for (unsigned int i = 0; i < records.size(); i++) {
        displayRecord(records[i]);
        recordsSummary += records[i].getAmount();
    }
}

void RecordManager::displayThisMonthRecords() {

    int thisYear = 0, thisMonth = 0;
    recordsSummary = 0;
    thisYear = Date::getThisYear();
    thisMonth = Date::getThisMonth();

    cout << " ID    Data       Wartosc      Nazwa" << endl;
    cout << "------------------------------------------" << endl;
    if (!records.empty()){
        for (unsigned int i = 0; i <= records.size(); i++) {
            if (records[i].getDate()/100 == (thisYear*100)+thisMonth) {
                displayRecord(records[i]);
                recordsSummary += records[i].getAmount();
            }
        }
    }
    displayRecordsSummary();
}

void RecordManager::displayPreviousMonthRecords() {

    int thisYear = 0, thisMonth = 0;
    recordsSummary = 0;
    thisYear = Date::getThisYear();
    thisMonth = Date::getThisMonth();

    if (thisMonth == 1) {
        thisMonth = 12;
        thisYear -= 1;
    } else
        thisMonth -= 1;

    cout << " ID    Data       Wartosc      Nazwa" << endl;
    cout << "------------------------------------------" << endl;
    if (!records.empty()){
        for (unsigned int i = 0; i <= records.size(); i++) {
            if (records[i].getDate()/100 == (thisYear*100)+thisMonth) {
                displayRecord(records[i]);
                recordsSummary += records[i].getAmount();
            }
        }
    }
    displayRecordsSummary();
}

void RecordManager::displaySelectedPeriodRecords(int firstDate, int secondDate) {

    recordsSummary = 0;

    cout << " ID    Data       Wartosc      Nazwa" << endl;
    cout << "------------------------------------------" << endl;
    if(!records.empty()){
        for (unsigned int i = 0; i <= records.size(); i++) {
            if (records[i].getDate() >= firstDate && records[i].getDate() <= secondDate) {
                displayRecord(records[i]);
                recordsSummary += records[i].getAmount();
            }
        }
    }
    displayRecordsSummary();
}

void RecordManager::displayRecordsSummary() {
    cout << "------------------------------------" << endl;
    cout << "      Suma:  ";
    cout.width(10);
    cout << recordsSummary << endl;
    cout << "------------------------------------" << endl;
}

double RecordManager::getSummary() {
    return recordsSummary;
}

void RecordManager::sortByDate(){
    sort(records.begin(), records.end(), less<Record>());
}
