#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{
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
