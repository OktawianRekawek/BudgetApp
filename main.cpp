#include <iostream>
#include "Budget.h"
#include "User.h"
#include "UserManager.h"
#include "Record.h"
#include "RecordManager.h"
#include "Date.h"
#include "UsersFile.h"
#include "RecordsFile.h"

using namespace std;

char selectFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SubsidiaryMethods::readChar();

    return choice;
}

char selectFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SubsidiaryMethods::readChar();

    return choice;
}

int main() {
    Budget budget("users.xml", "incomes.xml", "expanses.xml");
    char choice;

    while (true) {
        if (budget.isUserLogged()) {
            choice = selectFromUserMenu();

            switch (choice) {
            case '1':
                budget.addIncome();
                break;
            case '2':
                budget.addExpanse();
                break;
            case '3':
                budget.thisMonthBalance();
                break;
            case '4':
                budget.previousMonthBalance();
                break;
            case '5':
                budget.selectedPeriodBalance();
                break;
            case '6':
                budget.changeLoggedUserPassword();
                break;
            case '7':
                budget.userLogout();
                break;
            }
        } else {
            choice = selectFromMainMenu();

            switch (choice) {
            case '1':
                budget.userRagistration();
                break;
            case '2':
                budget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }

        }
    }
    return 0;
}
