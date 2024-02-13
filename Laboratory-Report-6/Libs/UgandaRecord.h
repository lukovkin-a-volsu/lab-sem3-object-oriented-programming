#ifndef UGANDARECORD_H
#define UGANDARECORD_H

#include "Record.h"
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

class UgandaRecord : public Record
{
private:
  string _country;
  string _president;
  string _city;
  int _area;
  double _population;

public:
  UgandaRecord();
  friend void operator<<(ostream &ostream, UgandaRecord &record);
  friend int operator>>(istream &istream, UgandaRecord &record);
  friend int operator>>(ifstream &infile, UgandaRecord &record);
  friend void operator<<(ofstream &outfile, UgandaRecord &record);
  friend bool operator==(UgandaRecord &record1, UgandaRecord &record2);
  bool isCorrect();
};

#endif