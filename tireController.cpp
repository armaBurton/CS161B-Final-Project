#include "tools.h"
#include "tireController.h"

bool loadData(TireData list[], int &count)
{
    ifstream infile;
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
        infile.ignore(100, '\n');
        count++;
    }
    infile.close();

    return true;
}