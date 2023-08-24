#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

const int MAXLEN = 250;
const int STRLEN = 30;

struct TireData
{
    char dimensions[MAXLEN];
    char brand[MAXLEN];
    char style[MAXLEN];
    double price;
};

bool loadData(TireData list[], int &count);
void writeToConsole(TireData list[], int count);
void addTire(TireData list[], int &count);