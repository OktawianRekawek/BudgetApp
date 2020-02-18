#ifndef RECORDSFILE_H
#define RECORDSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Record.h"
#include "SubsidiaryMethods.h"
#include "XmlFile.h"
#include "Date.h"

using namespace std;

class RecordsFile : public XmlFile{

    int lastRecordID;
public:
    RecordsFile(string fileName);
    void saveRecordInFile(Record);
    vector<Record> readLoggedUserRecordsFromFile(int);
    int getLastRecordID();
    void setLastRecordID(int);
};

#endif //RECORDSFILE_H
