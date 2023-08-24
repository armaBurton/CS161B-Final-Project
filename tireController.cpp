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
    system("pause");
    cout << endl;
}

void addTire(TireData list[], int &count)
{
    char brand[STRLEN], style[STRLEN], position[STRLEN], prompt[STRLEN];
    int width, ratio, diameter;
    double price;

    cout << "Enter the Brand name: ";
    cin.getline(brand, STRLEN, '\n');
    cout << "Enter the Style: ";
    cin.getline(style, STRLEN, '\n');
    choosePosition(position);
    cout << position << endl;
    strcpy(prompt, "Tire Width: ");
    getInt(prompt, width);
    system("pause");
    cout << endl;
}

void choosePosition(char position[])
{
    char positionBuffer;

    do
    {
        cout << "Choose Position:\n"
             << "\t(F)ront\n"
             << "\t(R)ear\n";
        cin >> positionBuffer;
        cin.ignore(1000, '\n');
        positionText(position, positionBuffer);
    } while (positionBuffer != 'f' && positionBuffer != 'r');
}

void positionText(char position[], char buffer)
{
    switch (buffer)
    {
    case 'f':
        strcpy(position, "Front");
        break;
    case 'r':
        strcpy(position, "Rear");
        break;
    default:
        cout << "You dun fucked up.\n";
        break;
    }
}
