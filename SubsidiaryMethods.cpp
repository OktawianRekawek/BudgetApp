#include "SubsidiaryMethods.h"

string SubsidiaryMethods::readLine() {
    string input = "";
    getline(cin, input);

    return input;
}

double SubsidiaryMethods::readDoubleNumber(){
    string input = "";
    double number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
