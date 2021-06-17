#ifndef STUDENTFILE_H_INCLUDED
#define STUDENTFILE_H_INCLUDED

#include "Student.h"
#include "General.h"

void bufferRead(vector<Student>&);

void writeToFile(vector<Student>&, bool);
void writeToFile(vector<Student>&, vector<Student>&, bool);

void generateStudents();

bool compareByLastName(const Student&, const Student&);
bool compareByFinalGrade(const Student&, const Student&);
bool isGood(const Student&);

void sortStudents(list<Student>&, list<Student>&, list<Student>&);
void sortStudents2(list<Student>&, list<Student>&);

template <class T>
void sortStudents(T& group, T& groupGood, T& groupBad) {

    std::sort(group.begin(), group.end(), compareByFinalGrade);
    auto it = std::find_if(group.begin(), group.end(), isGood);

    std::copy(it, group.end(), std::back_inserter(groupGood));
    std::copy(group.begin(), it, std::back_inserter(groupBad));

    std::sort(groupGood.begin(), groupGood.end(), compareByLastName);
    std::sort(groupBad.begin(), groupBad.end(), compareByLastName);
}


template <class T>
void sortStudents2(T& groupBad, T& groupGood) {

    std::sort(groupBad.begin(), groupBad.end(), compareByFinalGrade);
    auto it = std::find_if(groupBad.begin(), groupBad.end(), isGood);

    std::copy(it, groupBad.end(), std::back_inserter(groupGood));

    groupBad.erase(it, groupBad.end());

    std::sort(groupGood.begin(), groupGood.end(), compareByLastName);
    std::sort(groupBad.begin(), groupBad.end(), compareByLastName);
}
#endif // STUDENTFILE_H_INCLUDED