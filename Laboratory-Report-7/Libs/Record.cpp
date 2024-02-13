#include "Record.h"

Record::Record() {}

void Record::_setGender(int n)
{
    _gender = (n == 0 ? "female" : "male");
}

void operator<<(ostream &ostream, Record &record)
{
    ostream << "Sport: " << record._sport << endl;
    ostream << "Discipline: " << record._discipline << endl;
    ostream << "Type: " << record._type << endl;
    ostream << "Gender: " << record._gender << endl;
    ostream << "Date: " << record._date.getDate() << endl;
    ostream << "Country: " << record._country << endl;
    ostream << "Achievement: " << record._achievement << endl;
}

int operator>>(ifstream &infile, Record &record)
{
    int d, m, y;
    int gender;
    getline(infile, record._sport);
    getline(infile, record._discipline);
    getline(infile, record._type);
    infile >> gender;
    infile.ignore();
    infile >> d >> m >> y;
    infile.ignore();
    getline(infile, record._country);
    getline(infile, record._achievement);
    record._setGender(gender);
    return record._date.setDate(d, m, y);
}

void operator<<(ofstream &outfile, Record &record)
{
    outfile << record._sport << "\n"
            << record._discipline << "\n"
            << record._type << "\n"
            << record.getGenderBool() << "\n"
            << record._date.getSepDate() << "\n"
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
    if (record1._date.getDate() != record2._date.getDate())
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
    record._setGender(gender);
    return record._date.setDate(d, m, y);
}

void Record::toFileUnsafe(ofstream &outfile)
{
    outfile
        << SEPARATOR << "\n"
        << "default" << "\n"
        << _sport << "\n"
        << _discipline << "\n"
        << _type << "\n"
        << getGenderBool() << "\n"
        << _date.getSepDate() << "\n"
        << _country << "\n"
        << _achievement << "\n";
}

string Record::getSport()
{
    return _sport;
}

string Record::getType()
{
    return _type;
}

string Record::getDate()
{
    return _date.getDate();
}

int Record::getYear()
{
    return _date.getYear();
}

string Record::getGender()
{
    return _gender;
}

bool Record::getGenderBool()
{
    return _gender == "male" ? true : false;
}

void Record::about()
{
    cout << "This is an instance of \"Record\"" << endl;
}