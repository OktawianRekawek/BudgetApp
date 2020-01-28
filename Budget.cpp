#include "Budget.h"

Budget::Budget(){
    cout << "Konstruktor" << endl;
}

Budget::~Budget(){
    cout << "Destruktor" << endl;
}

void Budget::userRagistration(){
    userManager.userRagistration();
}

void Budget::userLogin(){
    cout << "Logowanie uzytkownika" << endl;
}

void Budget::changeLoggedUserPassword(){
    cout << "Zmiana hasla uzytkownika" << endl;
}

void Budget::userLogout(){
    cout << "Wylogowanie" << endl;
}

void Budget::addIncome(){
    cout << "Dodawanie przychodu" << endl;
}

void Budget::addExpanse(){
    cout << "Dodawanie wydatku" << endl;
}

bool Budget::isUserLogged(){
    cout << "Czy uzytkownik zalogowany?" << endl;
    return true;
}

void Budget::thisMonthBalance(){
    cout << "Bilans biezacego miesiaca" << endl;
}

void Budget::previousMonthBalance(){
    cout << "Bilans poprzedniego miesiaca" << endl;
}

void Budget::selectedPeriodBalance(){
    cout << "Bilans wybranego okresu" << endl;
}
