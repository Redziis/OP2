#ifndef STUDENTFILE_H_INCLUDED
#define STUDENTFILE_H_INCLUDED

#include "Student.h"
#include "General.h"

void bufferRead(vector<student>&);
void writeToFile(vector<student>&, int, bool);
void writeToFile(vector<student>&, vector<student>&, bool);
void generateStudents();
void sortStudents(vector<student>&, vector<student>&, vector<student>&);
bool compareByLastName(const student&, const student&);
bool compareByFinalGrade(const student&, const student&);
bool isGood(const student&);

#endif // STUDENTFILE_H_INCLUDED