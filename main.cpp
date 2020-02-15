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
//
//int main() {
//    Budget budget = Budget("users.xml", "incomes.xml", "expanses.xml");
//
////    budget.userRagistration();
//    budget.userLogin();
////    budget.isUserLogged();
//    budget.changeLoggedUserPassword();
////    budget.addExpanse();
////    budget.addIncome();
////    budget.thisMonthBalance();
////    budget.previousMonthBalance();
////    budget.selectedPeriodBalance();
//    budget.userLogout();
//
//
//
//    return 0;
//}
//
//int main_user() {
//    User user;
//
//    user.setID(1);
//    user.setLogin("rekawian");
//    user.setPassword("ania");
//    user.setName("Oktawian");
//    user.setSurname("Rekawek");
//
//    cout << user.getID() << endl;
//    cout << user.getLogin() << endl;
//    cout << user.getPassword() << endl;
//    cout << user.getName() << endl;
//    cout << user.getSurname() << endl;
//
//    return 0;
//}
//
//int main_usermanager(){
//
//    UserManager userManager = UserManager("users.xml");
//
////    userManager.userRagistration();
//    userManager.displayAllUsers();
////    userManager.userLogin();
////    userManager.changeLoggedUserPassword();
////    userManager.userLogout();
//
//    return 0;
//}
//
//int main_Record() {
//    Record record;
//
//    record.setUserID(1);
//    record.setDate(20200128);
//    record.setItem("XBOX");
//    record.setAmount(1000);
//
//    cout << record.getUserID() << endl;
//    cout << record.getDate() << endl;
//    cout << record.getItem() << endl;
//    cout << record.getAmount() << endl;
//
//    return 0;
//}
//
//int main_recordManager(){
//
//    RecordManager recordManager = RecordManager("records.xml", 1);
//
//    recordManager.addRecord();
//    recordManager.addRecord();
//    recordManager.addRecord();
//    recordManager.displayAllRecords();
////    recordManager.displayThisMonthRecords();
////    recordManager.displayPreviousMonthRecords();
////    recordManager.displaySelectedPeriodRecords();
//    recordManager.displayRecordsSummary();
//
//    return 0;
//}
//
//int main_usersFile (){
//
////    UsersFile usersFile = UsersFile("users.xml");
//
////    User user;
////    user.setID(2);
////    user.setLogin("ania");
////    user.setPassword("oki");
////    user.setName("Anna");
////    user.setSurname("Kurek");
////
////    usersFile.saveUserInFile(user);
////    usersFile.readUsersFromFile();
//
//    return 0;
//}
//
//int main_RecordsFile(){
//    RecordsFile recordsFile = RecordsFile("records.xml");
//
////    Record record;
////    record.setUserID(2);
////    record.setDate(20200221);
////    record.setItem("Laptop");
////    record.setAmount(3500);
////
////    recordsFile.saveRecordInFile(record);
//    recordsFile.readLoggedUserRecordsFromFile(1);
//    recordsFile.readLoggedUserRecordsFromFile(2);
//
//    return 0;
//}
//
//int main_Date(){
////    Date::checkDate("2020-01-32");
////    Date::checkDate("2020-04-31");
////    Date::checkDate("2020-02-30");
////    Date::checkDate("2019-02-29");
////
////    cout << Date::checkDateFormat("2020-01-31") << endl;
////    cout << Date::checkDateFormat("20a0-01-31") << endl;
////    cout << Date::checkDateFormat("2020-01-1o") << endl;
////    cout << Date::checkDateFormat("22020-1-01") << endl;
////    cout << Date::checkDateFormat("920-01-31") << endl;
////
////    cout << Date::isCorrectDate("2020-01-31") << endl;
////    cout << Date::isCorrectDate("2020-01-32") << endl;
////    cout << Date::isCorrectDate("2020-02-30") << endl;
////    cout << Date::isCorrectDate("22020-1-01") << endl;
////    cout << Date::isCorrectDate("20a0-01-31") << endl;
////
////    cout << Date::convertDateFromStringToInt("2020-01-31") << endl;
//    cout << Date::getActualDate() << endl;
//    return 0;
//}
