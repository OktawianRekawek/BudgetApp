#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H


#include <iostream>
#include <vector>

#include "Record.h"
#include "SubsidiaryMethods.h"

using namespace std;

class RecordManager {

    vector<Record> recordes;
    const int LOGGED_USER_ID;
    //RecordsFile recordsFile;


public:
    RecordManager();
    ~RecordManager();
//    void addRecord();
//    void readLoggedUserRecordsFromFile();
//    void displayThisMonthRecords();
//    void displayPreviousMonthRecords();
//    void displaySelectedPeriodRecords();
//    void displayRecordsSummary();
};
#endif //RECORDMANAGER_H
