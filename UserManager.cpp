#include "UserManager.h"

UserManager::UserManager(){
    cout << "UserManager konstruktor" << endl;
}

UserManager::~UserManager(){
    cout << "UserManager dekonstruktor" << endl;
}

void UserManager::userRagistration(){
   // User user = passNewUserData();
    //users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userLogin(){
    cout << "Logowania uzytkownika" << endl;
    loggedUserID = 1;
}

//User UserManager::passNewUserData() {
//    User user;
//
//    user.ustawId(pobierzIdNowegoUzytkownika());
//    string login;
//    do {
//        cout << "Podaj login: ";
//        login = MetodyPomocnicze::wczytajLinie();
//        user.ustawLogin(login);
//    } while (czyIstniejeLogin(user.pobierzLogin()) == true);
//
//    string haslo;
//    cout << "Podaj haslo: ";
//    haslo = MetodyPomocnicze::wczytajLinie();
//    user.ustawHaslo(haslo);
//
//    return user;
//}
