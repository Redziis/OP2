//
// Created by stolo on 2021-04-21.
//

#include "Student.h"
// Student class functions:

Student::Student() {}

Student::~Student() {
    homeworkGrades.clear();
    homeworkGrades.shrink_to_fit();
}

void Student::setFirstName(string Name) { firstName = Name; }

void Student::setLastName(string Name) { lastName = Name; }

void Student::addGrade(int Grade) {
    homeworkGrades.push_back(Grade);
    homeworkSize = homeworkSize + 1;
    homeworkGrades.shrink_to_fit();
}

void Student::setExamGrade(int Exam) { examGrade = Exam; }

void Student::setFinalGrade(double Grade) { finalGrade = Grade; }

string Student::getFirstName() const { return firstName; }

string Student::getLastName() const { return lastName; }

int Student::getHomeworkSize() const { return homeworkSize; }

int Student::getHomeworkGrade(int index) const { return homeworkGrades.at(index); }

int Student::getExamGrade() const { return examGrade; }

double Student::getFinalGrade() const { return finalGrade;}

void Student::removeLastGrade() {
    homeworkGrades.pop_back();
    homeworkSize = homeworkSize - 1;
    homeworkGrades.shrink_to_fit();
}


void Student::finalGradeAverage() {
    double average;
    average = 0;
    for (int j = 0; j < getHomeworkSize(); j++)
    {
        average = average + getHomeworkGrade(j);
    }
    average = average / getHomeworkSize();
    setFinalGrade((average * 0.4) + (getExamGrade() * 0.6));
}

void Student::finalGradeMedian() {
    double median;
    std::sort(homeworkGrades.begin(), homeworkGrades.end());
    median = getHomeworkGrade(getHomeworkSize() / 2);
    if (getHomeworkSize() % 2 == 0)
    {
        median = (median + getHomeworkGrade((getHomeworkSize() / 2) - 1)) / 2;
    }
    setFinalGrade((median * 0.4) + (getExamGrade() * 0.6));
}


// Program functions:

void homeworkGrades(bool gradeNumber, Student& Student, int homeworkSize) {
    bool run = true;
    string Grade;
    int temp;
    if (gradeNumber)
    {
        for (int i = 0; i < homeworkSize; i++)
        {
            do {
                cout << Student.getHomeworkSize() + 1 << ". Enter grade: ";
                cin >> Grade;
                try
                {
                    temp = std::stoi(Grade);
                    if (temp <= 10 && temp >= 0)
                    {
                        Student.addGrade(temp);
                        run = false;
                    }
                    else
                    {
                        cout << "Error: invalid grade" << endl;
                        run = true;
                    }
                }
                catch (std::exception& e)
                {
                    cout << "Error: invalid grade" << endl;
                    run = true;
                }
            }             while (run);
        }
    }
    else
    {
        cout << endl << "To finish entering grades type in 'end'" << endl;
        do {
            cout << Student.getHomeworkSize() + 1 << ". Enter grade: ";
            cin >> Grade;

            if (Grade == "end" || Grade == "END")
            {
                run = false;
            }
            else
            {
                try
                {
                    temp = std::stoi(Grade);

                    if (temp <= 10 && temp >= 0)
                    {
                        Student.addGrade(temp);
                    }
                    else
                    {
                        cout << "Error: invalid grade" << endl;
                    }
                }
                catch (std::exception& e)
                {
                    cout << "Error: invalid grade" << endl;
                }
            }

            if (Student.getHomeworkSize() == 0 && (Grade == "end" || Grade == "END"))
            {
                cout << "Error! Please enter at least one grade" << endl;
                run = true;
            }
        }         while (run);
    }
}

//Gets exam grade and checks it

int getExam() {
    int Grade;
    bool valid = false;
    do
    {
        try
        {
            Grade = std::stoi(getDigits());
        }
        catch (std::exception& e)
        {
            cout << "Error: number entered is to big." << endl;
            cout << "Try again: ";
        }

        if (Grade > 10)
        {
            cout << "Error: invalid grade" << endl;
            cout << "Try to enter exam grade again: ";
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    return Grade;
}

//Generates random homework grades and exam grade

void generateGrades(bool gradeNumber, Student& Student, int homeworkSize) {
    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);

    if (!gradeNumber)
    {
        std::uniform_int_distribution<int> distributionSize(1, 15);
        homeworkSize = distributionSize(generator);
    }

    cout << "Generated " << homeworkSize << " homework grades: ";
    for (int i = 0; i < homeworkSize; i++)
    {
        Student.addGrade(distribution(generator));
        cout << Student.getHomeworkGrade(i) << " ";
    }
    Student.setExamGrade(distribution(generator));
    cout << endl << "Generated exam grade: " << Student.getExamGrade() << endl << endl;

}

//Calculates final grade with average grade


//Prints results

void print(vector<Student>& group, bool isMedian) {
    cout << endl;
    if (isMedian) {
        cout << "First name          Last name           Final grade(median)" << endl;
    } else {
        cout << "First name          Last name           Final grade(average)" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    for (Student &i : group) {
        cout << std::setprecision(2) << std::fixed << i.getFirstName() << string(20 - i.getFirstName().length(), ' ')
             << i.getLastName() << string(21 - i.getLastName().length(), ' ') << i.getFinalGrade() << endl;
    }
}