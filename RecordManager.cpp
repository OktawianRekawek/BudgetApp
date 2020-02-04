#include "RecordManager.h"

RecordManager::RecordManager(int loggedUserID) : LOGGED_USER_ID(loggedUserID){
    cout << "RecordManager konstruktor" << endl;
}

RecordManager::~RecordManager(){
    cout << "RecordManager dekonstruktor" << endl;
}

void RecordManager::addRecord() {
    Record record;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO REKORDU <<<" << endl << endl;
    record = passNewRecordData();

    records.push_back(record);
//    if (plikZAdresatami.dopiszAdresataDoPliku(record)) {
//        cout << "Nowy adresat zostal dodany" << endl;
//    } else {
//        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
//    }
    system("pause");
}

Record RecordManager::passNewRecordData() {
    Record record;

    int date = 0;
    string item = "", dateString = "";
    double amount = 0;

    record.setRecordID(0+1);
    record.setUserID(LOGGED_USER_ID);

    do {
        cout << "Podaj date w formacie yyyy-mm-dd: ";
        dateString = SubsidiaryMethods::readLine();
    } while(!Date::isCorrectDate(dateString));
    date = Date::convertDateFromStringToInt(dateString);
    record.setDate(date);

    cout << "Podaj nazwe: ";
    item = SubsidiaryMethods::readLine();
    record.setItem(item);

    cout << "Podaj wartosc: ";
    amount = SubsidiaryMethods::readDoubleNumber();
    record.setAmount(amount);

    return record;
}

void RecordManager::displayRecord(Record record){
    cout << record.getRecordID() << endl;
    cout << record.getUserID() << endl;
    cout << record.getDate() << endl;
    cout << record.getItem() << endl;
    cout << record.getAmount() << endl;
}

void RecordManager::displayAllRecords(){
    for (unsigned int i = 0; i < records.size(); i++)
        displayRecord(records[i]);
}

void RecordManager::displayThisMonthRecords(){

    int thisYear = 0, thisMonth = 0;

    thisYear = Date::getThisYear();
    thisMonth = Date::getThisMonth();

    for (unsigned int i = 0; i <= records.size(); i++){
        if (records[i].getDate()/100 == (thisYear*100)+thisMonth)
            displayRecord(records[i]);
    }
}

void RecordManager::displayPreviousMonthRecords(){

    int thisYear = 0, thisMonth = 0;

    thisYear = Date::getThisYear();
    thisMonth = Date::getThisMonth();

    if (thisMonth == 1){
        thisMonth = 12;
        thisYear -= 1;
    } else
        thisMonth -= 1;

    for (unsigned int i = 0; i <= records.size(); i++){
        if (records[i].getDate()/100 == (thisYear*100)+thisMonth)
            displayRecord(records[i]);
    }
}
