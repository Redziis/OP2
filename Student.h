//
// Created by stolo on 2021-04-21.
//

#ifndef V1_1_STUDENT_H
#define V1_1_STUDENT_H

#include "General.h"
#include <iostream>
#include <ios>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iterator>
#include <exception>
#include <list>
#include <deque>
#include <direct.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::deque;
using std::strcmp;


class Human {
protected:
    string firstName, lastName;
public:
    Human() = default;
    virtual ~Human() = 0;
    void setFirstName(string Name) ;
    void setLastName(string name) ;
    string getFirstName() const ;
    string getLastName() const ;
};


class Student: public Human {
private:
    vector<int> homeworkGrades;
    int homeworkSize = 0, examGrade{};
    double finalGrade{};
public:
    Student();
    Student(const Student& student);
    Student(const string FirstName, const string LastName, vector<int> Grades );
    ~Student();

    void addGrade(int Grade);
    void setExamGrade(int Exam);
    void setFinalGrade(double Grade);

    int getHomeworkSize() const;
    int getHomeworkGrade(int index) const;
    int getExamGrade() const;
    double getFinalGrade() const;
    vector<int> getGrades() const;

    void removeLastGrade();

    Student& operator=(const Student& student);

    void finalGradeAverage();
    void finalGradeMedian();
};

void homeworkGrades(bool, Student&, int);
int getExam();
void generateGrades(bool, Student&, int);

void print(vector<Student>&, bool);


#endif //V1_1_STUDENT_H
