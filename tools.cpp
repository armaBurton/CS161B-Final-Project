#include "tools.h"

void greeting()
{
    cout << "Tire Tracker 2000" << endl;
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
    // strcpy(option, inputBuffer);
    option[0] = inputBuffer;
}