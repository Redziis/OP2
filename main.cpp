#include "student.h"
#include "general.h"

int main() {
    vector<Studentas> group;  
    int n;                  
    bool run = true;       
    bool PazymiuSkaicius;    

    string readfile;
    string ansmediana;
    
    cout << "Ar norite duomenis ivesti is failo(F) ar vedant ranka(R)? (F,R) ";
    do {
        cin >> readfile;
        if (readfile == "f" || readfile == "F")
        {
            cout << "Ar norite rezultate matyti mediana? 'T' - taip, 'N' - ne:  ";
            do {
                cin >> ansmediana;
                if (ansmediana == "t" || ansmediana == "T")
                {
                    bufferRead(group);
                    galutinismediana(group, group.size());
                    auto start3 = std::chrono::high_resolution_clock::now();
                    cout << "Rasoma..." << endl;
                    writeToFile(group, group.size(), true);
                    run = false;
                    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3; 
                    std::cout << "Rasymas truko " << diff3.count() << " s" << endl;
                }
                else if (ansmediana == "n" || ansmediana == "N")
                {
                    bufferRead(group);
                    galutinisvidurkis(group, group.size());
                    auto start3 = std::chrono::high_resolution_clock::now();
                    cout << "Rasoma..." << endl;
                    writeToFile(group, group.size(), false);
                    run = false;
                    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3; 
                    std::cout << "Rasymas truko " << diff3.count() << " s" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Klaidingas ivedimas" << endl;
                    cout << "Iveskite is naujo:   ";
                    run = true;
                }
            } 
            while (run);

            run = false;
        }
        else if (readfile == "r" || readfile == "R")
        {
            cout << "Iveskite studentu skaiciu:   ";

                do {
                    try
                    {
                        n = std::stoi(getDigits());
                        run = false;
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Ivestas skaicius per didelis" << endl;
                        cout << "Bandykite dar karta: ";
                        run = true;
                    }
                    
                } while (run);

                for (int i = 0; i < n; i++)
                {
                group.push_back(Studentas());

                cout << "Iveskite studento varda: ";
                do {
                    cin >> group[i].Vardas;
                    cout << endl;
                }
                while (!validateName(group[i].Vardas));

                cout << "Iveskite studento pavarde:   ";
                do {
                    cin >> group[i].Pavarde;
                    cout << endl;
                } while (!validateName(group[i].Pavarde));

                string anspazymys;
                cout << "Ar studento pazymiu kiekis zinomas? 'T' - taip, 'N' - ne:   ";
                do {
                    cin >> anspazymys;
                    if (anspazymys == "t" || anspazymys == "T")
                    {
                        int temp;
                        cout << "Iveskite pazymiu kieki:   ";
                        do {
                            do {
                                try
                                {
                                    temp = std::stoi(getDigits());
                                    run = false;
                                }
                                catch(const std::exception& e)
                                {
                                    cout << "Ivestas skaicius per didelis" << endl;
                                    cout << "Bandykite dar karta: ";
                                    run = true;
                                }
                            }                   while(run);

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
                        while (run);
                        PazymiuSkaicius = true;
                    }
                    else if (anspazymys == "n" || anspazymys == "N")
                    {
                        cout << endl;
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
                while (run);

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
                while (run);
            }
            group.shrink_to_fit();

            cout << "Ar norite rezultate matyti mediana? 'T' - taip, 'N' - ne:    ";
            do {
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
            while (run);
            run = false;
        }
        else
        {
            cout << endl;
            cout << "Klaidingas ivedimas" << endl;
            cout << "Iveskite is naujo:   ";
        }
    } 
    while (run);

    system("pause");
}
