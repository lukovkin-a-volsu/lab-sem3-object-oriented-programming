#include <iostream>
#include <vector>
#include "libs/RecordsTable.h"

using namespace std;

int countRecords(RecordsTable, string);
RecordsTable femWorldRecords(RecordsTable, int);
void RtSaveFile(RecordsTable, int);

int main(void)
{
    int size;
    int fileSize;
    string path;
    cout << "Input filename to read: ";
    cin >> path;
    ifstream infile(path);

    cout << "Input table size: ";
    cin >> size;
    infile >> fileSize;
    infile.get();
    RecordsTable rt;
    rt.records = new Record[size];
    rt.size = size;

    // reading from file
    for (int i = 0; i < fileSize; i++)
    {
        rt.records[i].FromFile(infile);
        rt.records[i].Print();
    }

    // if rt has empty cells, handwriting
    while (fileSize < size)
    {
        cout << "Input " << fileSize + 1 << "/" << size << ".\nSport Discipline Type Gender(ex:0/1) Date(ex:1 1 2000) Country Achievement: " << endl;
        int err = rt.records[fileSize].FromInput();
        if (err == 0)
        {
            cout << "Error" << endl;
        }
        else
        {
            fileSize++;
        }
    }
    infile.close();

    // save records
    RtSaveFile(rt, rt.size);

    // count by sports
    string sport;
    cout << "Count by sports. Enter the sport's name: " << endl;
    cin.get();
    getline(cin, sport);
    int spCount = countRecords(rt, sport); // #4
    cout << "Quantity: " 
         << (spCount == 0 ? "No record found." : to_string(spCount)) 
         << endl
         << endl;

    // fem records
    RecordsTable femRt;
    femRt = femWorldRecords(rt, 2023);
    cout << "2023 female world records: " << endl;
    if (femRt.size == 0)
        cout << "No record found." << endl;
    for (int i = 0; i < femRt.size; i++)
    {
        femRt.records[i].Print();
    }

    // save fem records
    RtSaveFile(femRt, femRt.size);

    delete[] femRt.records;
    delete[] rt.records;
    return 0;
}

int countRecords(RecordsTable rt, string sport)
{
    int total = 0;
    for (int i = 0; i < rt.size; i++)
    {
        if (rt.records[i].GetSport() == sport)
            total++;
    }
    return total;
}

RecordsTable femWorldRecords(RecordsTable rt, int year)
{
    vector<Record> recordV;
    string type = "world";
    for (int i = 0; i < rt.size; i++)
    {
        if (rt.records[i].GetType() == type && rt.records[i].GetYear() == year && !rt.records[i].GetGenderBool())
        {
            recordV.push_back(rt.records[i]);
        }
    }
    Record *records = new Record[recordV.size()];
    copy(recordV.begin(), recordV.end(), records);
    RecordsTable newRs = {records, (int)recordV.size()};
    return newRs;
}

void RtSaveFile(RecordsTable rt, int size)
{
    string path;
    cout << "\nInput filename to save (or \"skip\"): ";
    cin >> path;
    if (path == "skip") return;
    ofstream outfile(path, std::ios::out);
    for (int i = 0; i < size; i++)
    {
        rt.records[i].ToFile(outfile);
    }
    outfile.seekp(0);
    outfile << size << "\n";
    outfile.close();
}