#ifndef TEAMRECORD_H
#define TEAMRECORD_H

#include <fstream>
#include "Record.h"
#include "Season.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

#define TEAM_CLASSNAME "team"
#define SEPARATOR "----------------------------------------"

class TeamRecord : public Record
{
private:
  string _class;
  string _teamName;
  int _participantCount;
  string _location;
  Season _season;

public:
  TeamRecord();
  ~TeamRecord();
  friend void operator<<(ostream &, TeamRecord &);
  friend int operator>>(istream &, TeamRecord &);
  friend int operator>>(ifstream &, TeamRecord &);
  friend void operator<<(ofstream &, TeamRecord &);
  friend bool operator==(TeamRecord &, TeamRecord &);
  bool isCorrect();
  virtual void about() override;
};

#endif