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

void fillStructString();

vector<string> setSectionString();

vector<string> unionSetString();

vector<string> differenceSetString(vector<string> firstSet, vector<string> secondSet);

bool subSetString(vector<string> firstSet, vector<string> secondSet);

bool findStringVector(vector<string> Set, string Word);

vector<string> inputSetString(int counter);

//---------------------------------------
int tokenize(string line, string* results, char delimiter);

string vectorIntToStringFile(vector<int>vector, char delimiter);

string vectorStringToStringFile(vector<string>vector, char delimiter);

int getID(int option);

void updateID(int option);

void stringToLocalSet(string firstSet, string secondSet);

void selectSetFromId(string fileName, int id);

void deleteSavedSetInt(int id);

void deleteSavedSetById(string fileName, int id, char delimiter);

string fileStringToPrintString(string set, char delimiter);

void addSetToFile(string fileName, int idOption, int type);

//-----------------------------------------

void backup();