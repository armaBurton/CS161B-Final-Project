#include "tools.h"
#include "tireController.h"

bool loadData(TireData list[], int &count)
{
    ifstream infile;
    infile.open("tires.txt");
    if (!infile)
    {
        cout << "File did not open. Program exiting.\n";
        return false;
    }

    while (infile.getline(list[count].dimensions, MAXLEN, ';'))
    {
        infile.getline(list[count].brand, MAXLEN, ';');
        infile.getline(list[count].style, MAXLEN, ';');
        infile >> list[count].price;
        infile.ignore(5, '\n');
        count++;
    }
    infile.close();

    return true;
}

void writeToConsole(TireData list[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "0" << i + 1 << ": "
             << list[i].dimensions << ";"
             << list[i].brand << ";"
             << list[i].style << ";"
             << list[i].price << endl;
    }

    cout << endl;
}