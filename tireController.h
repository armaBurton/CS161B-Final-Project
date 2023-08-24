#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAXLEN = 250;

struct TireData
{
    char dimensions[MAXLEN];
    char brand[MAXLEN];
    char style[MAXLEN];
    double price;
};

bool loadData(TireData list[], int &count);