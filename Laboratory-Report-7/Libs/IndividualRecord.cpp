#include "IndividualRecord.h"

IndividualRecord::IndividualRecord() : _class{INDIVIDUAL_CLASSNAME}
{
}

IndividualRecord::~IndividualRecord()
{
}

// print
void operator<<(ostream &ostream, IndividualRecord &ir)
{
  Record *r = static_cast<Record *>(&ir);
  ostream << *r;
  ostream << "First name: " << ir._firstName << endl;
  ostream << "Last name: " << ir._lastName << endl;
  ostream << "Height: " << ir._height << endl;
  ostream << "Weight: " << ir._weight << endl;
}

// input
int operator>>(istream &istream, IndividualRecord &ir)
{
  Record *r = static_cast<Record *>(&ir);
  bool isCorrect = istream >> *r;
  cout << "First Name: ";
  getline(istream, ir._firstName);
  cout << "Last Name: ";
  getline(istream, ir._lastName);
  cout << "Height: ";
  istream >> ir._height;
  istream.ignore();
  cout << "Weight: ";
  istream >> ir._weight;
  istream.ignore();
  return isCorrect;
}

// file reading
int operator>>(ifstream &infile, IndividualRecord &ir)
{
  Record *r = static_cast<Record *>(&ir);
  bool isCorrect = infile >> *r;
  getline(infile, ir._firstName);
  getline(infile, ir._lastName);
  infile >> ir._height;
  infile.ignore();
  infile >> ir._weight;
  infile.ignore();
  return isCorrect;
}

// file writing
void operator<<(ofstream &outfile, IndividualRecord &ir)
{
  Record *r = static_cast<Record *>(&ir);
  outfile << SEPARATOR << "\n"
          << INDIVIDUAL_CLASSNAME << "\n";
  outfile << *r;
  outfile << ir._firstName << "\n";
  outfile << ir._lastName << "\n";
  outfile << ir._height << "\n";
  outfile << ir._weight << "\n";
}

// comparing
bool operator==(IndividualRecord &ir1, IndividualRecord &ir2)
{
  Record *r1 = static_cast<Record *>(&ir1);
  Record *r2 = static_cast<Record *>(&ir2);

  if (!(*r1 == *r2))
    return false;
  if (ir1._firstName != ir2._firstName)
    return false;
  if (ir1._lastName != ir2._lastName)
    return false;
  if (ir1._height != ir2._height)
    return false;
  if (ir1._weight != ir2._weight)
    return false;

  return true;
}

bool IndividualRecord::isCorrect()
{
  return _class == INDIVIDUAL_CLASSNAME;
}

void IndividualRecord::about()
{
    Record::about();
    cout << "This is an instance of \"IndividualRecord\"" << endl;
}