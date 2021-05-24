#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#pragma once

#include <iostream>
#include <string>
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

struct Studentas
{
    string Vardas, Pavarde;
    vector<int> namudarbai;
    int ND, egzpazymys;
    double galutinis;
};

void namudarbai(bool, Studentas&);
bool isdigits(string&);
bool validateName(string);
string getDigits();
int egzaminas();
void randomgrades(bool, Studentas&);
void galutinisvidurkis(vector<Studentas>&, int);
void galutinismediana(vector<Studentas>&, int);
void print(vector<Studentas>&, int, bool);
void bufferRead(vector<Studentas>&);
bool palygintiPavarde(const Studentas&, const Studentas&);
void writeToFile(vector<Studentas>&, int, bool);


#endif // Studentas_H_INCLUDED
