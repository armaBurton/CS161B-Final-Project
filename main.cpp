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

    greeting();

    do
    {
        menu();
        readOption(option);
        runOption(list, count, option);
    } while (option[0] != 'q');
    return 0;
}