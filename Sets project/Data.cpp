#include "Data.h"

// Function takes input from user which is then added into a set
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

// Function returns all common elements between two sets in a new set
vector<int> sectionSetInteger(vector<int>firstSet, vector<int>secondSet) {

	vector<int>section;
	int counter=0;
	for (int i = 0; i < firstSet.size(); i++)
	{
		for (int x = 0; x < secondSet.size(); x++)
		{
			// If an element from firstSet equals any element from secondSet, the counter will increment
			if (firstSet[i]==secondSet[x])
			{
				counter++;
			}
		}

		// If the counter is a value bigger than 0, the element from firstSet equal to an element from secondSet will be added to the new set
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

// ------------------------------------------
vector<string> inputSetString(int counter) {
	vector<string> stringSet;
	string stringVar;
	for (int i = 0; i < counter; i++)
	{
		cin >> stringVar;
		stringSet.push_back(stringVar);
	}
	return stringSet;
}

bool findStringVector (vector<string> Set, string Word) {
	for (int i = 0; i < Set.size(); i++)
	{
		if (Set[i] == Word) {
			return true;
		}
	}
	return false;
}

bool subSetString(vector<string> firstSet, vector<string> secondSet) {
	int counter = 0;
	for (int i = 0; i < firstSet.size(); i++) {
		for (int j = 0; j < secondSet.size(); j++) {

			if (firstSet[i] == secondSet[j]) {
				counter++;
			}
		}
	}
	if (counter == firstSet.size()) 
	{
		return true;
	}
	return false;
}

vector<string> unionSetIntiger(vector<string> firstSet, vector<string> secondSet) {
	vector<string> unionSet;
	for (int i = 0; i < firstSet.size(); i++) {
		unionSet.push_back(firstSet[i]);
	}

	for (int i = 0; i < secondSet.size(); i++) {
		if (!findStringVector(unionSet, secondSet[i])) {
			unionSet.push_back(secondSet[i]);
		}
	}
	return unionSet;
}

vector<string> setSectionString(vector<string> firstSet, vector<string> secondSet) {
	vector<string> section;
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

		if (counter > 0)
		{
			section.push_back(firstSet[i]);
		}
		counter = 0;
	}
	return section;
}

vector<string> differenceSetString(vector<string> firstSet, vector<string> secondSet) {
	vector<string> differenceSet; 

	for (int i = 0; i < firstSet.size(); i++) {
		if (!findStringVector(differenceSet, firstSet[i])) 
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}



