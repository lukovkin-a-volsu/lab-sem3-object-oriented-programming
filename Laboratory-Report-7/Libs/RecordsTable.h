#ifndef RECORDSTABLE_H
#define RECORDSTABLE_H

#include "Record.h"
#include "TeamRecord.h"
#include "IndividualRecord.h"
#include <vector>
#include <iomanip>
#include <filesystem>
#define lowSep "........................................"
#define sep "----------------------------------------"
#define pSep "++++++++++++++++++++++++++++++++++++++++"
#define hashSep "########################################"
#define outSep "-----------------OUTPUT-----------------"
using std::getline;
using std::setw;
using std::vector;

class RecordsTable
{
private:
    string _name;
    vector<Record *> _records;
public:
    ~RecordsTable();
    RecordsTable();
    RecordsTable(string);
    bool removeRecord(int);
    int getSize();
    string getName();
    RecordsTable *getBySport(string);
    RecordsTable *getFemWorldRecords(int);
    friend bool operator<<(ostream &, RecordsTable &);
    friend bool operator>>(istream &, RecordsTable &);
    friend bool operator>>(ifstream &, RecordsTable &);
    friend bool operator<<(ofstream &, RecordsTable &);
    friend bool operator+=(RecordsTable &, Record &);
    friend bool operator+=(RecordsTable &, TeamRecord &);
    friend bool operator==(RecordsTable &, RecordsTable &);
    void about();
};

#endif