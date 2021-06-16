#include "Student.h"
#include "General.h"

void homeworkGrades(bool gradeNumber, student& Student) {
    bool run = true;
    string Grade;
    int temp;
    if (gradeNumber)
    {
        for (int i = 0; i < Student.homeworkSize; i++)
        {
            do {
                cout << Student.homeworkGrades.size() + 1 << ". Enter grade: ";
                cin >> Grade;
                try
                {
                    temp = std::stoi(Grade);
                    if (temp <= 10 && temp >= 0)
                    {
                        Student.homeworkGrades.push_back(temp);
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
            cout << Student.homeworkGrades.size() + 1 << ". Enter grade: ";
            cin >> Grade;

            if (Grade == "end" || Grade == "END")
            {
                Student.homeworkSize = Student.homeworkGrades.size();
                Student.homeworkGrades.shrink_to_fit();
                run = false;
            }
            else
            {
                try
                {
                    temp = std::stoi(Grade);

                    if (temp <= 10 && temp >= 0)
                    {
                        Student.homeworkGrades.push_back(temp);
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

            if (Student.homeworkGrades.empty() && (Grade == "end" || Grade == "END"))
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

void generateGrades(bool gradeNumber, student& Student) {
    using chronoClock = std::chrono::high_resolution_clock;
    unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10);

    if (!gradeNumber)
    {
        std::uniform_int_distribution<int> distributionSize(1, 15);
        Student.homeworkSize = distributionSize(generator);
    }

    cout << "Generated " << Student.homeworkSize << " homework grades: ";
    for (int i = 0; i < Student.homeworkSize; i++)
    {
        Student.homeworkGrades.push_back(distribution(generator));
        cout << Student.homeworkGrades[i] << " ";
    }
    Student.examGrade = distribution(generator);
    cout << endl << "Generated exam grade: " << Student.examGrade << endl << endl;

}

//Calculates final grade with average grade


//Prints results

void print(vector<student>& group, int n, bool isMedian) {
    cout << endl;
    if (isMedian)
    {
        cout << "First name          Last name           Final grade(median)" << endl;
    }
    else
    {
        cout << "First name          Last name           Final grade(average)" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
     {
        cout << std::setprecision(2) << std::fixed << group[i].firstName << string(20 - group[i].firstName.length(), ' ')
             << group[i].lastName << string(21 - group[i].lastName.length(), ' ') << group[i].finalGrade << endl;
    }
    
}
