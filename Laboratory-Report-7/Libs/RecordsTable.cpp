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
    vector<Record *>().swap(_records);
}

bool operator<<(ostream &ostream, RecordsTable &rt)
{
    try
    {
        for (int i = 0; i < rt._records.size(); i++)
        {
            TeamRecord *tr = static_cast<TeamRecord *>(rt._records[i]);
            IndividualRecord *ir = static_cast<IndividualRecord *>(rt._records[i]);
            if (tr->isCorrect())
            {
                ostream << "Team Record #" << i + 1 << endl;
                ostream << *tr;
            }
            else if (ir->isCorrect())
            {
                ostream << "Individual Record #" << i + 1 << endl;
                ostream << *ir;
            }
            else
            {
                ostream << "Record #" << i + 1 << endl;
                ostream << *rt._records[i];
            }
            ostream << endl;
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
        Record *record = new Record();
        int status = istream >> (*record);
        if (status == 0)
        {
            // TODO: maybe throw error
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
            int status;
            string className;
            string separator;
            getline(ifstream, separator);
            getline(ifstream, className);
            if (className == TEAM_CLASSNAME)
            {
                TeamRecord *tr = new TeamRecord();
                status = ifstream >> *tr;
                if (status == 0)
                {
                    error++;
                    cout << "ERROR FOR TEAM RECORD" << endl
                         << endl;
                    continue;
                }
                rt._records.push_back(tr);
            }
            else if (className == INDIVIDUAL_CLASSNAME)
            {
                IndividualRecord *ir = new IndividualRecord();
                status = ifstream >> *ir;
                if (status == 0)
                {
                    error++;
                    cout << "ERROR FOR INDIVIDUAL RECORD" << endl
                         << endl;
                    continue;
                }
                rt._records.push_back(ir);
            }
            else
            {
                Record *record = new Record();
                status = ifstream >> *record;
                if (status == 0)
                {
                    cout << "ERROR FOR RECORD" << endl
                         << endl;
                    error++;
                    continue;
                }
                rt._records.push_back(record);
            }
            success++;
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
        // UgandaRecord *tmp = static_cast<UgandaRecord *>(item);
        // if (tmp->isCorrect())
        // {
        // cout << (*tmp);
        // }
        // else
        // {
        // cout << (*item);
        // }

        int count = rt._records.size();
        for (int i = 0; i < count; i++)
        {
            TeamRecord *tr = static_cast<TeamRecord *>(rt._records[i]);
            IndividualRecord *ir = static_cast<IndividualRecord *>(rt._records[i]);
            if (tr->isCorrect())
            {
                ofstream << *tr;
            }
            else if (ir->isCorrect())
            {
                ofstream << *ir;
            }
            else
            {
                (*rt._records[i]).toFileUnsafe(ofstream);
                // ofstream << *rt._records[i];
            }
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
        rt._records.push_back((&r));
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator+=(RecordsTable &rt, TeamRecord &r)
{
    try
    {
        rt._records.push_back((&r));
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool operator==(RecordsTable &rt1, RecordsTable &rt2)
{
    if (rt1.getName() != rt2.getName())
        return false;
    if (rt1.getSize() != rt2.getSize())
        return false;

    for (int i = 0; i < rt1.getSize(); i++)
    {
        if (&rt1._records[i] != &rt2._records[i])
        {
            return false;
        }
    }

    return true;
}

bool RecordsTable::removeRecord(int idx)
{
    if (idx < 1 || idx > _records.size())
    {
        return false;
    }
    _records.erase(_records.begin() + idx - 1);
    return true;
}

int RecordsTable::getSize()
{
    return _records.size();
}

string RecordsTable::getName()
{
    return _name;
}

RecordsTable *RecordsTable::getBySport(string sport)
{
    int count = 0;
    RecordsTable *rt = new RecordsTable("By Sport Records");

    for (Record *record : _records)
    {
        if (record->getSport() == sport)
        {
            Record *newRecord = new Record(*record);
            TeamRecord *tr = static_cast<TeamRecord *>(record);
            IndividualRecord *ir = static_cast<IndividualRecord *>(record);
            if (tr->isCorrect())
            {
                (*rt) += (*tr);
            }
            else if (ir->isCorrect())
            {
                (*rt) += (*ir);
            }
            else
            {
                (*rt) += (*newRecord);
            }
            count++;
        }
    }

    cout << sep << endl;
    cout << "Result: " << count << endl;
    cout << endl;

    return rt;
}

RecordsTable *RecordsTable::getFemWorldRecords(int year)
{
    RecordsTable *rt = new RecordsTable("Female World Records");
    for (Record *record : _records)
    {
        bool isLastYear = record->getYear() == year;
        bool isFemale = record->getGenderBool() == 0;
        bool isWorldRecord = record->getType() == "world";
        bool condition = isLastYear && isFemale && isWorldRecord;
        if (condition)
        {
            Record *newRecord = new Record(*record);
            TeamRecord *tr = static_cast<TeamRecord *>(record);
            IndividualRecord *ir = static_cast<IndividualRecord *>(record);
            if (tr->isCorrect())
            {
                (*rt) += (*tr);
            }
            else if (ir->isCorrect())
            {
                (*rt) += (*ir);
            }
            else
            {
                (*rt) += (*newRecord);
            }
        }
    }

    bool status = true;
    return rt;
}

void RecordsTable::about()
{
    for (int i = 0; i < _records.size(); i++)
    {
        (*_records[i]).about();
    }
}