#include <iostream>
#include <vector>
#include "Libs/RecordsTable.h"

using namespace std;

string GetPath();
bool PrintSize(RecordsTable &);
bool ActivateSportTable(RecordsTable &);
bool ActivateFemWorldTable(RecordsTable &);
bool AddFromFile(RecordsTable &);
bool RemoveRecord(RecordsTable &);
bool AddFromKeyboard(RecordsTable &);
bool WriteToFile(RecordsTable &);
bool PrintTable(RecordsTable &);
bool RemoveRecord(RecordsTable &);
bool Menu(RecordsTable &);

int main(void)
{
    RecordsTable rt;
    RecordsTable rt2;

    bool status = true;
    while (status)
    {
        status = Menu(rt);
    }

    return 0;
}

bool Menu(RecordsTable &rt)
{
    cout << hashSep << endl;
    cout << "Menu (Table - \"" << rt.GetName() << "\")" << endl;
    cout << "Actions:" << endl;
    cout << "1. Add from file" << endl;
    cout << "2. Add from keyboard" << endl;
    cout << "3. Write to file" << endl;
    cout << "4. Print table" << endl;
    cout << "5. Remove record by number" << endl;
    cout << "6. Get sport table" << endl;
    cout << "7. Get female world table" << endl;
    cout << "8. Print Size" << endl;
    cout << "0. Exit" << endl;
    cout << hashSep << endl;
    cout << ": ";

    int action;
    cin >> action;
    cin.get();
    cout << endl;

    if (!cin)
    {
        cout << "Your input is not a number. Exit." << endl;
        cout << endl;
        return false;
    }

    switch (action)
    {
    case 1:
        return AddFromFile(rt);
    case 2:
        return AddFromKeyboard(rt);
    case 3:
        return WriteToFile(rt);
    case 4:
        return PrintTable(rt);
    case 5:
        return RemoveRecord(rt);
    case 6:
        return ActivateSportTable(rt);
    case 7:
        return ActivateFemWorldTable(rt);
    case 8:
        return PrintSize(rt);
    default:
        cout << "Exit from " << rt.GetName() << endl
             << endl;
        return false;
    }

    return true;
}

string GetPath()
{
    string path;
    cout << sep << endl;
    cout << "Input path (or \"Exit\")" << endl;
    cout << ":: ";
    cin >> path;
    cin.get();
    if (path == "Exit")
    {
        cout << sep << endl;
        cout << endl;
        return "";
    }
    return path;
}

bool AddFromFile(RecordsTable &rt)
{
    string path = GetPath();
    if (path == "")
        return true;

    if (!std::filesystem::exists(path))
    {
        cout << sep << endl;
        cout << "The file doesn't exist" << endl;
        cout << endl;
        return true;
    }

    ifstream file(path);
    file >> rt;
    cout << sep << endl
         << endl;
    return true;
}

bool AddFromKeyboard(RecordsTable &rt)
{
    int count;
    cout << sep << endl;
    cout << "Please enter the number of records you will enter (or \"-1\")" << endl;
    cout << sep << endl;
    cout << ":: ";
    cin >> count;
    cin.get();
    if (count < 0)
    {
        cout << endl;
        return true;
    }
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        cout << "Record #" + to_string(i + 1) << endl;
        bool status = cin >> rt;
        if (!status)
        {
            cout << endl
                 << lowSep << endl;
            cout << "Something went wrong." << endl
                 << "Make sure that all the data is correct." << endl
                 << "Try again." << endl;
            cout << lowSep << endl;
            i--;
            continue;
        }
    }

    cout << endl
         << sep << endl;
    cout << endl;
    return true;
}

bool WriteToFile(RecordsTable &rt)
{
    string path = GetPath();
    if (path == "")
        return true;

    ofstream file(path);
    file << rt;
    cout << endl;
    return true;
}

bool PrintTable(RecordsTable &rt)
{
    cout << outSep << endl
         << endl;
    cout << rt;
    cout << sep << endl;
    cout << endl;
    return true;
}

bool RemoveRecord(RecordsTable &rt)
{
    int idx;
    cout << sep << endl;
    cout << "Input number to remove (or \"-1\")" << endl;
    cout << sep << endl;
    cout << ":: ";
    cin >> idx;
    bool status = rt.RemoveRecord(idx);
    if (!status) 
    {
        cout << endl << sep << endl << "The element that you've tried to delete doesn't exist." << endl << sep << endl;
    }
    cout << endl
         << endl;
    return true;
}

bool PrintSize(RecordsTable &rt)
{
    cout << outSep << endl;
    cout << "Size: " << rt.GetSize() << endl;
    cout << sep << endl;
    cout << endl;
    return true;
}

bool ActivateSportTable(RecordsTable &rt)
{
    string sport;
    cout << sep << endl;
    cout << "Get table by sport. Input sport: " << endl;
    cout << ":: ";
    getline(cin, sport);
    RecordsTable *rtSport = rt.GetBySport(sport);
    bool status = true;
    while (status)
    {
        status = Menu((*rtSport));
    }
    return true;
}

bool ActivateFemWorldTable(RecordsTable &rt)
{
    RecordsTable *rs = rt.GetFemWorldRecords(2023);
    bool status = true;
    while (status)
    {
        status = Menu((*rs));
    }
    return true;
}