#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"
#include "SubsidiaryMethods.h"
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile{


//    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik);
//    Uzytkownik pobierzDaneUzytkownika(string);
public:
    UsersFile(string fileName) : XmlFile(fileName) {};
    void saveUserInFile(User);
//    vector<Uzytkownik> wczytajUzytkownikowZPliku();
//    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif //USERSFILE_H
