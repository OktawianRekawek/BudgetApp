#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

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
    void displayRecord(Record);
    void displayRecordsSummary();
    void sortByDate();

public:
    RecordManager(string, int);
    ~RecordManager();
    void addRecord();
    void displayAllRecords();
    void displayThisMonthRecords();
    void displayPreviousMonthRecords();
    void displaySelectedPeriodRecords(int, int);
    double getSummary();
};
#endif //RECORDMANAGER_H
