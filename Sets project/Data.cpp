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
		if (set[i] == num) //Checks if num is a part of set 
		{
			return true;
		}
	}
	return false;
}

bool subSetInteger(vector<int>firstSet, vector<int>secondSet) { //Function checks if firstSet is a subset of secondSet
	int counter = 0;

	for (int i = 0; i < firstSet.size(); i++)
	{
		for (int j = 0; j < secondSet.size(); j++)
		{
			if (firstSet[i] == secondSet[j]) //Check if an element from firstSet is equal to any elements within secondSet
			{
				counter++;
			}
		}
	}
	if (counter == firstSet.size()) // If all elements in firstSet exist within secondSet, the counter will equal the size of firstSet
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> unionSetInteger(vector<int>firstSet, vector<int>secondSet) { //Function combines firstSet and secondSet into one set
	vector<int>unionSet;
	for (int i = 0; i < firstSet.size(); i++) 
	{
		unionSet.push_back(firstSet[i]); //Add all elements from firstSet to unionSet
	}
	for (int i = 0; i < secondSet.size(); i++)
	{
		if (!vectorIntFind(unionSet, secondSet[i])) //Add all elements from secondSet that aren't already present in unionSet
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

vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet) { //Function returns all elements from firstSet that aren't present in secondSet
	vector<int>differenceSet;
	for (int i = 0; i < firstSet.size(); i++)
	{
		if (!vectorIntFind(secondSet,firstSet[i])) //Checks which elements from firstSet don't appear in secondSet
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}