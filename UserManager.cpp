#include "UserManager.h"

UserManager::UserManager(){
    cout << "UserManager konstruktor" << endl;
}

UserManager::~UserManager(){
    cout << "UserManager dekonstruktor" << endl;
}

void UserManager::userRagistration(){
    cout << "UserManager rejestracja" << endl;
}

void UserManager::userLogin(){
    cout << "Logowania uzytkownika" << endl;
    loggedUserID = 1;
}
