#include "RecordManager.h"

RecordManager::RecordManager(string fileName, int loggedUserID)
    : LOGGED_USER_ID(loggedUserID), recordsFile(fileName) {
    records = recordsFile.readLoggedUserRecordsFromFile(LOGGED_USER_ID);
    recordsSummary = 0;
}

RecordManager::~RecordManager() {
    cout << "RecordManager dekonstruktor" << endl;
}

void RecordManager::addRecord() {
    Record record;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO REKORDU <<<" << endl << endl;
    record = passNewRecordData();

    records.push_back(record);
    recordsFile.saveRecordInFile(record);
    cout << "Nowy rekord zostal dodany" << endl;
    system("pause");
}

Record RecordManager::passNewRecordData() {
    Record record;
    char character;
    int date = 0;
    string item = "", dateString = "";
    double amount = 0;

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
    cout << record.getDate() << "  ";
    cout << record.getAmount() << "  ";
    cout << record.getItem() << endl;
}

void RecordManager::displayAllRecords() {
    recordsSummary = 0;
    cout << "Data      Wartosc    Nazwa" << endl;
    cout << "---------------------------" << endl;
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

    cout << "Data      Wartosc    Nazwa" << endl;
    cout << "--------------------------" << endl;
    for (unsigned int i = 0; i <= records.size(); i++) {
        if (records[i].getDate()/100 == (thisYear*100)+thisMonth) {
            displayRecord(records[i]);
            recordsSummary += records[i].getAmount();
        }
    }
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

    cout << "Data      Wartosc    Nazwa" << endl;
    cout << "--------------------------" << endl;
    for (unsigned int i = 0; i <= records.size(); i++) {
        if (records[i].getDate()/100 == (thisYear*100)+thisMonth) {
            displayRecord(records[i]);
            recordsSummary += records[i].getAmount();
        }
    }
}

void RecordManager::displaySelectedPeriodRecords() {

    int firstDate, secondDate;
    recordsSummary = 0;
    cout << "Podaj pierwsza date!" << endl;
    firstDate = Date::getDate();
    cout << "Podaj druga date!" << endl;
    secondDate = Date::getDate();

    if (Date::compareDates(firstDate, secondDate)) {
        cout << "Data      Wartosc    Nazwa" << endl;
        cout << "--------------------------" << endl;
        for (unsigned int i = 0; i <= records.size(); i++) {
            if (records[i].getDate() >= firstDate && records[i].getDate() <= secondDate) {
                displayRecord(records[i]);
                recordsSummary += records[i].getAmount();
            }
        }
    } else {
        cout << "Druga data jest przed pierwsza!" << endl;
    }
}

void RecordManager::displayRecordsSummary() {
    cout << "=======================" << endl;
    cout << recordsSummary << endl;
    cout << "=======================" << endl;
}

double RecordManager::getSummary(){
    return recordsSummary;
}
