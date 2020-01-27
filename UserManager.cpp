#include "UserManager.h"

UserManager::UserManager(){
    cout << "UserManager konstruktor" << endl;
}

UserManager::~UserManager(){
    cout << "UserManager dekonstruktor" << endl;
}

void UserManager::userRagistration(){
    User user = passNewUserData();
    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userLogin(){
    cout << "Logowania uzytkownika" << endl;
    loggedUserID = 1;
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

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
