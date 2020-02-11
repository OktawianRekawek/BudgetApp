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


public:
    UsersFile(string fileName) : XmlFile(fileName) {};
    void saveUserInFile(User);
    vector<User> readUsersFromFile();
};

#endif //USERSFILE_H
