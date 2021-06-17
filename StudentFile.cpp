#include "StudentFile.h"

bool compareByLastName(const Student& a, const Student& b) {
    return a.getLastName() < b.getLastName();
}

bool compareByFinalGrade(const Student& a, const Student& b) {
    return a.getFinalGrade() < b.getFinalGrade();
}

bool isGood(const Student& a) {
    return a.getFinalGrade() >= 5;
}

void bufferRead(vector<Student>& group) {
    string eil, name;
    std::stringstream startBuffer;
    std::stringstream lines;
    std::fstream input;
    int k;
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Reading..." << endl;
    try
    {
        input.open("kursiokai.txt");
        if (input.fail())
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "Failed to open file" << endl;
        cout << "Make sure file 'kursiokai.txt' is in the right directory" << endl;
        system("pause");
        exit(e);
    }
    std::getline(input, eil);
    startBuffer << input.rdbuf();
    input.close();


    while (startBuffer) {
        if (!startBuffer.eof()) {
            std::getline(startBuffer, eil);
            lines << eil;
            Student temp;
            lines >> name;
            temp.setFirstName(name);
            lines>> name;
            temp.setLastName(name);
            while (!lines.eof())
            {
                lines >> k;
                temp.addGrade(k);
            }
            lines.clear();
            temp.setExamGrade(temp.getHomeworkGrade(temp.getHomeworkSize()-1));
            temp.removeLastGrade();
            group.push_back(temp);
        }
        else break;
    }
    startBuffer.clear();

    std::sort(group.begin(), group.end(), compareByLastName);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Reading took " << diff.count() << " s" << endl;
}

void writeToFile(vector<Student>& group, bool isMedian) {
    std::ofstream output("output.txt");
    std::stringstream endBuffer;

    if (isMedian)
    {
        endBuffer << "First name          Last name           Final grade(median)\n";
    }
    else
    {
        endBuffer << "First name          Last name           Final grade(average)\n";
    }

    endBuffer << "-----------------------------------------------------------\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (Student& i : group)
    {
        endBuffer << std::setprecision(2) << std::fixed << i.getFirstName() << string(20 - i.getFirstName().length(), ' ')
                  << i.getLastName() << string(21 - i.getLastName().length(), ' ') << i.getFinalGrade() << endl;
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "writing to buffer took " << diff.count() << " s" << endl;

    output << endBuffer.str();
    output.close();
}


void writeToFile(vector<Student>& groupGood, vector<Student>& groupBad, bool isMedian) {
    std::ofstream output1("kietiakiai.txt");
    std::ofstream output2("vargšiukai.txt");
    std::stringstream endBuffer1;
    std::stringstream endBuffer2;

    if (isMedian)
    {
        endBuffer1 << "First name          Last name           Final grade(median)\n";
        endBuffer2 << "First name          Last name           Final grade(median)\n";
    }
    else
    {
        endBuffer1 << "First name          Last name           Final grade(average)\n";
        endBuffer2 << "First name          Last name           Final grade(average)\n";
    }

    endBuffer1 << "-----------------------------------------------------------\n";
    endBuffer2 << "-----------------------------------------------------------\n";

    auto start = std::chrono::high_resolution_clock::now();
    for (Student& i : groupGood)
    {
        endBuffer1 << std::setprecision(2) << std::fixed << i.getFirstName() << string(20 - i.getFirstName().length(), ' ')
                  << i.getLastName() << string(21 - i.getLastName().length(), ' ') << i.getFinalGrade() << endl;
    }

    for (Student& i : groupBad)
    {
        endBuffer2 << std::setprecision(2) << std::fixed << i.getFirstName() << string(20 - i.getFirstName().length(), ' ')
                  << i.getLastName() << string(21 - i.getLastName().length(), ' ') << i.getFinalGrade() << endl;
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "writing to buffer took " << diff.count() << " s" << endl;

    output1 << endBuffer1.str();
    output1.close();

    output2 << endBuffer2.str();
    output2.close();
}

void generateStudents() {
    std::ofstream output("kursiokai.txt");
    std::stringstream endBuffer;
    Student Student;
    int n;
    bool run = true;

    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);
    std::uniform_int_distribution<int> distributionSize(2, 20);


    cout << "Enter the number of students: ";
    do {
        try
        {
            n = std::stoi(getDigits());
            run = false;
        }
        catch (std::exception& e)
        {
            cout << "Error: number entered is to big." << endl;
            cout << "Try again: ";
            run = true;
        }
    }     while (run);

    cout << "Generating..." << endl;
    auto start = std::chrono::high_resolution_clock::now();

    int a = distributionSize(generator);

    for (int i = 1; i <= n; i++)
    {

        endBuffer << endl;
        int b = log10(i) + 1;
        endBuffer << "Vardas" << i << string(25 - (6 + b), ' ') << "Pavarde" << i << string(25 - (7 + b), ' ');
        for (int j = 0; j < a; j++)
        {
            endBuffer << distribution(generator) << "    ";
        }
    }
    output << endBuffer.str();
    output.close();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Generating took " << diff.count() << " s" << endl;
}

void sortStudents(list<Student>& group, list<Student>& groupGood, list<Student>& groupBad) {

    group.sort(compareByFinalGrade);
    auto it = std::find_if(group.begin(), group.end(), isGood);

    std::copy(it, group.end(), std::back_inserter(groupGood));
    std::copy(group.begin(), it, std::back_inserter(groupBad));

    groupGood.sort(compareByLastName);
    groupBad.sort(compareByLastName);
}

void sortStudents2(list<Student>& groupBad, list<Student>& groupGood) {

    groupBad.sort(compareByFinalGrade);
    auto it = std::find_if(groupBad.begin(), groupBad.end(), isGood);

    std::copy(it, groupBad.end(), std::back_inserter(groupGood));

    groupBad.erase(it, groupBad.end());

    groupGood.sort(compareByLastName);
    groupBad.sort(compareByLastName);
}
