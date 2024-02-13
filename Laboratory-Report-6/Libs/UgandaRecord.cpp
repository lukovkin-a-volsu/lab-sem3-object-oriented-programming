#include "UgandaRecord.h"
#include "Record.h"

UgandaRecord::UgandaRecord() : _country{"Uganda"}, _president{"Yoweri Museveni"}, _area{241'038}, _population{45.85e6}
{
}

void operator<<(ostream &ostream, UgandaRecord &record)
{
  ostream << "Sport: " << record._sport << endl;
  ostream << "Discipline: " << record._discipline << endl;
  ostream << "Type: " << record._type << endl;
  ostream << "Gender: " << record._gender << endl;
  ostream << "Date: " << record._date.GetDate() << endl;
  ostream << "Country: " << record._country << endl;
  ostream << "City: " << record._city << endl;
  ostream << "Achievement: " << record._achievement << endl;
  ostream << "President: " << record._president << endl;
  ostream << "Area: " << record._area << endl;
  ostream << "Population: " << record._population << endl;
  ostream << "Achievement: " << record._achievement << endl;
}

int operator>>(istream &istream, UgandaRecord &record)
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
  cout << "City: ";
  getline(istream, record._city);
  cout << "Achievement: ";
  getline(istream, record._achievement);
  record._SetGender(gender);
  return record._date.SetDate(d, m, y);
}

int operator>>(ifstream &infile, UgandaRecord &record)
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
  getline(infile, record._city);
  getline(infile, record._achievement);

  record._SetGender(gender);
  return record._date.SetDate(d, m, y);
}

void operator<<(ofstream &outfile, UgandaRecord &record)
{
  const string sep = "----------------------------------------\n";
  outfile << sep << "Uganda" << endl << sep << record._sport << "\n"
          << record._discipline << "\n"
          << record._type << "\n"
          << record.GetGenderBool() << "\n"
          << record._date.GetSepDate() << "\n"
          << record._city << "\n"
          << record._achievement << "\n";
}

bool operator==(UgandaRecord &record1, UgandaRecord &record2)
{
  if (record1._sport != record2._sport)
    return false;
  if (record1._discipline != record2._discipline)
    return false;
  if (record1._date.GetDate() != record2._date.GetDate())
    return false;
  if (record1._country != record2._country)
    return false;
  if (record1._president != record2._president)
    return false;
  if (record1._area != record2._area)
    return false;
  if (record1._population != record2._population)
    return false;
  if (record1._achievement != record2._achievement)
    return false;
  return true;
}

bool UgandaRecord::isCorrect()
{
  if (_country != "Uganda")
    return false;
  if (_president != "Yoweri Museveni")
    return false;
  if (_area != 241'038)
    return false;
  if (_population != 45.85e6)
    return false;
  if (_president == "")
    return false;
  return true;
}