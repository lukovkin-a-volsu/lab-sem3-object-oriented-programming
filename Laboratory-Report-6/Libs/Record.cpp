#include "Record.h"

Record::Record() {}

void Record::_SetGender(int n)
{
    _gender = (n == 0 ? "female" : "male");
}

void operator<<(ostream &ostream, Record &record)
{
    ostream << "Sport: " << record._sport << endl;
    ostream << "Discipline: " << record._discipline << endl;
    ostream << "Type: " << record._type << endl;
    ostream << "Gender: " << record._gender << endl;
    ostream << "Date: " << record._date.GetDate() << endl;
    ostream << "Country: " << record._country << endl;
    ostream << "Achievement: " << record._achievement << endl;
}

int operator>>(ifstream &infile, Record &record)
{
    int d, m, y;
    int gender;
    string separator;
    getline(infile, separator);
    getline(infile, record._sport);
    getline(infile, record._discipline);
    getline(infile, record._type);
    infile >> gender;
    infile.ignore();
    infile >> d >> m >> y;
    infile.ignore();
    getline(infile, record._country);
    getline(infile, record._achievement);

    record._SetGender(gender);
    return record._date.SetDate(d, m, y);
}

void operator<<(ofstream &outfile, Record &record)
{
    const string sep = "----------------------------------------\n";
    outfile << sep << "Default" << endl << sep << record._sport << "\n"
            << record._discipline << "\n"
            << record._type << "\n"
            << record.GetGenderBool() << "\n"
            << record._date.GetSepDate() << "\n"
            << record._country << "\n"
            << record._achievement << "\n";
}

bool operator==(Record &record1, Record &record2)
{
    if (record1._sport != record2._sport)
        return false;
    if (record1._discipline != record2._discipline)
        return false;
    if (record1._type != record2._type)
        return false;
    if (record1._gender != record2._gender)
        return false;
    if (record1._date.GetDate() != record2._date.GetDate())
        return false;
    if (record1._country != record2._country)
        return false;
    if (record1._achievement != record2._achievement)
        return false;
    return true;
}

int operator>>(istream &istream, Record &record)
{
    int d, m, y;
    int gender;
    cout << "Sport: ";
    getline(istream, record._sport);
    cout << "Discipline: ";
    getline(istream, record._discipline);
    cout << "Type: ";
    getline(istream, record._type);
    cout << "Gender (0 - female, 1 - male): ";
    istream >> gender;
    istream.get();
    cout << "Date (d/m/y, example: 20 9 2023): ";
    istream >> d >> m >> y;
    istream.get();
    cout << "Country: ";
    getline(istream, record._country);
    cout << "Achievement: ";
    getline(istream, record._achievement);
    record._SetGender(gender);
    return record._date.SetDate(d, m, y);
}

string Record::GetSport()
{
    return _sport;
}

string Record::GetType()
{
    return _type;
}

string Record::GetDate()
{
    return _date.GetDate();
}

int Record::GetYear()
{
    return _date.GetYear();
}

string Record::GetGender()
{
    return _gender;
}

bool Record::GetGenderBool()
{
    return _gender == "male" ? true : false;
}