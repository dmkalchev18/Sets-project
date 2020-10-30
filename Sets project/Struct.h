#pragma once
#include <vector>
using namespace std;

struct SETINT
{
	vector<int> firstSet,secondSet;
	vector<int> firstDiff, secondDiff, section, unionSet;
	bool firstIsSub =false, secondIsSub=false;
};

extern SETINT intStructure;
