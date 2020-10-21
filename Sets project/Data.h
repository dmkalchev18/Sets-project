#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void inputSetInteger(int firstCounter, int secondCounter);

bool vectorIntFind(vector<int>set, int num);

bool subSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> unionSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> sectionSetInteger(vector<int>firstSet, vector<int>secondSet);

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet);