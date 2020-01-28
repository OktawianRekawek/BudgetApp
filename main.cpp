#include <iostream>
#include "Budget.h"
#include "User.h"
#include "UserManager.h"

using namespace std;

int main__() {
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

int main_() {
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

int main(){

    UserManager userManager;

    userManager.userRagistration();
    userManager.displayAllUsers();
    userManager.userLogin();
    userManager.changeLoggedUserPassword();
    userManager.userLogout();

    return 0;
}
