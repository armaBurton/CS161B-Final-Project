#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <limits>
#include <cstdio>

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
void choosePosition(char position[]);
void positionText(char position[], char buffer);
void tireSizeBuilder(char tireSize[], int width, int ratio, int diameter);
void addToList(TireData list[], int &count, char position[], char brand[], char style[], double price);
void findMin(TireData list[], int count);
