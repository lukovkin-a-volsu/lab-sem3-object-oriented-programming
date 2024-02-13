#include <iostream>
#include <vector>
#include "libs/RecordsTable.h"

using namespace std;

int main(void)
{
    RecordsTable rt("Default Records");
    bool status = true;
    while (status)
    {
        status = rt.Menu();
    }
    return 0;
}
