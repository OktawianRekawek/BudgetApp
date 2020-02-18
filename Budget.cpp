#include "Budget.h"

Budget::Budget(string usersFileName, string incomesFileName, string expansesFileName)
    : userManager(usersFileName), INCOMES_FILENAME(incomesFileName), EXPANSES_FILENAME(expansesFileName) {
    expanseManager = NULL;
    incomeManager = NULL;
    balance = 0;
}

Budget::~Budget() {
    delete expanseManager;
    delete incomeManager;

    expanseManager = NULL;
    incomeManager = NULL;
}

void Budget::userRagistration() {
    system("cls");
    cout << " >>> REJESTRACJA NOWEGO UZYTKOWNIKA <<<" << endl << endl;
    userManager.userRagistration();
}

void Budget::userLogin() {
    system("cls");
    cout << " >>> LOGOWANIE UZYTKOWNIKA <<<" << endl << endl;
    userManager.userLogin();
    if (userManager.isUserLogged()) {
        incomeManager = new RecordManager(INCOMES_FILENAME, userManager.getLoggedUserID());
        expanseManager = new RecordManager(EXPANSES_FILENAME, userManager.getLoggedUserID());
    }
}

void Budget::changeLoggedUserPassword() {
    system("cls");
    cout << " >>> ZMIANA HASLA UZYTKOWNIKA <<<" << endl << endl;
    userManager.changeLoggedUserPassword();
}

void Budget::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    delete expanseManager;
    incomeManager = NULL;
    expanseManager = NULL;
}

void Budget::addIncome() {

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    incomeManager->addRecord();
    cout << endl << "Nowy przychod zostal dodany" << endl;
    system("pause");
}

void Budget::addExpanse() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expanseManager->addRecord();
    cout << endl << "Nowy wydatek zostal dodany" << endl;
    system("pause");
}

bool Budget::isUserLogged() {
    return userManager.isUserLogged();
}

void Budget::thisMonthBalance() {
    system("cls");
    cout << " >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl << endl;
    cout << " Przychody:" << endl;
    cout << "------------------------------------" << endl;
    incomeManager->displayThisMonthRecords();
    cout << endl << " Wydatki:" << endl;
    cout << "------------------------------------" << endl;
    expanseManager->displayThisMonthRecords();

    balance = incomeManager->getSummary() - expanseManager->getSummary();
    cout << "====================================" << endl;
    cout << "           >>> BILANS <<<" << endl;
    cout << "====================================" << endl;
    cout << "    Suma przychodow:      ";
    cout.width(10);
    cout << incomeManager->getSummary() << endl;
    cout << "    Suma wydatkow:        ";
    cout.width(10);
    cout << expanseManager->getSummary() << endl;
    cout << "------------------------------------" << endl;
    cout << "    Bilans:               ";
    cout.width(10);
    cout << balance << endl;
    cout << "------------------------------------" << endl;
    system("pause");
}

void Budget::previousMonthBalance() {
    system("cls");

    cout << " >>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl << endl;
    cout << " Przychody:" << endl;
    cout << "------------------------------------" << endl;
    incomeManager->displayPreviousMonthRecords();
    cout << endl << " Wydatki:" << endl;
    cout << "------------------------------------" << endl;
    expanseManager->displayPreviousMonthRecords();

    balance = incomeManager->getSummary() - expanseManager->getSummary();
    cout << "====================================" << endl;
    cout << "           >>> BILANS <<<" << endl;
    cout << "====================================" << endl;
    cout << "    Suma przychodow:      ";
    cout.width(10);
    cout << incomeManager->getSummary() << endl;
    cout << "    Suma wydatkow:        ";
    cout.width(10);
    cout << expanseManager->getSummary() << endl;
    cout << "------------------------------------" << endl;
    cout << "    Bilans:               ";
    cout.width(10);
    cout << balance << endl;
    cout << "------------------------------------" << endl;
    system("pause");
}

void Budget::selectedPeriodBalance() {
    int firstDate, secondDate;
    system("cls");
    cout << "Podaj pierwsza date!" << endl;
    firstDate = Date::getDate();
    cout << "Podaj druga date!" << endl;
    secondDate = Date::getDate();

    if (Date::compareDates(firstDate, secondDate)) {
        system("cls");
        cout << " >>> BILANS Z OKRESU <<<" << endl;
        cout << " ";
        Date::displayDate(firstDate);
        cout << " - ";
        Date::displayDate(secondDate);
        cout << endl << endl;
        cout << " Przychody:" << endl;
        cout << "------------------------------------" << endl;
        incomeManager->displaySelectedPeriodRecords(firstDate,secondDate);
        cout << endl << " Wydatki:" << endl;
        cout << "------------------------------------" << endl;
        expanseManager->displaySelectedPeriodRecords(firstDate,secondDate);

        balance = incomeManager->getSummary() - expanseManager->getSummary();
        cout << "====================================" << endl;
        cout << "           >>> BILANS <<<" << endl;
        cout << "====================================" << endl;
        cout << "    Suma przychodow:      ";
        cout.width(10);
        cout << incomeManager->getSummary() << endl;
        cout << "    Suma wydatkow:        ";
        cout.width(10);
        cout << expanseManager->getSummary() << endl;
        cout << "------------------------------------" << endl;
        cout << "    Bilans:               ";
        cout.width(10);
        cout << balance << endl;
        cout << "------------------------------------" << endl;
    } else {
        cout << "Druga data jest przed pierwsza!" << endl;
    }
    system("pause");
}
