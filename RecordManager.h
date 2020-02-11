#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H


#include <iostream>
#include <vector>

#include "Record.h"
#include "SubsidiaryMethods.h"
#include "Date.h"
#include "RecordsFile.h"

using namespace std;

class RecordManager {

    vector<Record> records;
    const int LOGGED_USER_ID;
    double recordsSummary;
    RecordsFile recordsFile;

    Record passNewRecordData();

public:
    RecordManager(string, int);
    ~RecordManager();
    void addRecord();
    void displayRecord(Record);
    void displayAllRecords();
    void readLoggedUserRecordsFromFile();
    void displayThisMonthRecords();
    void displayPreviousMonthRecords();
    void displaySelectedPeriodRecords();
    void displayRecordsSummary();
};
#endif //RECORDMANAGER_H
