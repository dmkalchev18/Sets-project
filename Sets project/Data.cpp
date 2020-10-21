#include "Data.h"

void inputSetInteger(int firstCounter, int secondCounter) {
	vector<int>intFirstSet;
	int input;

	for (int i = 0; i < firstCounter; i++)
	{
		cin >> input;
		intFirstSet.push_back(input);
	}

}

bool vectorIntFind(vector<int>set, int num) {
	for (int i = 0; i < set.size(); i++)
	{
		if (set[i] == num)
		{
			return true;
		}
	}
	return false;
}

bool subSetInteger(vector<int>firstSet, vector<int>secondSet) {
	int counter = 0;

	for (int i = 0; i < firstSet.size(); i++)
	{
		for (int j = 0; j < secondSet.size(); j++)
		{
			if (firstSet[i] == secondSet[j])
			{
				counter++;
			}
		}
	}
	if (counter == firstSet.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> unionSetInteger(vector<int>firstSet, vector<int>secondSet) {
	vector<int>unionSet;
	for (int i = 0; i < firstSet.size(); i++)
	{
		unionSet.push_back(firstSet[i]);
	}
	for (int i = 0; i < secondSet.size(); i++)
	{
		if (!vectorIntFind(unionSet, secondSet[i]))
		{
			unionSet.push_back(secondSet[i]);
		}
	}
	return unionSet;
}

//Do not test (still in progress)
vector<int> sectionSetInteger(vector<int>firstSet, vector<int>secondSet) {
	vector<int>sectionSet,tempSet;

	for (int i = 0; i < firstSet.size(); i++)
	{
		if (!vectorIntFind(secondSet, firstSet[i]))
		{
			tempSet.push_back(firstSet[i]);
		}
	}
	for (int i = 0; i < secondSet.size(); i++)
	{
		if (!vectorIntFind(tempSet, secondSet[i]))
		{
			tempSet.push_back(secondSet[i]);
		}
	}
	return sectionSet;
}

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet) {
	vector<int>differenceSet;
	for (int i = 0; i < firstSet.size(); i++)
	{
		if (!vectorIntFind(secondSet,firstSet[i]))
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}