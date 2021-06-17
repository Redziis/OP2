
#include "General.h"

#include "General.h"

//checks is string is only made out of digits

bool isdigits(string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

//checks if name is only made out of letters

bool validateName(string name) {
    for (char i : name)
    {
        if (!isalpha(i))
        {
            cout << "Error! Please use only letters" << endl;
            cout << "Try to enter students name again: ";
            return false;
        }
    }
    return true;
}

//Returns string that is only digits

string getDigits() {
    bool valid;
    string number;
    do {
        cin >> number;
        cout << endl;
        if (!isdigits(number))
        {
            cout << "Error! Please enter only digits" << endl;
            cout << "Try to enter your number again: ";
            valid = false;
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    return number;
}
