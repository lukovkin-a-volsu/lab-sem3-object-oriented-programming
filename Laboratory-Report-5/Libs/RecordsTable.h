#ifndef RECORDSTABLE_H
#define RECORDSTABLE_H

#include "Record.h"
#include <vector>
#include <iomanip>
#include <filesystem>
#define lowSep "........................................"
#define sep "----------------------------------------"
#define pSep "++++++++++++++++++++++++++++++++++++++++"
#define hashSep "########################################"
#define outSep "-----------------OUTPUT-----------------"
using std::setw;
using std::vector;

class RecordsTable
{
private:
    string _name;
    vector<Record> _records;
public:
    ~RecordsTable();
    RecordsTable();
    RecordsTable(string);
    bool RemoveRecord(int);
    int GetSize();
    string GetName();
    RecordsTable* GetBySport(string);
    RecordsTable* GetFemWorldRecords(int);
    friend bool operator<<(ostream &, RecordsTable&);
    friend bool operator>>(istream &, RecordsTable&);
    friend bool operator>>(ifstream&, RecordsTable&);
    friend bool operator<<(ofstream&, RecordsTable&);
    friend bool operator+=(RecordsTable&, Record&);
    friend bool operator==(RecordsTable&, RecordsTable&);
};

#endif