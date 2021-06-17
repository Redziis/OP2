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

class Student {
private:
    string firstName, lastName;
    vector<int> homeworkGrades;
    int homeworkSize = 0, examGrade;
    double finalGrade;
public:
    Student();
    //Student( string firstName, string lastName);
    ~Student();

    void setFirstName(string name);
    void setLastName(string name);
    void addGrade(int Grade);
    void setExamGrade(int Exam);
    void setFinalGrade(double Grade);

    string getFirstName() const;
    string getLastName() const;
    int getHomeworkSize() const;
    int getHomeworkGrade(int index) const;
    int getExamGrade() const;
    double getFinalGrade() const;

    void removeLastGrade();

    void finalGradeAverage();
    void finalGradeMedian();
};

void homeworkGrades(bool, Student&, int);
int getExam();
void generateGrades(bool, Student&, int);

void print(vector<Student>&, bool);


#endif //V1_1_STUDENT_H
