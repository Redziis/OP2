#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

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

struct student
{
    string firstName, lastName;
    vector<int> homeworkGrades;
    int homeworkSize, examGrade;
    double finalGrade;
};

void homeworkGrades(bool, student&);
bool isdigits(string&);
bool validateName(string);
string getDigits();
int getExam();
void generateGrades(bool, student&);

void print(vector<student>&, int, bool);

template <class T>
void finalGradeAverage(T& group, int n) {
    double average;
    for (student& i : group)
    {
        average = 0;
        for (int j = 0; j < i.homeworkSize; j++)
        {
            average = average + i.homeworkGrades[j];
        }
        average = average / i.homeworkSize;
        i.finalGrade = (average * 0.4) + (i.examGrade * 0.6);
    }
}
template <class T>
void finalGradeMedian(T& group, int n) {
    double median;
    for (student& i : group)
    {
        std::sort(i.homeworkGrades.begin(), i.homeworkGrades.end());
        median = i.homeworkGrades[(i.homeworkSize / 2)];
        if (i.homeworkSize % 2 == 0)
        {
            median = (median + i.homeworkGrades[(i.homeworkSize / 2) - 1]) / 2;
        }
        i.finalGrade = (median * 0.4) + (i.examGrade * 0.6);
    }
}
#endif // STUDENT_H_INCLUDED
