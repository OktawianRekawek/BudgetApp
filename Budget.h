#ifndef BUDGET_H
#define BUDGET_H


#include <iostream>
#include "UserManager.h"
#include "RecordManager.h"

using namespace std;

class Budget {
    UserManager userManager;
    RecordManager *incomeManager;
    RecordManager *expanseManager;
    const string INCOMES_FILENAME;
    const string EXPANSES_FILENAME;
public:
    Budget(string, string, string);
    ~Budget();
    void userRagistration();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    void addIncome();
    void addExpanse();
    bool isUserLogged();
    void thisMonthBalance();
    void previousMonthBalance();
    void selectedPeriodBalance();
};
#endif //BUDGET_H
