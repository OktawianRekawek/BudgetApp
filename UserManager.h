#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>

#include "User.h"
#include "SubsidiaryMethods.h"
#include "UsersFile.h"

using namespace std;

class UserManager {

    int loggedUserID;
    vector<User> users;
    UsersFile usersFile;

    User passNewUserData();
    int getNewUserID();
    bool isLoginExist(string);

public:
    UserManager(string);
    ~UserManager();
    void userRagistration();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    bool isUserLogged();
    int getLoggedUserID();
};
#endif //USERMANAGER_H
