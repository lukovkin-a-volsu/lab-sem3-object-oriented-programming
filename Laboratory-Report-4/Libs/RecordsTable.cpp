#include "RecordsTable.h"

bool RecordsTable::_PrintCountBySport()
{
    string sport;
    int count = 0;
    cout << sep << endl;
    cout << "Quantity by sport. Input sport: " << endl;
    cout << ":: ";
    getline(cin, sport);

    for (Record record : _records)
    {
        if (record.GetSport() == sport)
        {
            count++;
        }
    }

    cout << sep << endl;
    cout << "Result: " << count << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_WorkingFemWorldRecords()
{
    cout << sep << endl;
    // DONE TODO: More info about file reading
    // DONE TODO: check if user input not a number and throw error
    // TODO: create a function that could be return a RecordsTable that i be able to save and work with it as an particular entity
    RecordsTable *rs = new RecordsTable("Female World Records");
    for (int i = 0; i < _records.size(); i++)
    {
        bool isLastYear = _records[i].GetYear() == 2023;
        bool isFemale = _records[i].GetGenderBool() == 0;
        bool isWorldRecord = _records[i].GetType() == "world";
        bool condition = isLastYear && isFemale && isWorldRecord;
        if (condition)
        {
            rs->PushUnsafe(Record(_records[i]));
        }
    }

    bool status = true;
    while (status)
    {
        status = rs->Menu();
    }
    delete rs;

    cout << sep << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_RemoveRecord()
{
    int idx;
    cout << sep << endl;
    cout << "Input number to remove (or \"-1\")" << endl;
    cout << sep << endl;
    cout << ":: ";
    cin >> idx;
    if (idx < 1)
    {
        cout << endl;
        return true;
    }
    if (idx > _records.size())
    {
        cout << "Element doesn't exist" << endl;
        cout << endl;
        return true;
    }
    _records.erase(_records.begin() + idx - 1);
    cout << endl;
    return true;
}

bool RecordsTable::_ToFile()
{
    string path;
    cout << sep << endl;
    cout << "Input path (or \"Exit\")" << endl;
    cout << sep << endl;
    cout << ":: ";
    if (path == "Exit")
        return true;
    cin >> path;
    cin.get();
    ofstream file(path);
    int count = _records.size();
    for (int i = 0; i < count; i++)
    {
        _records[i].ToFile(file);
    }
    file.seekp(0);
    file << count << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_ReadFromFile()
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
        return true;
    }
    if (!std::filesystem::exists(path))
    {
        cout << sep << endl;
        cout << "The file doesn't exist" << endl;
        cout << endl;
        return true;
    }
    ifstream file(path);
    int count;
    file >> count;
    file.ignore();
    int success = 0;
    int error = 0;
    for (int i = 0; i < count; i++)
    {
        Record record;
        int status = record.FromFile(file);
        if (status == 0)
        {
            error++;
            continue;
        }
        success++;
        _records.push_back(record);
    }
    cout << sep << endl;
    cout << "Total: " << count << " Success: " << success << " Error: " << error << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_ReadFromKeyboard()
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
        Record record;
        int status = record.FromInput();
        if (status == 0)
        {
            cout << endl
                 << lowSep << endl;
            cout << "Something went wrong. Make sure that all the data is correct." << endl
                 << "Try again" << endl;
            cout << lowSep << endl;
            i--;
            continue;
        }
        _records.push_back(record);
    }
    cout << endl
         << sep << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_Print()
{
    cout << outSep << endl;
    for (int i = 0; i < _records.size(); i++)
    {

        cout << endl;
        cout << "Record #" << i + 1 << endl;
        _records[i].Print();
    }
    cout << endl
         << sep << endl;
    cout << endl;
    return true;
}

bool RecordsTable::_MoreMenu()
{
    cout << hashSep << endl;
    cout << "More actions:" << endl;
    cout << "1. Count by sport" << endl;
    cout << "2. Remove record by number" << endl;
    cout << "3. Work with the female world records" << endl;
    cout << "0. To the main menu" << endl;
    cout << hashSep << endl;
    cout << ": ";

    int action;
    cin >> action;
    cin.get();
    cout << endl;

    if (!cin)
    {
        cout << "Your input is not a number. Exit" << endl;
        cout << endl;
        return false;
    }

    switch (action)
    {
    case 1:
        return _PrintCountBySport();
        break;
    case 2:
        return _RemoveRecord();
        break;
    case 3:
        return _WorkingFemWorldRecords();
        break;
    case 0:
        return true;
        break;
    default:
        cout << "Exit" << endl;
        return false;
        break;
    }
}

RecordsTable::RecordsTable(string name)
{
    _name = name;
    cout << "RecordsTable \"" << _name << "\" created." << endl
         << endl;
}

RecordsTable::~RecordsTable()
{
    cout << "RecordsTable \"" << _name << "\" deleted." << endl;
    vector<Record>().swap(_records);
}

bool RecordsTable::Menu()
{
    cout << hashSep << endl;
    cout << "Menu (Table - \"" << _name << "\")" << endl;
    cout << "Actions:" << endl;
    cout << "1. Add from file" << endl;
    cout << "2. Add from keyboard" << endl;
    cout << "3. Write to file" << endl;
    cout << "4. Print table" << endl;
    cout << "5. More actions" << endl;
    cout << "0. Exit" << endl;
    cout << hashSep << endl;
    cout << ": ";

    int action;
    cin >> action;
    cin.get();
    cout << endl;

    if (!cin)
    {
        cout << "Your input is not a number. Exit" << endl;
        cout << endl;
        return false;
    }

    switch (action)
    {
    case 1:
        return _ReadFromFile();
        break;
    case 2:
        return _ReadFromKeyboard();
        break;
    case 3:
        return _ToFile();
        break;
    case 4:
        return _Print();
        break;
    case 5:
        return _MoreMenu();
        break;
    default:
        return false;
        break;
    }
}

void RecordsTable::PushUnsafe(Record r)
{
    _records.push_back(r);
}