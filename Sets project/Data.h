#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> firstSetInt;

vector<int> secondSetInt;

vector<string> firstSetStr;

vector<string> secondSetStr;

vector<int> inputSetInteger(int counter);

bool vectorIntFind(vector<int>set, int num);

bool subSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> unionSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> sectionSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet);