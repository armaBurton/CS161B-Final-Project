#include "tools.h"

int main()
{
    TireData list[LIST];
    int count = 0;
    char option[MAXLEN];
    if (!loadData(list, count))
    {
        return 0;
    }
    cout << list[0].brand << endl;

    greeting();

    do
    {
        menu();
        readOption(option);
    } while (option[0] != 'q');
    return 0;
}