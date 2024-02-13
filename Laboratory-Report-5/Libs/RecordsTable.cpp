#include "RecordsTable.h"

// 1) Разработайте класс-контейнер, предназначенный для хранения коллекции объектов
// своей предметной области. Реализуйте следующие методы класса-контейнера:
//  конструктор и деструктор,
//  добавление нового элемента,
//  удаление элемента из коллекции,
//  загрузка из файла и запись в файл,
//  вывод содержимого на экран,
//  поиск данных в коллекции согласно своему индивидуальному заданию.
// 2) Разместите класс-контейнер в отдельном программном модуле. В заголовочном
// файле модуля (*.h) поместите объявление класса, в файле реализации (*.cpp) –
// определения методов класса.
// 3) В основном модуле программы:
//  создайте экземпляр класса-контейнера,
//  заполните контейнер данными из текстового файла,
//  выведите содержимое контейнера на экран,
//  продемонстрируйте выполнение дополнительных функций из своего задания.

// friend void operator<<(ostream &, Record &);  // output
// friend int operator>>(istream &, Record &);  // input
// friend int operator>>(ifstream &, Record &);  // reading from File
// friend void operator<<(ofstream &, Record &); // writing to File

// 1) Для своего варианта задания реализуйте операторные функции:
//  проверки двух объектов основного класса на эквивалентность (operator==),
//  вывода информации в поток ostream (operator<<),
//  ввода данных из потока istream (operator>>),
//  записи в файловый поток ofstream (operator<<),
//  чтения из файлового потока ifstream (operator>>),
//  добавления нового элемента в класс-контейнер (operator+=).
// 2) Продемонстрируйте работу операторных функций.

RecordsTable::RecordsTable()
{
    _name = "Default Table";
}

RecordsTable::RecordsTable(string name)
{
    _name = name;
}

RecordsTable::~RecordsTable()
{
    vector<Record>().swap(_records);
}

bool operator<<(ostream &ostream, RecordsTable &rt)
{
    try
    {
        for (int i = 0; i < rt._records.size(); i++)
        {
            ostream << rt._records[i];
        }
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator>>(istream &istream, RecordsTable &rt)
{
    try
    {
        Record record;
        int status = (istream >> record);
        if (status == 0)
        {
            return false;
        }
        rt._records.push_back(record);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator>>(ifstream &ifstream, RecordsTable &rt)
{
    try
    {
        int count;
        ifstream >> count;
        ifstream.ignore();
        int success = 0;
        int error = 0;
        for (int i = 0; i < count; i++)
        {
            Record record;
            int status = ifstream >> record;
            if (status == 0)
            {
                error++;
                continue;
            }
            success++;
            rt._records.push_back(record);
        }
        // cout << sep << endl;
        // cout << endl << "Reading the file" << endl;
        // cout << "Total: " << count << " Success: " << success << " Error: " << error << endl;
        // cout << endl << sep << endl << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator<<(ofstream &ofstream, RecordsTable &rt)
{
    try
    {
        int count = rt._records.size();
        for (int i = 0; i < count; i++)
        {
            ofstream << rt._records[i];
        }
        ofstream.seekp(0);
        ofstream << count << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator+=(RecordsTable &rt, Record &r)
{
    try
    {
        rt._records.push_back(r);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator==(RecordsTable &rt1, RecordsTable& rt2)
{
    if (rt1.GetName() != rt2.GetName()) return false;
    if (rt1.GetSize() != rt2.GetSize()) return false;

    for (int i = 0; i < rt1.GetSize(); i++)
    {
        if (&rt1._records[i] != &rt2._records[i])
        {
            return false;
        }
    }

    return true;
}

bool RecordsTable::RemoveRecord(int idx)
{
    if (idx < 1 || idx > _records.size())
    {
        return false;
    }
    _records.erase(_records.begin() + idx - 1);
    return true;
}

int RecordsTable::GetSize()
{
    return _records.size();
}

string RecordsTable::GetName()
{
    return _name;
}

RecordsTable *RecordsTable::GetBySport(string sport)
{
    int count = 0;
    RecordsTable *rt = new RecordsTable("By Sport Records");

    for (Record record : _records)
    {
        if (record.GetSport() == sport)
        {
            Record newRecord = Record(record);
            (*rt) += newRecord;
            count++;
        }
    }

    cout << sep << endl;
    cout << "Result: " << count << endl;
    cout << endl;

    return rt;
}

RecordsTable *RecordsTable::GetFemWorldRecords(int year)
{
    RecordsTable *rs = new RecordsTable("Female World Records");
    for (Record record : _records)
    {
        bool isLastYear = record.GetYear() == year;
        bool isFemale = record.GetGenderBool() == 0;
        bool isWorldRecord = record.GetType() == "world";
        bool condition = isLastYear && isFemale && isWorldRecord;
        if (condition)
        {
            Record newRecord = Record(record);
            (*rs) += newRecord;
        }
    }

    bool status = true;
    return rs;
}