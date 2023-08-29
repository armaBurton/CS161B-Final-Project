#include "tools.h"

/*
  Name:   loadData()
  Desc:   reads data from "tires.txt" and stores them in
          an TireData array
  input:  "tires.txt"
  output: text
  return: bool
*/
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

/*
  Name:   writeToConsole()
  Desc:   writes all the data from the TireData array and
          display it to the console using ";" as a separator
  input:  none
  output: TireData
  return: none
*/
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
    cout << endl;
}

/*
  Name:   greeting()
  Desc:   greets the user
  input:  none
  output: text
  return: none
*/
void greeting()
{
    cout << "\nTire Tracker 2000" << endl;
    cout << "This program creates a database of information about"
         << "motorcycle tires including the dimensions, brand, style, "
         << "and cost.\n\n";
}

/*
  Name:   menu()
  Desc:   display the menu
  input:  none
  output: text
  return: none
*/
void menu()
{
    cout << "TT2K menu:\n\n"
         << "(A)dd\n"
         << "(R)emove\n"
         << "(P)rint\n"
         << "(F)ind Brand\n"
         << "(-)Min Price\n"
         << "(+)Max Price\n"
         << "(Q)uit\n\n";
}

/*
  Name:   readOption()
  Desc:   reads the menu option from the user
  input:  char { inputBuffer }
  output: text
  return: none
*/
void readOption(char *option)
{
    char inputBuffer;
    cin >> inputBuffer;
    cin.ignore(100, '\n');
    option[0] = tolower(inputBuffer);
}

/*
  Name:   runOption()
  Desc:   controller, calls functions based on user menu inputs.
  input:  none
  output: text
  return: none
*/
void runOption(TireData list[], int &count, char *option)
{
    int index = 0;
    char prompt[STRLEN];
    switch (*option)
    {
    case 'a': // add
        addTire(list, count);
        break;
    case 'r': // remove
        writeToConsole(list, count);
        strcpy(prompt, "Enter an index to remove: ");
        getInt(prompt, index);
        if (index > 0 && index <= count)
        {
            index--;
            removeData(list, count, index);
            writeToFile(list, count);
        }
        else
        {
            cout << "Invalid Index\n\n";
        }
        break;
    case 'p': // print
        writeToConsole(list, count);
        break;
    case 'f': // find
        findBrand(list, count);
        break;
    case '-': // min
        findMin(list, count);
        break;
    case '+': // max
        findMax(list, count);
        break;
    case 'q': // quit
        cout << "Thank you for using Tire Tracker 2000!" << endl;
        break;
    default: // error
        cout << "Invalid entry." << endl;
        break;
    }
}

/*
  Name:   getInt()
  Desc:   reads integer from the user, provides data validation
  input:  int { numberBuffer }
  output: text
  return: none
*/
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

/*
  Name:   getDouble()
  Desc:   reads double from the user, provides data validation
  input:  double { numberBuffer }
  output: text
  return: none
*/
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

/*
  Name:   writeToFile()
  Desc:   writes TireData to "tires.txt"
  input:  none
  output: text
  return: none
*/
void writeToFile(TireData list[], int count)
{
    ofstream outFile("tires.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        outFile << list[i].dimensions << ";"
                << list[i].brand << ";"
                << list[i].style << ";"
                << list[i].price << endl;
    }

    outFile.close();
}

/*
  Name:   printIndex()
  Desc:   prints a specific TireData line item.
  input:  none
  output: TireData
  return: none
*/
void printIndex(TireData listItem)
{
    cout << listItem.dimensions << ";"
         << listItem.brand << ";"
         << listItem.style << ";"
         << listItem.price << endl
         << endl;
}

/*
  Name:   notFound()
  Desc:   Prompts the user that queried brand was not found.
  input:  none
  output: text
  return: none
*/
void notFound(char brand[])
{
    cout << "Target brand \x1b[48;5;242m " << brand << " \x1B[0m was not found.\n\n";
}