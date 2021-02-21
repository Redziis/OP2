#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;


struct Studentas
{
    string Vardas, Pavarde;
    int* namudarbai = nullptr;
    int ND = 0, egzpazymys;
    double galutinis;
};

bool isdigits(string &str)

{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int* arrayResize(int* arr, int arraySize){
    int* newArr = new int[arraySize+1];
    for(int i = 0; i < arraySize; i++)
    {
       newArr[i] = arr[i];
    }
    delete [] arr;
    return newArr;
}

void namudarbai(bool PazymiuSkaicius, Studentas& Studentas){
    bool run = true;
    string pazymys;
    if (PazymiuSkaicius)
    {
        Studentas.namudarbai = new int[Studentas.ND];
        for (int i=0; i<Studentas.ND; i++)
        {
            do{
                cout << i + 1 << " -ojo pazymio ivestis ";
                cin >> pazymys;
                if  (isdigits(pazymys) && std::stoi(pazymys) <= 10 && std::stoi(pazymys) > 0 )
                {
                    Studentas.namudarbai[i] = std::stoi(pazymys);
                    run = false;
                }
                else
                {
                    cout << "Klaidingas pazymys" << endl;
                    run = true;
                }
            }
            while(run);
        }
    }
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

int egzaminas(){
    int pazymys;
    bool valid = false;
    do
    {
        pazymys = std::stoi(getDigits());
        if (pazymys > 10 || pazymys <=0)
        {
            cout << "Egzamino pazymys ivestas neteisingai" << endl;
            cout << "Iveskite is naujo ";
        }
        else
        {
            valid = true;
        }
    }
    while(!valid);

    return pazymys;
}

void randomgrades(bool PazymiuSkaicius, Studentas& Studentas){
    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);

    if (!PazymiuSkaicius)
    {
        std::uniform_int_distribution<int> distributionSize(1, 15);
        Studentas.ND = distributionSize(generator);
    }

    cout << "Atsitiktinai sugeneruoti " << Studentas.ND << " namu darbu pazymiai:  ";
    Studentas.namudarbai = new int[Studentas.ND];
    for (int i=0; i<Studentas.ND; i++)
    {
        Studentas.namudarbai[i] = distribution(generator);
        cout << Studentas.namudarbai[i] << " ";
    }
    Studentas.egzpazymys = distribution(generator);
    cout << endl << "Sugeneruotas egzamino pazymys:  " << Studentas.egzpazymys << endl << endl;

}

void galutinisvidurkis(Studentas* group, int n){
    double vidurkis;
    for (int i=0; i<n; i++)
    {
        vidurkis = 0;
        for (int j=0; j<group[i].ND; j++)
        {
            vidurkis = vidurkis + group[i].namudarbai[j];
        }
        vidurkis = vidurkis / group[i].ND;
        group[i].galutinis = (vidurkis*0.4) + (group[i].egzpazymys*0.6);
    }
}

void galutinismediana(Studentas* group, int n){
    double mediana;
    for (int i=0; i<n; i++)
    {
        std::sort(group[i].namudarbai, group[i].namudarbai+group[i].ND);
        mediana = group[i].namudarbai[(group[i].ND/2)];
        if (group[i].ND%2 == 0)
        {
            mediana = (mediana + group[i].namudarbai[(group[i].ND/2)-1]) / 2;
        }
        group[i].galutinis = (mediana*0.4) + (group[i].egzpazymys*0.6);
    }
}

void print(Studentas* group, int n, bool ismediana){
    cout << endl;
    if (ismediana)
    {
        cout << "Vardas              Pavarde               medianaa" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i=0; i<n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].Vardas << string (20-group[i].Vardas.length(), ' ')
                 << group[i].Pavarde << string (21-group[i].Pavarde.length(), ' ')  << group[i].galutinis << endl;
        }
    }
    else
    {
        cout << "Vardas              Pavarde               Vidurkis" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i=0; i<n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].Vardas << string (20-group[i].Vardas.length(), ' ')
                 << group[i].Pavarde << string (21-group[i].Pavarde.length(), ' ')  << group[i].galutinis << endl;
        }
    }
}

int main(){
    Studentas *group;  
    int n;           
    bool run = true; 
    bool PazymiuSkaicius;

    cout << "Iveskite studentu skaiciu:   ";
    n = std::stoi(getDigits());
    group = new Studentas[n];

    for (int i=0; i<n; i++)
    {
        cout << "Iveskite studento varda:   ";
        do {
           cin >> group[i].Vardas;
           cout << endl;
        }
        while(!validateName(group[i].Vardas));

        cout << "Iveskite studento pavarde:   ";
        do{
            cin >> group[i].Pavarde;
            cout << endl;
        }
        while(!validateName(group[i].Pavarde));

        string anspazymys;
        cout << "Ar studento pazymiu kiekis zinomas? 'T' - taip, 'N' - ne:   ";
        do{
            cin >> anspazymys;
            if(anspazymys == "t" || anspazymys == "T")
            {
                int temp;
                cout << "Iveskite pazymiu kieki:   ";
                do {
                    temp = std::stoi(getDigits());
                    if (temp > 0)
                    {
                        group[i].ND = temp;
                        run = false;
                    }
                    else
                    {
                        cout << "Pazymiu kiekis negali buti mazesnis arba lygus nuliui" << endl;
                        cout << "Iveskite is naujo:   ";
                        run = true;
                    }
                }
                while(run);
                PazymiuSkaicius = true;
            }
            else if (anspazymys == "n" || anspazymys == "N")
            {
                PazymiuSkaicius = false;
                run = false;
            }
            else
            {
                cout << endl;
                cout << "Klaidingas ivedimas" << endl;
                cout << "Iveskite is naujo:   ";
                run = true;
            }
        }
        while(run);

        string ansRandom;
        cout <<"Ar pazymius sugeneruotini atsitiktiniu budu? 'T' - taip, 'N' - ne:   ";
        do {
            cin >> ansRandom;
            if (ansRandom == "t" || ansRandom == "T")
            {
                cout << endl;
                randomgrades(PazymiuSkaicius, group[i]);
                run = false;
            }
            else if (ansRandom == "n" || ansRandom == "N")
            {
                namudarbai(PazymiuSkaicius, group[i]);
                cout << endl <<"Iveskite studento egzamino pazymi:   ";
                group[i].egzpazymys = egzaminas();
                run = false;
            }
            else
            {
            cout << endl;
            cout << "Klaidingas ivedimas" << endl;
            cout << "Iveskite is naujo:   ";
            run = true;
            }
        }
        while(run);

    }

    string ansmediana;
    cout << "Ar norite rezultate matyti medianaa? 'T' - taip, 'N' - ne:    ";
    do{
        cin >> ansmediana;
        if (ansmediana == "t" || ansmediana == "T")
        {
            galutinismediana(group, n);
            print(group, n, true);
            run = false;
        }
        else if (ansmediana == "n" || ansmediana == "N")
        {
            galutinisvidurkis(group, n);
            print(group, n, false);
            run = false;
        }
        else
        {
            cout << endl;
            cout << "Klaidingas ivedimas" << endl;
            cout << "Iveskite is naujo:   ";
            run = true;
        }
    }
    while(run);
}
