#include "Data.h"
#include<Windows.h>

SETINT intStructure;
SETSTRING stringStructure;
// Function takes input from user which is then added into a set
vector<int> inputSetInteger(int counter,int charactersToIgnore) {
	vector<int>intSet;
	string input,validInput[40];
	getline(cin, input);
	input = input + " ";
	if (!checkInputInt(input))
	{
		return intSet;
	}
	tokenize(input, validInput, ' ');
	for (int i = 0; i < counter; i++)
	{
		intSet.push_back(stoi(validInput[i]));
	}
	return intSet;
}

// Function validates given input
bool checkInputInt(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])&& str[i]!=' ')
		{
			return false;
		}
	}
	return true;
}

// Function fills a structure with data from the sets, entered by the user, alongside the operations performed with them
void fillStructInt() {
	intStructure.firstDiff = differenceSetInteger(intStructure.firstSet, intStructure.secondSet);
	intStructure.secondDiff = differenceSetInteger(intStructure.secondSet, intStructure.firstSet);
	intStructure.section = sectionSetInteger();
	intStructure.unionSet = unionSetInteger();
	intStructure.firstIsSub = subSetInteger(intStructure.firstSet, intStructure.secondSet);
	intStructure.secondIsSub = subSetInteger(intStructure.secondSet, intStructure.firstSet);
}

// Searches a set for a given number
bool vectorIntFind(vector<int>set, int num) {
	for (int i = 0; i < set.size(); i++)
	{
		// Checks if number is a part of set 
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
	return false;
}

// Function combines firstSet and secondSet into one set
vector<int> unionSetInteger() {
	vector<int>unionSet;
	for (int i = 0; i < intStructure.firstSet.size(); i++)
	{
		// Add all elements from firstSet to unionSet
		unionSet.push_back(intStructure.firstSet[i]);
	}
	for (int i = 0; i < intStructure.secondSet.size(); i++)
	{
		// Add all elements from secondSet that aren't already present in unionSet
		if (!vectorIntFind(unionSet, intStructure.secondSet[i]))
		{
			unionSet.push_back(intStructure.secondSet[i]);
		}
	}
	return unionSet;
}

// Function returns all common elements between two sets in a new set
vector<int> sectionSetInteger() {

	vector<int>section;
	int counter = 0;
	for (int i = 0; i < intStructure.firstSet.size(); i++)
	{
		for (int x = 0; x < intStructure.secondSet.size(); x++)
		{
			// If an element from firstSet equals any element from secondSet, the counter will increment
			if (intStructure.firstSet[i] == intStructure.secondSet[x])
			{
				counter++;
			}
		}

		// If the counter is a value bigger than 0, the element from firstSet equal to an element from secondSet will be added to the new set
		if (counter > 0)
		{
			section.push_back(intStructure.firstSet[i]);
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
		if (!vectorIntFind(secondSet, firstSet[i]))
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}

// ------------------------------------------
void fillStructString() {
	stringStructure.firstDiff = differenceSetString(stringStructure.firstSet, stringStructure.secondSet);
	stringStructure.secondDiff = differenceSetString(stringStructure.secondSet, stringStructure.firstSet);
	stringStructure.section = setSectionString();
	stringStructure.unionSet = unionSetString();
	stringStructure.firstIsSub = subSetString(stringStructure.firstSet, stringStructure.secondSet);
	stringStructure.secondIsSub = subSetString(stringStructure.secondSet, stringStructure.firstSet);
}

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

bool findStringVector(vector<string> Set, string Word) {
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

vector<string> unionSetString() {
	vector<string> unionSet;
	for (int i = 0; i < stringStructure.firstSet.size(); i++) {
		unionSet.push_back(stringStructure.firstSet[i]);
	}

	for (int i = 0; i < stringStructure.secondSet.size(); i++) {
		if (!findStringVector(unionSet, stringStructure.secondSet[i])) {
			unionSet.push_back(stringStructure.secondSet[i]);
		}
	}
	return unionSet;
}

vector<string> setSectionString() {
	vector<string> section;
	int counter = 0;
	for (int i = 0; i < stringStructure.firstSet.size(); i++)
	{
		for (int j = 0; j < stringStructure.secondSet.size(); j++)
		{
			if (stringStructure.firstSet[i] == stringStructure.secondSet[j])
			{
				counter++;
			}
		}

		if (counter > 0)
		{
			section.push_back(stringStructure.firstSet[i]);
		}
		counter = 0;
	}
	return section;
}

vector<string> differenceSetString(vector<string> firstSet, vector<string> secondSet) {
	vector<string> differenceSet;

	for (int i = 0; i < firstSet.size(); i++) {
		if (!findStringVector(secondSet, firstSet[i]))
		{
			differenceSet.push_back(firstSet[i]);
		}
	}
	return differenceSet;
}

void gotoxy(int x, int y) {
	COORD pos = { x, y - 1 };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

//-------------------------------------------------------

// Function takes a formatted set from a file and transforms it into a more readable form
string fileStringToPrintString(string set, char delimiter) {
	string newString,content[40];
	int i=0;
	
	// Formatted set is broken into pieces, split by a delimiter, which are passed onto to the "content" array 
	tokenize(set, content, delimiter);

	while (content[i]!="") {
		newString = newString + content[i]+" ";
		i++;
	}

	return newString;
}


void stringToLocalSet(string firstSet, string secondSet) {
	vector<int>firstSetInt, secondSetInt;
	string firstContent[60], secondContent[60];
	int i = 0, j = 0;
	

	tokenize(firstSet, firstContent, '|');
	tokenize(secondSet, secondContent, '|');
	
	while (true)
	{
		if (firstContent[i] != "")
		{
			firstSetInt.push_back(stoi(firstContent[i]));
			i++;
		}
		if (secondContent[j] != "")
		{
			secondSetInt.push_back(stoi(secondContent[j]));
			j++;
		}
		if (firstContent[i] == "" && secondContent[j] == "")
		{
			break;
		}
	}
	intStructure.firstSet = firstSetInt;
	intStructure.secondSet = secondSetInt;
	fillStructInt();
}

void selectSetFromId(string fileName, int id) {
	ifstream file(fileName + ".txt");
	string line, content[10];
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			if (line != "")
			{
				tokenize(line, content, ',');
				if (stoi(content[0]) == id)
				{
					stringToLocalSet(content[1], content[2]);
				}
			}
		}
	}
	file.close();
}

// Function splits a string "line" into separate parts using given delimiter. Split parts are returned via pointer to a storage variable
int tokenize(string line, string* results, char delimiter) {
	string tmp;
	int counter = 0, count = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == delimiter)
		{ 
			results[counter++] = tmp;
			tmp = "";
			i++;
		}
		tmp += line[i];
	}
	return counter;
}

// Function takes elements from a vector and turns them into a string that is ready to be stored in a file
string vectorIntToStringFile(vector<int>vector, char delimiter) {
	string str;
	for (int i = 0; i < vector.size(); i++)
	{
		str = str + to_string(vector[i]) + delimiter;
	}
	if (str=="")
	{
		str = " ";
	}
	return str;
}

string vectorStringToStringFile(vector<string>vector, char delimiter) {
	string str;
	for (int i = 0; i < vector.size(); i++)
	{
		str = str + vector[i] + delimiter;
	}
	if (str == "")
	{
		str = " ";
	}
	return str;
}

// Function deletes a saved set from the save file
void deleteSavedSetInt(int id) {
	ifstream saveFile("saveInt.txt");
	ofstream newFile("newSave.txt");
	string content[10], help;
	string line;

	if (saveFile.is_open())
	{
		string line;
		while (!saveFile.eof())
		{
			getline(saveFile, line);

			if (line != "") {

				tokenize(line, content, ',');
				if (stoi(content[0])==id)
				{

				}
				else
				{
					newFile << content[0] << "," << content[1] << "," << content[2] << "," << content[3] << "," << content[4] << "," << content[5] << "," << content[6] << "," << content[7] << "," << content[8] << "," << endl;
				}
			}
		}
		newFile.close();
		saveFile.close();

		
		if (remove("saveInt.txt") != 0) {
			cout << "A wild error appeared!!!!" << endl;
		}
		else {
			cout << "Deleting set 50% done" << endl;
		}



		if (rename("newSave.txt", "saveInt.txt") != 0) {
			cout<< "A wild error appeared!!!!!"<< endl;
		}
		else
		{
			cout << "Deleting set done!!!!" << endl;
		}
	}
}

void deleteSavedSetById(string fileName, int id, char delimiter) {
	string basicFileName = fileName + ".txt", newFileName = fileName + "New.txt";
	ifstream saveFile(basicFileName);
	ofstream newFile(newFileName);
	string content[10], help;
	string line;

	if (saveFile.is_open())
	{
		string line;
		while (!saveFile.eof())
		{
			getline(saveFile, line);

			if (line != "") {

				tokenize(line, content, delimiter);
				if (stoi(content[0]) == id)
				{

				}
				else
				{
					newFile << content[0] << delimiter << content[1] << delimiter << content[2] << delimiter << content[3] << delimiter << content[4] << delimiter << content[5] << delimiter << content[6] << delimiter << content[7] << delimiter << content[8] << delimiter << endl;
				}
			}
		}
		newFile.close();
		saveFile.close();


		if (remove(basicFileName.c_str()) != 0) {
			cout << "A wild error appeared!!!!" << endl;
		}
		else {
			cout << "Deleting set 50% done" << endl;
		}



		if (rename(newFileName.c_str(), basicFileName.c_str()) != 0) {
			cout << "A wild error appeared!!!!!" << endl;
		}
		else
		{
			cout << "Deleting set done!!!!" << endl;
		}
	}
}

// Function returns an ID contained within the history
int getID(int option) {
	ifstream idFile("id.txt");
	string line, id[10];
	if (idFile.is_open())
	{
		getline(idFile, line);
		if (line != " " and line!="")
		{
			tokenize(line, id, ',');
			return stoi(id[option - 1]);
		}
	}
	return -1;
}

// Function updates an ID contained within the history
void updateID(int option) {
	ifstream idFile("id.txt");
	ofstream newIdFile("newId.txt");
	string line, content[10];

	if (idFile.is_open())
	{
		getline(idFile, line);
		tokenize(line, content, ',');
		if (newIdFile.is_open())
		{
			switch (option)
			{
			case 1:
				newIdFile << stoi(content[0]) + 1 << "," << content[1] << "," << content[2] << "," << content[3] << ",";
				break;
			case 2:
				newIdFile << content[0] << "," << stoi(content[1]) + 1 << "," << content[2] << "," << content[3] << ",";
				break;
			case 3:
				newIdFile << content[0] << "," << content[1] << "," << stoi(content[2]) + 1 << "," << content[3] << ",";
				break;
			case 4:
				newIdFile << content[0] << "," << content[1] << "," << content[2] << "," << stoi(content[3]) + 1 << ",";
				break;
			default:
				break;
			}
		}
	}
	idFile.close();

	if (remove("id.txt") != 0) {
		cout << "A wild error appeared!!!!";
	}
	else {

	}

	newIdFile.close();

	if (rename("newId.txt", "id.txt") != 0)
	{
		cout << "A wild error appeared!!!";
	}
	else
	{
	}
}

// Function adds a set to a file, containing all sets entered by the user
void addSetToFile(string fileName, int idOption, int type) {
	ofstream myFile(fileName + ".txt", ios::app);
	int id = getID(idOption);

	switch (type)
	{
	case 1:
		if (myFile.is_open())
		{
			myFile << id << "," << vectorIntToStringFile(intStructure.firstSet, '|') << "/"
				<< vectorIntToStringFile(intStructure.secondSet, '|') << "/"
				<< vectorIntToStringFile(intStructure.firstDiff, '|') << "/"
				<< vectorIntToStringFile(intStructure.secondDiff, '|') << "/"
				<< vectorIntToStringFile(intStructure.section, '|') << "/"
				<< vectorIntToStringFile(intStructure.unionSet, '|') << "/"
				<< intStructure.firstIsSub << "/" << intStructure.secondIsSub << "/" << endl;
		}
		break;
	case 2:
		if (myFile.is_open())
		{
			myFile << id << "/" << vectorStringToStringFile(stringStructure.firstSet, '^') << "/"
				<< vectorStringToStringFile(stringStructure.secondSet, '^') << "/"
				<< vectorStringToStringFile(stringStructure.firstDiff, '^') << "/"
				<< vectorStringToStringFile(stringStructure.secondDiff, '^') << "/"
				<< vectorStringToStringFile(stringStructure.section, '^') << "/"
				<< vectorStringToStringFile(stringStructure.unionSet, '^') << "/"
				<< stringStructure.firstIsSub << "/" << stringStructure.secondIsSub << "/" << endl;
		}
		break;
	default:
		break;
	}
	myFile.close();
	updateID(idOption);
}
//-------------------------------------------------------

// Function creates a backup of all files within the project
void backup() {
	system("robocopy /E ..\\..\\Sets-project ..\\..\\Sets-project-backup-%DATE:~10,4%-%DATE:~4,2%-%DATE:~7,2%_%TIME:~0,2%-%TIME:~3,2%");
	system("cls");
}

//7
//1 2 3 4 5 6 7
//4
//1 2 3 4