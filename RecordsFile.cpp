#include "RecordsFile.h"

void RecordsFile::saveRecordInFile(Record record) {
    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Records");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Record");
    xml.IntoElem();
    xml.AddElem("UserId", record.getUserID());
    xml.AddElem("RecordID", record.getRecordID());
    xml.AddElem("Date", Date::convertDateFromIntToString(record.getDate()));
    xml.AddElem("Amount", SubsidiaryMethods::convertDoubleToString(record.getAmount()));
    xml.AddElem("Item", record.getItem());

    xml.Save(FILE_NAME);
}

vector<Record> RecordsFile::readLoggedUserRecordsFromFile(int loggedUserId) {
    CMarkup xml;
    vector<Record> records;
    Record record;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
        return records;

    xml.FindElem("Records");
    xml.IntoElem();

    while ( xml.FindElem("Record") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        record.setUserID(atoi(MCD_2PCSZ(xml.GetData())));
        if (record.getUserID() == loggedUserId) {
            xml.FindElem( "RecordID" );
            record.setRecordID(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Date" );
            record.setDate(Date::convertDateFromStringToInt(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Amount" );
            record.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Item" );
            record.setItem(xml.GetData());
            records.push_back(record);
        }
        xml.OutOfElem();
    }
    return records;
}
