#include <iostream>
#include "Budget.h"
#include "User.h"
#include "UserManager.h"
#include "Record.h"

using namespace std;

int main_budget() {
    Budget budget;

    budget.userRagistration();
    budget.userLogin();
    budget.isUserLogged();
    budget.changeLoggedUserPassword();
    budget.addExpanse();
    budget.addIncome();
    budget.thisMonthBalance();
    budget.previousMonthBalance();
    budget.selectedPeriodBalance();
    budget.userLogout();



    return 0;
}

int main_user() {
    User user;

    user.setID(1);
    user.setLogin("rekawian");
    user.setPassword("ania");
    user.setName("Oktawian");
    user.setSurname("Rekawek");

    cout << user.getID() << endl;
    cout << user.getLogin() << endl;
    cout << user.getPassword() << endl;
    cout << user.getName() << endl;
    cout << user.getSurname() << endl;

    return 0;
}

int main_userManager(){

    UserManager userManager;

    userManager.userRagistration();
    userManager.displayAllUsers();
    userManager.userLogin();
    userManager.changeLoggedUserPassword();
    userManager.userLogout();

    return 0;
}

int main() {
    Record record;

    record.setRecordID(1);
    record.setUserID(1);
    record.setDate(20200128);
    record.setItem("XBOX");
    record.setAmount(1000);

    cout << record.getRecordID() << endl;
    cout << record.getRecordID() << endl;
    cout << record.getDate() << endl;
    cout << record.getItem() << endl;
    cout << record.getAmount() << endl;

    return 0;
}
