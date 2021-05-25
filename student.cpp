#include "student.h"
#include "general.h"

bool palygintiPavarde(const Studentas& a, const Studentas& b) {
    return a.Pavarde < b.Pavarde;
}

void bufferRead(vector<Studentas>& group) {
    string eil;
    std::stringstream startBuffer;
    std::stringstream lines;
    Studentas temp;
    std::fstream input;
    int j = 0;
    int k;
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Skaitoma..." << endl;
    try
    {
        input.open("kursiokai.txt");
        if (input.fail())
        {
            throw 1;
        }
    }
    catch(int e)
   {
        cout << "Nepavyko atidaryti failo" << endl;
        cout << "Isitikinkite ar failo pavadinimas 'kursiokai.txt' yra reikiamoje direktorijoje" << endl;
        system("pause");
        exit(e);
    }

    std::getline(input, eil);
    startBuffer << input.rdbuf();
    input.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Skaitymas truko " << diff.count() << " s" << endl;


    auto start2 = std::chrono::high_resolution_clock::now();
    cout << "Apdorojama..." << endl;
    while (startBuffer) {
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;
            
            lines >> temp.Vardas >>temp.Pavarde;  

            while (!lines.eof())
            {
                lines >> k;
                temp.namudarbai.push_back(k);
            }
            lines.clear();
            temp.egzpazymys = temp.namudarbai[temp.namudarbai.size() - 1];
            temp.namudarbai.pop_back();
            temp.namudarbai.shrink_to_fit();
            temp.ND = temp.namudarbai.size();
            group.push_back(temp);
            temp = {};
        }
        else break;
    }
    startBuffer.clear();

    std::sort(group.begin(), group.end(), palygintiPavarde);
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Apdorojimas truko: " << diff2.count() << " s" << endl;
}

void writeToFile(vector<Studentas>& group, int n, bool ismediana) {
    std::ofstream output("output.txt");
    std::stringstream endBuffer;
    if (ismediana)
    {
        endBuffer << "Vardas              Pavarde              Mediana\n";
        endBuffer << "----------------------------------------------------------\n";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            endBuffer << std::setprecision(2) << std::fixed << group.at(i).Vardas << string(20 - group.at(i).Vardas.length(), ' ')
                << group.at(i).Pavarde << string(21 - group.at(i).Pavarde.length(), ' ') << group.at(i).galutinis << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
        std::cout << "Rasymas i bufferi truko " << diff.count() << " s" << endl;
    }
    else
    {
        endBuffer << "Vardas              Pavarde              Vidurkis\n";
        endBuffer << "-----------------------------------------------------------\n";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            endBuffer << std::setprecision(2) << std::fixed << group.at(i).Vardas << string(20 - group.at(i).Vardas.length(), ' ')
                << group.at(i).Pavarde << string(21 - group.at(i).Pavarde.length(), ' ') << group.at(i).galutinis << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
        std::cout << "Rasymas i bufferi truko " << diff.count() << " s" <<endl;
    }

    output << endBuffer.str();
    output.close();
}


void namudarbai(bool PazymiuSkaicius, Studentas& Studentas) {
    bool run = true;
    string pazymys;
    int temp;
    if (PazymiuSkaicius)
    {
        for (int i = 0; i < Studentas.ND; i++)
        {
            do {
                cout << Studentas.namudarbai.size() + 1 << ". Iveskite pazymys: ";
                cin >> pazymys;
                try{
                    temp = std::stoi(pazymys);
                    if (temp <= 10 && temp >= 0)
                    {
                        Studentas.namudarbai.push_back(temp);
                        run = false;
                    }
                    else
                    {
                        cout << "Klaidingas pazymys" << endl;
                        run = true;
                    }
                }
                catch (std::exception& e)
                {
                    cout << "Klaidingas pazymys" << endl;
                    run = true;
                }
            }
            while (run);
        }
    }
    else
    {
        cout << endl << "Norint baigti pazymiu ivesti rasykite 'end'" << endl;
        do {
            cout << Studentas.namudarbai.size() + 1 << ". Iveskite pazymi: ";
            cin >> pazymys;
             if (pazymys == "end" || pazymys == "END")
            {
                Studentas.ND = Studentas.namudarbai.size();
                Studentas.namudarbai.shrink_to_fit();
                run = false;
            }
            else
            {
                try{
                    temp = std::stoi(pazymys);

                    if ( temp <= 10 && temp >= 0)
                    {
                        Studentas.namudarbai.push_back(temp);
                    }
                    else
                    {
                        cout << "Klaidingas pazymys" << endl;
                    }
                }
                catch (std::exception& e)
                {
                    cout << "Klaidingas pazymys" << endl;
                }
            }
            if (Studentas.namudarbai.empty() && (pazymys == "end" || pazymys == "END"))
            {
                cout << "Klaida! Iveskite bent viena skaiciu" << endl;
                run = true;
            }
        }
        while (run);
    }
}


int egzaminas() {
    int pazymys;
    bool valid = false;
    do
    {
        try{

            pazymys = std::stoi(getDigits());
        }
        catch (std::exception& e)
        {
            cout << "Skaicius per didelis" << endl;
            cout << "Bandykite ivesti is naujo ";

        }
        if (pazymys > 10)
        {
            cout << "Klaidingas pazymys" << endl;
            cout << "Bandykite ivesti is naujo ";
        }
        else
        {
            valid = true;
        }
    } 
    while (!valid);

    return pazymys;
}


void randomgrades(bool PazymiuSkaicius, Studentas& Studentas) {
    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);

    if (!PazymiuSkaicius)
    {
        std::uniform_int_distribution<int> distributionSize(1, 15);
        Studentas.ND = distributionSize(generator);
    }

    cout << "Sugeneruoti " << Studentas.ND << " namu darbu rezultatai: ";
    for (int i = 0; i < Studentas.ND; i++)
    {
        Studentas.namudarbai.push_back(distribution(generator));
        cout << Studentas.namudarbai[i] << " ";
    }
    Studentas.egzpazymys = distribution(generator);
    cout << endl << "Sugeneruotas egzamino rezultatas: " << Studentas.egzpazymys << endl << endl;

}


void galutinisvidurkis(vector<Studentas>& group, int n) {
    double vidurkis;
    for (int i = 0; i < n; i++)
    {
        vidurkis = 0;
        for (int j = 0; j < group[i].ND; j++)
        {
            vidurkis = vidurkis + group[i].namudarbai[j];
        }
        vidurkis = vidurkis / group[i].ND;
        group[i].galutinis = (vidurkis * 0.4) + (group[i].egzpazymys * 0.6);
    }
}

void galutinismediana(vector<Studentas>& group, int n) {
    double mediana;
    for (int i = 0; i < n; i++)
    {
        std::sort(group[i].namudarbai.begin(), group[i].namudarbai.end());
        mediana = group[i].namudarbai[(group[i].ND / 2)];
        if (group[i].ND % 2 == 0)
        {
            mediana = (mediana + group[i].namudarbai[(group[i].ND / 2) - 1]) / 2;
        }
        group[i].galutinis = (mediana * 0.4) + (group[i].egzpazymys * 0.6);
    }
}

void print(vector<Studentas>& group, int n, bool ismediana) {
    cout << endl;
    if (ismediana)
    {
        cout << "Vardas          Pavarde           Mediana" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].Vardas << string(20 - group[i].Vardas.length(), ' ')
                << group[i].Pavarde << string(21 - group[i].Pavarde.length(), ' ') << group[i].galutinis << endl;
        }
    }
    else
    {
        cout << "Vardas          Pavarde           Vidurkis" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << std::setprecision(2) << std::fixed << group[i].Vardas << string(20 - group[i].Vardas.length(), ' ')
                << group[i].Pavarde << string(21 - group[i].Pavarde.length(), ' ') << group[i].galutinis << endl;
        }
    }
}
