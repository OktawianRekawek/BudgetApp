#include "Budget.h"

Budget::Budget(string usersFileName, string incomesFileName, string expansesFileName)
    : userManager(usersFileName), INCOMES_FILENAME(incomesFileName), EXPANSES_FILENAME(expansesFileName){
    expanseManager = NULL;
    incomeManager = NULL;
    balance = 0;
}

Budget::~Budget(){
    cout << "Destruktor" << endl;
}

void Budget::userRagistration(){
    userManager.userRagistration();
}

void Budget::userLogin(){
    userManager.userLogin();
    if (userManager.isUserLogged())
        incomeManager = new RecordManager(INCOMES_FILENAME, userManager.getLoggedUserID());
        expanseManager = new RecordManager(EXPANSES_FILENAME, userManager.getLoggedUserID());
}

void Budget::changeLoggedUserPassword(){
    cout << "Zmiana hasla uzytkownika" << endl;
}

void Budget::userLogout(){
    userManager.userLogout();
}

void Budget::addIncome(){
    incomeManager->addRecord();
}

void Budget::addExpanse(){
    expanseManager->addRecord();
}

bool Budget::isUserLogged(){
    return true;
}

void Budget::thisMonthBalance(){
    incomeManager->displayThisMonthRecords();
    expanseManager->displayThisMonthRecords();

    balance = incomeManager->getSummary() - expanseManager->getSummary();

    cout << "Przychody: " << incomeManager->getSummary() << endl;
    cout << "Wydatki:   " << expanseManager->getSummary() << endl;
    cout << "Bilans:    " << balance << endl;
}

void Budget::previousMonthBalance(){
    cout << "Bilans poprzedniego miesiaca" << endl;
}

void Budget::selectedPeriodBalance(){
    cout << "Bilans wybranego okresu" << endl;
}
