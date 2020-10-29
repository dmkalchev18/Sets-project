#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> inputSetInteger(int counter);

void fillStructInt();

bool vectorIntFind(vector<int>set, int num);

bool subSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> unionSetInteger();

vector<int> sectionSetInteger();

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet);

//---------------------------------------

void addSetToHistory() {};