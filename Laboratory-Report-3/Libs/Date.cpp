#include "date.h"

string Date::GetDate()
{
    return to_string(_m) + "/" + to_string(_d) + "/" + to_string(_y);
}

string Date::GetSepDate()
{
    return to_string(_m) + " " + to_string(_d) + " " + to_string(_y);
}

#include <iostream>
int Date::SetDate(int d, int m, int y)
{
    struct tm date;
    date.tm_mday = d;
    date.tm_mon = m;
    date.tm_year = y;

    bool isLeap = (date.tm_year % 400 == 0 || (date.tm_year % 4 == 0 && date.tm_year % 100 != 0)); 

    if (!isLeap && date.tm_mday > 28)
    {
        // std::cout << isLeap << std::endl;
        return 0;
    }
    
    if (isLeap && date.tm_mday > 29)
    {
        return 0;
    }

    if ((date.tm_mday < 1 || date.tm_mday > 31))
    {
        return 0;
    }

    if ((date.tm_mon < 1 || date.tm_mon > 12))
    {
        return 0;
    }

    if (date.tm_year < 1900 || date.tm_year > 2023)
    {
        return 0;
    }

    _d = d;
    _m = m;
    _y = y;

    return 1;
}

int Date::GetYear()
{
    return _y;
}