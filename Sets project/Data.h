#pragma once
#include <iostream>
#include "Struct.h"
#include <string>
#include <vector>
#include<Windows.h>
#include <fstream>

using namespace std;

bool checkInputInt(string str);

vector<int> inputSetInteger(int counter, int charactersToIgnore);

void fillStructInt();

bool vectorIntFind(vector<int>set, int num);

bool subSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> unionSetInteger();

vector<int> sectionSetInteger();

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet);
void gotoxy(int x, int y);
//---------------------------------------
int tokenize(string line, string* results, char delimiter);

void addSetToHistory();

string vectorToStringFile(vector<int>vector, char delimiter);

int getID(int option);

void updateID(int option);

void addSetToSaveFile();

void stringToLocalSet(string firstSet, string secondSet);

void selectSetFromId(string fileName, int id);

void deleteSavedSetInt(int id);

string fileStringToPrintString(string set, char delimiter);

//-----------------------------------------

void backup();