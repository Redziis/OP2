#include "StudentFile.h"

bool compareByLastName(const student& a, const student& b) {
    return a.lastName < b.lastName;
}

bool compareByFinalGrade(const student& a, const student& b) {
    return a.finalGrade < b.finalGrade;
}

bool isGood(const student& a) {
    return a.finalGrade >= 5;
}

void bufferRead(vector<student>& group) {
    string eil;
    student temp;
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

            lines >> temp.firstName >> temp.lastName;

            while (!lines.eof())
            {
                lines >> k;
                temp.homeworkGrades.push_back(k);
            }
            lines.clear();
            temp.examGrade = temp.homeworkGrades.back();
            temp.homeworkGrades.pop_back();
            temp.homeworkGrades.shrink_to_fit();
            temp.homeworkSize = temp.homeworkGrades.size();
            group.push_back(temp);
            temp = {};
        }
        else break;
    }
    startBuffer.clear();

    std::sort(group.begin(), group.end(), compareByLastName);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Reading took " << diff.count() << " s" << endl;
}

void writeToFile(vector<student>& group, int n, bool isMedian) {
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
    for (int i = 0; i < n; i++)
    {
        endBuffer << std::setprecision(2) << std::fixed << group.at(i).firstName << string(20 - group.at(i).firstName.length(), ' ')
        << group.at(i).lastName << string(21 - group.at(i).lastName.length(), ' ') << group.at(i).finalGrade << endl;
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "writing to buffer took " << diff.count() << " s" << endl;
   
    output << endBuffer.str();
    output.close();
}


void writeToFile(vector<student>& groupGood, vector<student>& groupBad, bool isMedian) {
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
    for (student& i : groupGood)
    {
        endBuffer1 << std::setprecision(2) << std::fixed << i.firstName << string(20 - i.firstName.length(), ' ')
            << i.lastName << string(21 - i.lastName.length(), ' ') << i.finalGrade << endl;
    }

    for (student& i : groupBad)
    {
        endBuffer2 << std::setprecision(2) << std::fixed << i.firstName << string(20 - i.firstName.length(), ' ')
            << i.lastName << string(21 - i.lastName.length(), ' ') << i.finalGrade << endl;
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
    student Student;
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
    }     
    while (run);

    cout << "Generating..." << endl;
    auto start = std::chrono::high_resolution_clock::now();

    int a = distributionSize(generator);

    for (int i = 1; i <= n; i++)
    {

        endBuffer << endl;
        int b = log10(i) + 1;
        endBuffer << "Vardas" << i << string (25-(6+b),' ') << "Pavarde" << i << string(25 - (7 + b), ' ');
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

void sortStudents(vector<student>& group, vector<student>& groupGood, vector<student>& groupBad) {

    std::sort(group.begin(), group.end(), compareByFinalGrade);
    auto it = std::find_if(group.begin(), group.end(), isGood);

    std::copy(it, group.end(), std::back_inserter(groupGood));
    std::copy(group.begin(), it, std::back_inserter(groupBad));

    group.erase(group.begin(), group.end());

    std::sort(groupGood.begin(), groupGood.end(), compareByLastName);
    std::sort(groupBad.begin(), groupBad.end(), compareByLastName);
}