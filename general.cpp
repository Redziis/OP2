#include "general.h"

bool isdigits(string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool validateName(string name){
    for (char i : name)
    {
        if (!isalpha(i))
        {
            cout << "Naudokite tik raides!" << endl;
            cout << "Iveskite is naujo ";
            return false;
        }
    }
    return true;
}

string getDigits(){
    bool valid;
    string number;
    do {
        cin >> number;
        cout << endl;
            if (!isdigits(number))
            {
                cout << "Naudokite tik teigiamus skaicius" << endl;
                cout << "Iveskite is naujo ";
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
    while(!valid);

    return number;
}
