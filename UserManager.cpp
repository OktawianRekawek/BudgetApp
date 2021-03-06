#include "UserManager.h"

UserManager::UserManager(string fileName)
    : usersFile(fileName) {
    users = usersFile.readUsersFromFile();
    loggedUserID = 0;
}

UserManager::~UserManager() {
}

void UserManager::userRagistration() {
    User user = passNewUserData();
    users.push_back(user);
    usersFile.saveUserInFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userLogin() {
    string login = "", password = "";
    cout << "Podaj login: ";
    login = SubsidiaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int tries = 3; tries > 0; tries--) {
                cout << "Podaj haslo. Pozostalo prob: " << tries << ": ";
                password = SubsidiaryMethods::readLine();

                if (itr -> getPassword() == password) {
                    loggedUserID = itr -> getID();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

User UserManager::passNewUserData() {
    User user;

    user.setID(getNewUserID());
    string login;
    do {
        cout << "Podaj login: ";
        login = SubsidiaryMethods::readLine();
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    password = SubsidiaryMethods::readLine();
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    name = SubsidiaryMethods::readLine();
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    surname = SubsidiaryMethods::readLine();
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserID() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getID() + 1;
}

bool UserManager::isLoginExist(string login) {

    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::changeLoggedUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SubsidiaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getID() == loggedUserID) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveNewPasswordInFile(newPassword, loggedUserID);
}

void UserManager::userLogout() {
    loggedUserID = 0;
    cout << endl << "Wylogowales sie." << endl << endl;
    system("pause");
}

bool UserManager::isUserLogged() {
    if (loggedUserID != 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserID() {
    return loggedUserID;
}
