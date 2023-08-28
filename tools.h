#pragma once

#include "tireController.h"

const int LIST = 40;

bool loadData(TireData list[], int &count);
void greeting();
void menu();
void readOption(char *option);
void runOption(TireData list[], int &count, char *option);
void getInt(char prompt[], int &number);
void getDouble(char prompt[], double &number);
void writeToFile(TireData list[], int count);
void printIndex(TireData listItem);
void notFound(char brand[]);