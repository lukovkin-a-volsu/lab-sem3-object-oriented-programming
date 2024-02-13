#include <iostream>
#include <vector>
#include "Libs/UgandaRecord.h"

int main()
{
  vector<Record *> table;
  Record *record = new Record();
  UgandaRecord *ugandaRecord = new UgandaRecord();
  cout << "RECORD" << endl
       << endl;
  cin >> (*record);
  cout << endl
       << "UGANDA RECORD" << endl
       << endl;
  cin >> (*ugandaRecord);
  table.push_back(record);
  table.push_back(ugandaRecord);
  cout << endl
       << "OUTPUT IS " << endl;
  for (auto &item : table)
  {
    UgandaRecord *tmp = static_cast<UgandaRecord *>(item);

    if (tmp->isCorrect())
    {
      cout << endl
           << "UGANDA RECORD" << endl
           << endl;
      cout << (*tmp);
    }
    else
    {
      cout << endl
           << "RECORD" << endl
           << endl;
      cout << (*item);
    }
  }

  return 0;
}