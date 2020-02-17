#include "SubsidiaryMethods.h"

string SubsidiaryMethods::readLine() {
    string input = "";
    getline(cin, input);

    return input;
}

double SubsidiaryMethods::readDoubleNumber() {
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

char SubsidiaryMethods::readChar() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
