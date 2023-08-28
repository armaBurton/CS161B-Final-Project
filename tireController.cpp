#include "tools.h"
#include "tireController.h"

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
  Name:   addTire()
  Desc:   collects tire data from the user to create a new entry
          in the TireData array
  input:  char { brand[], style[], position[] }, int{ width, ratio, diameter }, double { price }
  output: char { prompt[] }, text
  return: none
*/
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
    strcpy(prompt, "Tire Width: ");
    getInt(prompt, width);
    strcpy(prompt, "Tire Ratio: ");
    getInt(prompt, ratio);
    strcpy(prompt, "Tire Diameter: ");
    getInt(prompt, diameter);
    strcpy(prompt, "Price: ");
    getDouble(prompt, price);
    tireSizeBuilder(position, width, ratio, diameter);
    addToList(list, count, position, brand, style, price);

    cout << endl;
}

/*
  Name:   choosePosition()
  Desc:   Queries the user for the front or rear position
          of the tire
  input:  char positionBuffer
  output: text
  return: none
*/
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

/*
  Name:   positionText()
  Desc:   converts the character entry to a cstring based on user input
  input:  none
  output: text
  return: none
*/
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
        cout << "Invalid entry.\n";
        break;
    }
}

/*
  Name:   tireSizeBuilder()
  Desc:   converts integer values to characters and concats them to position[]
          to create data line
  input:  none
  output: none
  return: none
*/
void tireSizeBuilder(char position[], int width, int ratio, int diameter)
{
    char buffer[STRLEN] = "\0";
    strcat(position, " ");
    sprintf(buffer, "%d", width);
    strcat(position, buffer);
    strcat(position, "/");
    sprintf(buffer, "%d", ratio);
    strcat(position, buffer);
    strcat(position, "-");
    sprintf(buffer, "%d", diameter);
    strcat(position, buffer);
}

/*
  Name:   addToList()
  Desc:   appends new TireData item to array
  input:  none
  output: none
  return: none
*/
void addToList(TireData list[], int &count, char position[], char brand[], char style[], double price)
{
    cout << fixed << setprecision(2);
    strcpy(list[count].brand, brand);
    strcpy(list[count].style, style);
    strcpy(list[count].dimensions, position);
    list[count].price = price;
    count++;
    writeToFile(list, count);
}

/*
  Name:   findMin()
  Desc:   searches array for lowest priced tire and sends
          it to print index
  input:  none
  output: text
  return: none
*/
void findMin(TireData list[], int count)
{
    double tempMin = list[0].price;
    int index;

    for (int i = 0; i < count; i++)
    {
        if (tempMin > list[i].price)
        {
            tempMin = list[i].price;
            index = i;
        }
    }
    cout << "Min price: ";
    printIndex(list[index]);
}

/*
  Name:   findMax()
  Desc:   searches array for highest priced tire and sends
          it to print index
  input:  none
  output: text
  return: none
*/
void findMax(TireData list[], int count)
{
    double tempMin = list[0].price;
    int index;

    for (int i = 0; i < count; i++)
    {
        if (tempMin < list[i].price)
        {
            tempMin = list[i].price;
            index = i;
        }
    }
    cout << "Max Price: ";
    printIndex(list[index]);
}

/*
  Name:   findBrand()
  Desc:   searches array for the brand provided by the users and
          displays the result(s)
  input:  char { findBrand[] }
  output: text
  return: none
*/
void findBrand(TireData list[], int count)
{
    char findBrand[STRLEN], tempBrand[STRLEN];
    bool found = false;

    cout << "Enter the name of the brand you are searching for: ";
    cin.getline(findBrand, STRLEN, '\n');

    for (int i = 0; findBrand[i]; i++)
    {
        findBrand[i] = tolower(findBrand[i]);
    }
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        strcpy(tempBrand, list[i].brand);
        {
            for (int i = 0; tempBrand[i]; i++)
            {
                tempBrand[i] = tolower(tempBrand[i]);
            }
        }
        if (strcmp(findBrand, tempBrand) == 0)
        {
            printIndex(list[i]);
            found = true;
        }
    }
    if (found == false)
    {
        notFound(findBrand);
    }
}

/*
  Name:   findData()
  Desc:   removes index in the array from a user provided index
  input:  none
  output: none
  return: none
*/
void removeData(TireData list[], int &count, int index)
{
    for (int i = index; i < count; i++)
    {
        list[i] = list[i + 1];
    }
    count--;
}
