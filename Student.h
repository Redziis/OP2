#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <ios>
#include <string>
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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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
void finalGradeAverage(vector<student>&, int);
void finalGradeMedian(vector<student>&, int);
void print(vector<student>&, int, bool);



#endif // STUDENT_H_INCLUDED
