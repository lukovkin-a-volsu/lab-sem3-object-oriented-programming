#include "TeamRecord.h"
#include "Record.h"

TeamRecord::TeamRecord(): _class{TEAM_CLASSNAME}
{
}

TeamRecord::~TeamRecord()
{
}

// print
void operator<<(ostream &ostream, TeamRecord &tr)
{
  Record *r = static_cast<Record *>(&tr);
  ostream << *r;
  ostream << "Team name: " << tr._teamName << endl;
  ostream << "Participant count: " << tr._participantCount << endl;
  ostream << "Location: " << tr._location << endl;
  ostream << "Season: " << seasonToString(tr._season) << endl;
}

// input
int operator>>(istream &istream, TeamRecord &tr)
{
  Record *r = static_cast<Record *>(&tr);
  bool isCorrect = istream >> *r;
  cout << "Team name: ";
  getline(istream, tr._teamName);
  cout << "Participant count: ";
  istream >> tr._participantCount;
  istream.ignore();
  cout << "Location: ";
  getline(istream, tr._location);
  cout << "Season: ";
  string seasonStr;
  getline(istream, seasonStr);
  Season season = static_cast<Season>(seasonToInt(seasonStr));
  tr._season = season;
  return isCorrect;
}

// file reading
int operator>>(ifstream &infile, TeamRecord &tr)
{
  Record *r = static_cast<Record *>(&tr);
  bool isCorrect = infile >> *r;
  getline(infile, tr._teamName);
  infile >> tr._participantCount;
  infile.ignore();
  getline(infile, tr._location);
  string seasonStr;
  getline(infile, seasonStr);
  Season season = static_cast<Season>(seasonToInt(seasonStr));
  tr._season = season;
  return isCorrect;
}

// file writing
void operator<<(ofstream &outfile, TeamRecord &tr)
{
  Record *r = static_cast<Record *>(&tr);
  outfile << SEPARATOR << "\n"
          << TEAM_CLASSNAME << "\n";
  outfile << *r;
  outfile << tr._teamName << "\n";
  outfile << tr._participantCount << "\n";
  outfile << tr._location << "\n";
  outfile << seasonToString(tr._season) << "\n";
}

// comparing
bool operator==(TeamRecord &tr1, TeamRecord &tr2)
{
  Record *r1 = static_cast<Record *>(&tr1);
  Record *r2 = static_cast<Record *>(&tr2);

  if (!(*r1 == *r2))
    return false;
  if (tr1._teamName != tr2._teamName)
    return false;
  if (tr1._participantCount != tr2._participantCount)
    return false;
  if (tr1._location != tr2._location)
    return false;
  if (tr1._season != tr2._season)
    return false;

  return true;
}

bool TeamRecord::isCorrect()
{
  return _class == TEAM_CLASSNAME;
}

void TeamRecord::about() 
{
    cout << "This is an instance of \"TeamRecord\"" << endl;
}