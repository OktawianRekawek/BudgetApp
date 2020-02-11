#include "RecordsFile.h"

void RecordsFile::saveRecordInFile(Record record){
    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Records");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Record");
    xml.IntoElem();
    xml.AddElem("UserId", record.getUserID());
    xml.AddElem("Date", record.getDate());
    xml.AddElem("Amount", to_string(record.getAmount()));
    xml.AddElem("Item", record.getItem());

    xml.Save(FILE_NAME);
}

vector<Record> RecordsFile::readLoggedUserRecordsFromFile(int loggedUserId){
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
        cout << "UserID: " << record.getUserID() << endl;
        if (record.getUserID() == loggedUserId) {
            xml.FindElem( "Date" );
            record.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            cout << "Date: " << record.getDate()<< endl;
            xml.FindElem( "Amount" );
            record.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            cout << "Amount: " << record.getAmount()<< endl;
            xml.FindElem( "Item" );
            record.setItem(xml.GetData());
            cout << "Item: " << record.getItem()<< endl;
            records.push_back(record);
        }
        xml.OutOfElem();
    }
    return records;
}
