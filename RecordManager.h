#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H


#include <iostream>
#include <vector>

#include "Record.h"
#include "SubsidiaryMethods.h"

using namespace std;

class RecordManager {

    vector<Record> records;
    const int LOGGED_USER_ID;
    //RecordsFile recordsFile;

    Record passNewRecordData();

public:
    RecordManager(int);
    ~RecordManager();
    void addRecord();
    void displayAllRecords();
//    void readLoggedUserRecordsFromFile();
//    void displayThisMonthRecords();
//    void displayPreviousMonthRecords();
//    void displaySelectedPeriodRecords();
//    void displayRecordsSummary();
};
#endif //RECORDMANAGER_H
