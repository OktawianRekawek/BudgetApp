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
