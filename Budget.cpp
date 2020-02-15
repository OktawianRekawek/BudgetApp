#include "Budget.h"

Budget::Budget(string usersFileName, string incomesFileName, string expansesFileName)
    : userManager(usersFileName), INCOMES_FILENAME(incomesFileName), EXPANSES_FILENAME(expansesFileName) {
    expanseManager = NULL;
    incomeManager = NULL;
    balance = 0;
}

Budget::~Budget() {
    cout << "Destruktor" << endl;
}

void Budget::userRagistration() {
    userManager.userRagistration();
}

void Budget::userLogin() {
    userManager.userLogin();
    if (userManager.isUserLogged())
        incomeManager = new RecordManager(INCOMES_FILENAME, userManager.getLoggedUserID());
    expanseManager = new RecordManager(EXPANSES_FILENAME, userManager.getLoggedUserID());
}

void Budget::changeLoggedUserPassword() {
    cout << "Zmiana hasla uzytkownika" << endl;
}

void Budget::userLogout() {
    userManager.userLogout();
}

void Budget::addIncome() {
    incomeManager->addRecord();
}

void Budget::addExpanse() {
    expanseManager->addRecord();
}

bool Budget::isUserLogged() {
    return true;
}

void Budget::thisMonthBalance() {
    incomeManager->displayThisMonthRecords();
    expanseManager->displayThisMonthRecords();

    balance = incomeManager->getSummary() - expanseManager->getSummary();

    cout << "Przychody: " << incomeManager->getSummary() << endl;
    cout << "Wydatki:   " << expanseManager->getSummary() << endl;
    cout << "Bilans:    " << balance << endl;
}

void Budget::previousMonthBalance() {
    incomeManager->displayPreviousMonthRecords();
    expanseManager->displayPreviousMonthRecords();

    balance = incomeManager->getSummary() - expanseManager->getSummary();

    cout << "Przychody: " << incomeManager->getSummary() << endl;
    cout << "Wydatki:   " << expanseManager->getSummary() << endl;
    cout << "Bilans:    " << balance << endl;
}

void Budget::selectedPeriodBalance() {
    int firstDate, secondDate;

    cout << "Podaj pierwsza date!" << endl;
    firstDate = Date::getDate();
    cout << "Podaj druga date!" << endl;
    secondDate = Date::getDate();

    if (Date::compareDates(firstDate, secondDate)) {
        incomeManager->displaySelectedPeriodRecords(firstDate, secondDate);
        expanseManager->displaySelectedPeriodRecords(firstDate, secondDate);

        balance = incomeManager->getSummary() - expanseManager->getSummary();

        cout << "Przychody: " << incomeManager->getSummary() << endl;
        cout << "Wydatki:   " << expanseManager->getSummary() << endl;
        cout << "Bilans:    " << balance << endl;
    } else {
        cout << "Druga data jest przed pierwsza!" << endl;
    }
}
