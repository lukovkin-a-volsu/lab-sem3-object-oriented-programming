#ifndef RECORD_H
#define RECORD_H

#include "date.h"
#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Record
{
private:
    // fields
    string _sport;
    string _discipline;
    string _type;
    string _gender; // female=0/male=1
    Date _date;     // 00.00.0000
    string _country;
    string _achievement;
    // methods
    void _SetGender(int n);

public:
    void Print();
    int FromInput();
    void FromFile(ifstream &infile);
    void ToFile(ofstream &outfile);
    void Fill();
    string GetSport();
    string GetType();
    int GetYear();
    bool GetGenderBool();
};

#endif