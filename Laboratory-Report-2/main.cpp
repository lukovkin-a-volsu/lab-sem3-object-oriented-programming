// variant #11
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Date
{
    int d;
    int m;
    int y;
};

struct Record
{
    string sport;
    string discipline;
    string type;
    bool gender; // 0 - female
    Date date;   // 00.00.0000
    string country;
    string achievement;
};

struct RecordsSize
{
    Record *records;
    int size;
};

RecordsSize getRecords();
void printRecords(RecordsSize);
int countRecords(RecordsSize, string);
RecordsSize femYWorldRecords(RecordsSize, int);

int main()
{
    RecordsSize rs;
    rs = getRecords(); // #2
    printRecords(rs);  // #3

    // int a = new int[size1][size2]
    // int *p{new int[3] {1, 2, 3}};
    // int *p = new int[3] {1, 2, 3};

    string sport;
    cout << "Count by sports. Enter the sport's name: ";
    cin >> sport;
    int spCount = countRecords(rs, sport); // #4
    cout << "Quantity: " << spCount << endl;

    RecordsSize femRecords = femYWorldRecords(rs, 2023); // #4
    cout << "2023 female world records: " << endl;
    printRecords(femRecords);

    delete[] femRecords.records;
    delete[] rs.records;
    return 0;
}

RecordsSize getRecords()
{
    ifstream infile;
    infile.open("records.txt");
    int count;
    infile >> count;
    Record *records = new Record[count];
    for (int i = 0; i < count; i++)
    {
        infile >> records[i].sport >> records[i].discipline >> records[i].type >> records[i].gender >> records[i].date.d >> records[i].date.m >> records[i].date.y >> records[i].country >> records[i].achievement;
    }
    infile.close();
    RecordsSize rs = {records, count};
    return rs;
}

void printRecords(RecordsSize rs)
{
    for (int i = 0; i < rs.size; i++)
    {
        cout << rs.records[i].sport
             << " "
             << rs.records[i].discipline
             << " "
             << rs.records[i].type
             << " "
             << (rs.records[i].gender == 0 ? "Female" : "Male")
             << " "
             << rs.records[i].date.d
             << "."
             << rs.records[i].date.m
             << "."
             << rs.records[i].date.y
             << " "
             << rs.records[i].country
             << " "
             << rs.records[i].achievement
             << endl;
    }
}

int countRecords(RecordsSize rs, string sport)
{
    int total = 0;
    for (int i = 0; i < rs.size; i++)
    {
        if (rs.records[i].sport == sport)
            total++;
    }
    return total;
}

RecordsSize femYWorldRecords(RecordsSize rs, int year)
{
    vector<Record> recordV;
    string type = "world";
    for (int i = 0; i < rs.size; i++)
    {
        if (rs.records[i].type == type && rs.records[i].date.y == year && !rs.records[i].gender)
        {
            recordV.push_back(rs.records[i]);
        }
    }
    Record *records = new Record[recordV.size()];
    copy(recordV.begin(), recordV.end(), records);
    RecordsSize newRs = {records, (int)recordV.size()};
    return newRs;
}