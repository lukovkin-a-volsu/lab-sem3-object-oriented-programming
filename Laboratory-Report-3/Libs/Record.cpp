#include "record.h"

void Record::_SetGender(int n)
{
    _gender = (n == 0 ? "female" : "male");
}

void Record::Print()
{
    cout << "=======================================" << endl;
    cout << " Sport: " << _sport << endl;
    cout << " Discipline: " << _discipline << endl;
    cout << " Type: " << _type << endl;
    cout << " Gender: " << _gender << endl;
    cout << " Date: " << _date.GetDate() << endl;
    cout << " Country: " << _country << endl;
    cout << " Achievement: " << _achievement << endl;
    cout << "=======================================\n"
         << endl;
}

void Record::FromFile(ifstream &infile)
{
    int d, m, y;
    int gender;
    string sep;
    getline(infile, sep);
    getline(infile, _sport);
    getline(infile, _discipline);
    getline(infile, _type);
    infile >> gender;
    infile.ignore();
    infile >> d >> m >> y;
    infile.ignore();
    getline(infile, _country);
    getline(infile, _achievement);

    _SetGender(gender);
    _date.SetDate(d, m, y);
}

void Record::ToFile(ofstream &outfile)
{
    const string sep = "--------------------------------------\n";
    outfile << sep << _sport << "\n" << _discipline << "\n" << _type << "\n" << GetGenderBool() << "\n" << _date.GetSepDate() << "\n" << _country << "\n" << _achievement << "\n";
}

int Record::FromInput()
{
    int d, m, y;
    int gender;
    cin >> _sport >> _discipline >> _type >> gender >> d >> m >> y >> _country >> _achievement;
    _SetGender(gender);
    return _date.SetDate(d, m, y);
}

void Record::Fill()
{
    int d, m, y;
    cout << "Input a record in next format: " << endl;
    cout << "sport discipline type gender(0-fem, 1) day month year country achievement: " << endl;
    cin >> _sport >> _discipline >> _type >> _gender >> d >> m >> y >> _country >> _achievement;
    _date.SetDate(d, m, y);
}

string Record::GetSport()
{
    return _sport;
}

string Record::GetType()
{
    return _type;
}

int Record::GetYear()
{
    return _date.GetYear();
}

bool Record::GetGenderBool()
{
    return _gender == "male" ? true : false;
}
