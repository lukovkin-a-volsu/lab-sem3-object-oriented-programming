#ifndef RECORD_H
#define RECORD_H

#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;

#define SEPARATOR "----------------------------------------"

class Record
{
protected:
    string _sport;
    string _discipline;
    string _type;
    string _gender; // female=0/male=1
    Date _date;     // 00.00.0000
    string _country;
    string _achievement;
    void _setGender(int n);
public:
    Record();
    friend void operator<<(ostream &, Record &);  // output
    friend int operator>>(istream &, Record &);  // input
    friend int operator>>(ifstream &, Record &);  // reading from File
    friend void operator<<(ofstream &, Record &); // writing to File
    friend bool operator==(Record &, Record &);
    string getSport();
    string getType();
    string getDate();
    int getYear();
    string getGender();
    bool getGenderBool();
    virtual void about();
    virtual void toFileUnsafe(ofstream&);
};

#endif