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
        cout << "option A" << endl;
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