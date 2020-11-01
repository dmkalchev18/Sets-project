#pragma once
#include <iostream>
#include "Struct.h"
#include <string>
#include <vector>
#include<Windows.h>
#include <fstream>

using namespace std;

vector<int> inputSetInteger(int counter);

void fillStructInt();

bool vectorIntFind(vector<int>set, int num);

bool subSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> unionSetInteger();

vector<int> sectionSetInteger();

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet);
void gotoxy(int x, int y);
//---------------------------------------

//void addSetToHistory() {};

//-----------------------------------------

void backup();