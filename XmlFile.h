#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <fstream>

#include "Markup.h"

using namespace std;

class XmlFile {

protected:
    const string FILE_NAME;

public :
    XmlFile(string fileName) : FILE_NAME(fileName) {};
};

#endif // XMLFILE_H
