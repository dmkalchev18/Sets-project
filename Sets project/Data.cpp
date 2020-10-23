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
		// Checks if num is a part of set 
		if (set[i] == num) 
		{
			return true;
		}
	}
	return false;
}

// Function checks if firstSet is a subset of secondSet
bool subSetInteger(vector<int>firstSet, vector<int>secondSet) { 
	int counter = 0;

	for (int i = 0; i < firstSet.size(); i++)
	{
		for (int j = 0; j < secondSet.size(); j++)
		{
			// Check if an element from firstSet is equal to any elements within secondSet
			if (firstSet[i] == secondSet[j]) 
			{
				counter++;
			}
		}
	}
	// If all elements in firstSet exist within secondSet, the counter will equal the size of firstSet
	if (counter == firstSet.size()) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function combines firstSet and secondSet into one set
vector<int> unionSetInteger(vector<int>firstSet, vector<int>secondSet) { 
	vector<int>unionSet;
	for (int i = 0; i < firstSet.size(); i++) 
	{
		// Add all elements from firstSet to unionSet
		unionSet.push_back(firstSet[i]); 
	}
	for (int i = 0; i < secondSet.size(); i++)
	{
		// Add all elements from secondSet that aren't already present in unionSet
		if (!vectorIntFind(unionSet, secondSet[i])) 
		{
			unionSet.push_back(secondSet[i]);
		}
	}
	return unionSet;
}

vector<int> sectionSetInteger(vector<int>firstSet, vector<int>secondSet) {

	vector<int>section;
	int counter=0;
	for (int i = 0; i < firstSet.size(); i++)
	{
		for (int x = 0; x < secondSet.size(); x++)
		{
			if (firstSet[i]==secondSet[x])
			{
				counter++;
			}
		}
		if (counter>0)
		{
			section.push_back(firstSet[i]);
		}
		counter = 0;
	}
	return section;
}

// Function returns all elements from firstSet that aren't present in secondSet
vector<int> differenceSetInteger(vector<int>firstSet, vector<int>secondSet) { 
	vector<int>differenceSet;
	for (int i = 0; i < firstSet.size(); i++)
	{
		// Checks which elements from firstSet don't appear in secondSet
		if (!vectorIntFind(secondSet,firstSet[i]))
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}