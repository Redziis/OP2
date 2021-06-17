
#include "Student.h"
#include "StudentFile.h"
#include "Test.h"

int main(int argc, char* argv[]) {
    vector<Student> group;  // student vector
    vector<Student> groupGood;
    vector<Student> groupBad;
    list<Student> lgroup;
    list<Student> lgroupGood;
    list<Student> lgroupBad;
    deque<Student> dgroup;
    deque<Student> dgroupGood;
    deque<Student> dgroupBad;
    string fileName = "test/kursiokai";
    int n;                  // number of students
    int homeworkSize = NULL;
    bool run = true;        // used for while loops in main
    bool gradeNumber;       // flag for if grade number is known
    char readfile;
    char ansMedian;
    char ansfile;

    if (argc > 1 && strcmp(argv[1], "test1") == 0)
    {
        string test = "test";
        string dir = "test/method_1";
        int dir_ = _mkdir(test.c_str());
        int dir__ = _mkdir(dir.c_str());
        for (int i = 1000; i <= 10000000; i = i * 10)
        {
            generateStudents(i, fileName);
        }

        if (argc > 2 && strcmp(argv[2], "vector") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nVector\n";
                Test(group, groupGood, groupBad, fileName, i, dir);
            }
        }
        else if (argc > 2 && strcmp(argv[2], "list") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nList\n";
                Test(lgroup, lgroupGood, lgroupBad, fileName, i, dir);
            }
        }
        else if (argc > 2 && strcmp(argv[2], "deque") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nDeque\n";
                Test(dgroup, dgroupGood, dgroupBad, fileName, i, dir);
            }
        }
        else
        {
            exit(0);
        }

    }
    else if (argc > 1 && strcmp(argv[1], "test2") == 0)
    {
        string test = "test";
        string dir = "test/method_2";
        int dir_ = _mkdir(test.c_str());
        int dir__ = _mkdir(dir.c_str());
        for (int i = 1000; i <= 10000000; i = i * 10)
        {
            generateStudents(i, fileName);
        }

        if (argc > 2 && strcmp(argv[2], "vector") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nVector\n";
                Test2(group, groupGood, fileName, i, dir);
            }
        }
        else if (argc > 2 && strcmp(argv[2], "list") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nList\n";
                Test2(lgroup, lgroupGood, fileName, i, dir);
            }
        }
        else if (argc > 2 && strcmp(argv[2], "deque") == 0)
        {
            for (int i = 1000; i <= 10000000; i = i * 10)
            {
                cout << "\nDeque\n";
                Test2(dgroup, dgroupGood, fileName, i, dir);
            }
        }
        else
        {
            exit(0);
        }

    }
    else
    {
        cout << "Get students from file or enter manually?(f/m): ";
        do {
            cin >> readfile;
            if (std::toupper(readfile) == 'F')
            {
                cout << "Use exiting file or generate?(e/g): ";
                do {
                    cin >> ansfile;
                    if (std::toupper(ansfile) == 'E')
                    {
                        cout << "Use median for final grade?(y/n): ";
                        do {
                            cin >> ansMedian;
                            if (std::toupper(ansMedian) == 'Y')
                            {
                                bufferRead(group);
                                auto start2 = std::chrono::high_resolution_clock::now();
                                cout << "Calculating..." << endl;
                                for(Student& i : group)
                                {
                                    i.finalGradeMedian();
                                }
                                std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
                                std::cout << "Calculating took " << diff2.count() << " s" << endl;
                                auto start3 = std::chrono::high_resolution_clock::now();
                                cout << "Writing..." << endl;
                                writeToFile(group, true);
                                run = false;
                                std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
                                std::cout << "Writing took " << diff3.count() << " s" << endl;
                            }
                            else if (std::toupper(ansMedian) == 'N')
                            {
                                bufferRead(group);
                                auto start2 = std::chrono::high_resolution_clock::now();
                                cout << "Calculating..." << endl;
                                for(Student& i : group)
                                {
                                    i.finalGradeAverage();
                                }
                                std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
                                std::cout << "Calculating took " << diff2.count() << " s" << endl;
                                auto start3 = std::chrono::high_resolution_clock::now();
                                cout << "Writing..." << endl;
                                writeToFile(group, false);
                                run = false;
                                std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
                                std::cout << "Writing took " << diff3.count() << " s" << endl;
                            }
                            else
                            {
                                cout << endl;
                                cout << "Error: bad entry" << endl;
                                cout << "Try again(y/n): ";
                                run = true;
                            }
                        } while (run);
                        run = false;
                    }
                    else if (std::toupper(ansfile) == 'G')
                    {

                        generateStudents();
                        bufferRead(group);

                        auto start2 = std::chrono::high_resolution_clock::now();
                        cout << "Calculating..." << endl;

                        for(Student& i : group)
                        {
                            i.finalGradeMedian();
                        }

                        std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
                        std::cout << "Calculating took " << diff2.count() << " s" << endl;
                        cout << "Sorting..." << endl;
                        auto start = std::chrono::high_resolution_clock::now();

                        sortStudents(group, groupGood, groupBad);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        std::cout << "Sorting took " << diff.count() << " s" << endl;
                        auto start3 = std::chrono::high_resolution_clock::now();
                        cout << "Writing..." << endl;

                        writeToFile(groupGood, groupBad, false);

                        std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
                        std::cout << "Writing took " << diff3.count() << " s" << endl;
                        run = false;

                    }
                    else
                    {
                        cout << endl;
                        cout << "Error: bad entry" << endl;
                        cout << "Try again(y/n): ";
                        run = true;
                    }
                } while (run);
            }
            else if (std::toupper(readfile) == 'M')
            {
                cout << "Enter the number of students: ";

                do
                {
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
                } while (run);

                for (int i = 0; i < n; i++)
                {
                    Student temp;
                    string name;
                    cout << "Enter students first name: ";
                    do {
                        cin >> name;
                        temp.setFirstName(name);
                        cout << endl;
                    } while (!validateName(name));

                    cout << "Enter students last name: ";
                    do {
                        cin >> name;
                        temp.setLastName(name);
                        cout << endl;
                    } while (!validateName(name));

                    char ansGrade;
                    cout << "Is the number of grades known?(y/n): ";
                    do {
                        cin >> ansGrade;
                        if (std::toupper(ansGrade) == 'Y')
                        {
                            cout << "Enter the number of grades: ";
                            do {
                                do {
                                    try
                                    {
                                        homeworkSize = std::stoi(getDigits());
                                        run = false;
                                    }
                                    catch (std::exception& e)
                                    {
                                        cout << "Error: number entered is to big." << endl;
                                        cout << "Try again: ";
                                        run = true;
                                    }
                                } while (run);

                                if (homeworkSize > 0)
                                {
                                    run = false;
                                }
                                else
                                {
                                    cout << "Error! the number of grades cant be 0" << endl;
                                    cout << "Try to enter your number again: ";
                                    run = true;
                                }
                            } while (run);
                            gradeNumber = true;
                        }
                        else if (std::toupper(ansGrade) == 'N')
                        {
                            cout << endl;
                            gradeNumber = false;
                            run = false;
                        }
                        else
                        {
                            cout << endl;
                            cout << "Error: bad entry" << endl;
                            cout << "Try again(y/n): ";
                            run = true;
                        }
                    } while (run);

                    char ansRandom;
                    cout << "Generate grades randomly?(y/n): ";
                    do {
                        cin >> ansRandom;
                        if (std::toupper(ansRandom) == 'Y')
                        {
                            cout << endl;
                            generateGrades(gradeNumber, temp, homeworkSize);
                            run = false;
                        }
                        else if (std::toupper(ansRandom) == 'N')
                        {
                            homeworkGrades(gradeNumber, temp, homeworkSize);
                            cout << endl << "Enter students exam grade: ";
                            temp.setExamGrade(getExam());
                            run = false;
                        }
                        else
                        {
                            cout << endl;
                            cout << "Error: bad entry" << endl;
                            cout << "Try again(y/n): ";
                            run = true;
                        }
                    } while (run);
                    group.push_back(temp);
                }
                group.shrink_to_fit();

                cout << "Use median for final grade?(y/n): ";
                do {
                    cin >> ansMedian;
                    if (std::toupper(ansMedian) == 'Y')
                    {
                        for(Student& i : group)
                        {
                            i.finalGradeMedian();
                        }
                        print(group, true);
                        run = false;
                    }
                    else if (std::toupper(ansMedian) == 'N')
                    {
                        for(Student& i : group)
                        {
                            i.finalGradeAverage();
                        }
                        print(group, false);
                        run = false;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Error: bad entry" << endl;
                        cout << "Try again(y/n): ";
                        run = true;
                    }
                } while (run);
                run = false;
            }
            else
            {
                cout << endl;
                cout << "Error: bad entry" << endl;
                cout << "Try again(f/m): ";
            }
        } while (run);
        system("pause");
    }
}
