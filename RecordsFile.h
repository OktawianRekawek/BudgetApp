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


public:
    RecordsFile(string fileName) : XmlFile(fileName) {};
    void saveRecordInFile(Record);
    vector<Record> readLoggedUserRecordsFromFile(int);
};

#endif //RECORDSFILE_H
