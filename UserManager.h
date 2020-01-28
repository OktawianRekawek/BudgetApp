#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>

#include "User.h"
#include "SubsidiaryMethods.h"

using namespace std;

class UserManager {

    int loggedUserID;
    vector<User> users;
    //UsersFie usersFile;

    User passNewUserData();
    int getNewUserID();
    bool isLoginExist(string);

public:
    UserManager();
    ~UserManager();
    void userRagistration();
    void userLogin();
    void displayAllUsers();
    void changeLoggedUserPassword();
   // void userLogout();
   // void displayAllUsers();
   // void readUsersFromFile();
};
#endif //USERMANAGER_H
