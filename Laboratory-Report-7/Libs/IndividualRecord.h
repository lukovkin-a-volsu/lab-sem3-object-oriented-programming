#ifndef INDIVIDUALRECORD_H
#define INDIVIDUALRECORD_H

#include <fstream>
#include "Record.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

#define INDIVIDUAL_CLASSNAME "individual"
#define SEPARATOR "----------------------------------------"

class IndividualRecord : public Record
{
private:
  string _class;
  string _firstName;
  string _lastName;
  double _height;
  double _weight;
public:
  IndividualRecord();
  ~IndividualRecord();
  friend void operator<<(ostream &, IndividualRecord &);
  friend int operator>>(istream &, IndividualRecord &);
  friend int operator>>(ifstream &, IndividualRecord &);
  friend void operator<<(ofstream &, IndividualRecord &);
  friend bool operator==(IndividualRecord &, IndividualRecord &);
  bool isCorrect();
  virtual void about() override;
};

#endif