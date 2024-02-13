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
using std::vector;
using std::setw;

class RecordsTable
{
private:
    string _name;
    vector<Record> _records;
    bool _RemoveRecord();
    bool _PrintCountBySport();
    bool _WorkingFemWorldRecords();
    bool _ToFile();
    bool _ReadFromFile();
    bool _ReadFromKeyboard();
    bool _Print();
    bool _MoreMenu();
public:
    RecordsTable(string);
    ~RecordsTable();
    bool Menu();
    void PushUnsafe(Record r);
};

#endif