#include "tools.h"

void greeting()
{
    cout << "\nTire Tracker 2000" << endl;
    cout << "This program creates a database of information about"
         << "motorcycle tires including the dimensions, brand, style, "
         << "and cost.\n\n";
}

void menu()
{
    cout << "TT2K menu:\n\n"
         << "(A)dd\n"
         << "(R)emove\n"
         << "(P)rint\n"
         << "(F)ind\n"
         << "(-)Min\n"
         << "(+)Max\n"
         << "(Q)uit\n\n";
}

void readOption(char *option)
{
    char inputBuffer;
    cin >> inputBuffer;
    cin.ignore(100, '\n');
    option[0] = tolower(inputBuffer);
}

void runOption(TireData list[], int &count, char *option)
{
    switch (*option)
    {
    case 'a':
        addTire(list, count);
        break;
    case 'r':
        cout << "option R" << endl;
        break;
    case 'p':
        writeToConsole(list, count);
        break;
    case 'f':
        cout << "option F" << endl;
        break;
    case '-':
        cout << "option -" << endl;
        break;
    case '+':
        cout << "option +" << endl;
        break;
    case 'q':
        cout << "option Q" << endl;
        break;
    default:
        cout << "You dun fucked up." << endl;
        break;
    }
}

void getInt(char prompt[], int &number)
{
    int numberBuffer;
    cout << prompt;
    cin >> numberBuffer;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You chose poorly\n"
             << prompt;
        cin >> numberBuffer;
    }
    number = numberBuffer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getDouble(char prompt[], double &number)
{
    double numberBuffer;

    cout << prompt;
    cin >> numberBuffer;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You chose poorly\n"
             << prompt;
        cin >> numberBuffer;
    }
    number = numberBuffer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}