#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>
using std::string;
using std::to_string;

class Date
{
private:
    int _d;
    int _m;
    int _y;

public:
    string GetDate();
    string GetSepDate();
    int SetDate(int, int, int);
    int GetYear();
};

#endif