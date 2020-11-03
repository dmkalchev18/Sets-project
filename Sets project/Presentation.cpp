#include "Presentation.h"
#include "Data.h"
#include <string>
#include<Windows.h>
#include <vector>



void displayBorder() {
	for (int i = 0; i < 120; i++) {
		cout << char(177);
	}
}
void greetings() {
	cout << "\t\t\t\t\t\t  Hello User,\n";
	cout << "\n\t\t   Welcome to the <program_name> !!! ";
	cout << "We are thankful that you use our program\n\n";
	cout << "\t\t\t\t\t\t  Have fun!!!\n\n";
}
void goodbyeMessage() {
	cout << "\n\n\nThank you for using <program_name>!!!\n";
	cout << "Copyright (c) 2020 Technical Knockout\n";
}

void horizontalBorder(int n) {
	for (auto i = 0; i < n; i++) {
		cout << char(205);
	}
}

void printUpperSide(int n, bool isEnd = true, char indicator = 'd') {
	cout << char(201); //upper side of the square symbol  
	horizontalBorder(n);
	if (isEnd)
	{
		cout << char(187);//upper right corner symbol
		cout << endl;
	}

	else
	{
		if (indicator == 'b') {
			cout << char(185);//T like crossroad symbol
		}
		else
		{
			cout << char(206);//crossroad symbol
		}
	}
}

void printStars(int n) {
	for (auto i = 0; i < n; i++) {
		cout << "* ";
	}
}

void printSpace(int n) {
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}
}

void displayDownSide(int n, bool isEnd = true, char indicator = 'd') {
	cout << char(200);//down left corner symbol
	horizontalBorder(n);
	if (isEnd) {
		cout << char(188);//down right corner symbol
		cout << endl;
	}
	else
	{
		if (indicator == 'b') {
			cout << char(185);//T like crossroad symbol
		}
		else
		{
			cout << char(206);//crossroad symbol
		}

	}
}

void printSideForDifference(int n) {
	for (int i = 0; i < n; i++) {
		cout << char(186);//barrier symbol
		printStars(10);
		cout << char(186);
		cout << endl;
	}
}

void printSideForSubset(int n) {
	for (int i = 0; i < n; i++) {
		cout << char(186);//barrier symbol
		printSpace(10);
		cout << char(186);
		cout << endl;
	}
}



// the side of the square
//u-union
//s - section
//d-difference
//b-subset
void displaySide(int n, char indicator) {
	switch (indicator) {
	case 'u':printSideForDifference(n); break;
	case 's':printSideForSubset(n); break;
	case 'd':printSideForDifference(n); break;
	case 'b':printSideForSubset(n); break;
	}

}

void printUpperSideToSideDifference(int n) {
	printUpperSide(9, false);
	horizontalBorder(6);
	cout << char(187);
}

void printDownSideToSideDifference(int n) {
	displayDownSide(9, false);
	horizontalBorder(6);
	cout << char(188);
}
void printMiddleSideToSideDifference(char indicator = 'd') {
	cout << char(186);//border symbol
	if (indicator == 's') {

		printStars(4);
		cout << "*";
		cout << char(186);
		printSpace(3);

	}
	else if (indicator == 't') {
		printSpace(4);
		cout << " ";
		cout << char(186);
		printStars(3);
	}
	else
	{
		printSpace(4);
		cout << " ";
		cout << char(186);
		printSpace(3);
	}
}

void printMiddleSideToSideSubset(char indicator = 'u') {
	if (indicator == 'u') {
		printStars(5);
	}
	else
	{
		printSpace(5);
	}

	cout << char(186);
	printStars(4);
	cout << "*";
	if (indicator == 'u') {
		cout << char(186);
		printStars(3);
	}
}

// where the two squares meet
void showSideToSide(int n, char m) {

	for (int i = 0; i < n; i++) {
		cout << char(186);

		if (i == 0) {//printing the upper side of the small square
			switch (m) {
			case 'u':printStars(5); printUpperSideToSideDifference(n); break;
			case 's':printSpace(5); printUpperSideToSideDifference(n); break;
			case 'd':printStars(5); printUpperSideToSideDifference(n); break;
			case 'b':printSpace(5); printUpperSide(9, false, 'b'); break;
			case 't':printStars(5); printUpperSideToSideDifference(n); break;
			}

		}
		else if (i == n - 1) {//printing the down side of the small square


			switch (m) {
			case 'u':printStars(5); printDownSideToSideDifference(n); break;
			case 's':printSpace(5); printDownSideToSideDifference(n); break;
			case 'd':printStars(5); printDownSideToSideDifference(n); break;
			case 'b':printSpace(5); displayDownSide(9, false, 'b'); break;
			case 't':printStars(5); printDownSideToSideDifference(n); break;
			}
		}
		else {//printing the other two sides 


			switch (m) {
			case 'u': printMiddleSideToSideSubset('u'); break;
			case 's':printSpace(5); printMiddleSideToSideDifference('s'); break;
			case 'd':printStars(5); printMiddleSideToSideDifference(); break;
			case 'b':printMiddleSideToSideSubset('b'); break;
			case 't':printStars(5); printMiddleSideToSideDifference('t'); break;
			}
			cout << char(186);
		}

		cout << endl;

	}

}

void displayDifferenceFigure() {
	printUpperSide(20);
	displaySide(1, 'd');
	showSideToSide(8, 'd');
	displaySide(1, 'd');
	displayDownSide(20);
}


void displaySubsetFigure() {
	printUpperSide(20);
	displaySide(1, 'b');
	showSideToSide(8, 'b');
	displayDownSide(20);
}

void displaySectionFigure() {
	printUpperSide(20);
	displaySide(1, 's');
	showSideToSide(8, 's');
	displayDownSide(20);
}

void displayUnionFigure() {
	printUpperSide(20);
	displaySide(1, 'u');
	showSideToSide(8, 'u');
	displayDownSide(20);
}

void displaySimetricDifferenceFigure() {
	printUpperSide(20);
	displaySide(1, 'd');
	showSideToSide(8, 't');
	displayDownSide(20);
}

void setInputInt() {
	//system("cls");
	string userInput;
	displayBorder();
	displayBorder();
	cout << "\n\n\t\t\t\t\t\t  Sets input integer numbers\n";
	cout << "Enter how many numbers you want in your first set: ";
	cin.ignore(52, '\n');
	getline(cin, userInput);
	if (!checkInputInt(userInput))
	{
		cout << "Invalid input. The input must be number";
		showSetsFromNumbersMenu();
	}

	cout << "\n\nEnter the numbers: ";
	intStructure.firstSet = inputSetInteger(stoi(userInput),20);
	if (intStructure.firstSet.empty())
	{
		cout << "Invalid input. The input must be set of numbers";
		showSetsFromNumbersMenu();
	}
	cout << "\n\nEnter how many numbers you want in your second set: ";
	getline(cin, userInput);
	if (!checkInputInt(userInput))
	{
		cout << "Invalid input. The input must be number";
		showSetsFromNumbersMenu();
	}

	cout << "\n\nEnter the numbers: ";
	intStructure.secondSet = inputSetInteger(stoi(userInput),22);
	if (intStructure.secondSet.empty())
	{
		cout << "Invalid input. The input must be set of numbers";
		showSetsFromNumbersMenu();
	}

}

bool areTheVectorsFull() {
	if (intStructure.firstSet.size() == 0) {
		return false;
	}
	return true;
}

void showSetsOfNumbers() {
	system("cls");
	if (areTheVectorsFull()) {
		cout << "\n First Set: ";
		for (int i = 0; i < intStructure.firstSet.size(); i++)
		{
			cout << intStructure.firstSet[i] << " ";
		}
		cout << "\n\n Second Set: ";
		for (int i = 0; i < intStructure.secondSet.size(); i++)
		{
			cout << intStructure.secondSet[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

void showTheSubsets() {
	system("cls");
	if (areTheVectorsFull()) {
		displaySubsetFigure();
		if (intStructure.firstIsSub) {
			cout << "\n\nThe first set is subset.\n\n";
			for (int i = 0; i < intStructure.firstSet.size(); i++)
			{
				cout << intStructure.firstSet[i] << " ";
			}
		}
		else if(intStructure.secondIsSub)
		{
			cout << "\n\nThe second set is subset.\n\n";
				for (int i = 0; i < intStructure.secondSet.size(); i++)
				{
					cout << intStructure.secondSet[i] << " ";
				}
		}
		else
		{
			cout << "\n\n There is no subset.\n\n";
		}
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

void showTheUnion() {
	system("cls");
	if (areTheVectorsFull()) {
		displayUnionFigure();
		cout << "\n\n";
		for (int i = 0; i < intStructure.unionSet.size(); i++)
		{
			cout << intStructure.unionSet[i] << " ";
		}
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

void showTheSections() {
	system("cls");
	if (areTheVectorsFull()) {
		displaySectionFigure();
		cout << "\n\n";
		for (int i = 0; i < intStructure.section.size(); i++)
		{
			cout << intStructure.section[i] << " ";
		}
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

void showTheDifference() {
	system("cls");
	if (areTheVectorsFull()) {
		displayDifferenceFigure();
		cout << "\n\n The first difference: ";
		for (int  i = 0; i < intStructure.firstDiff.size(); i++)
		{
			cout << intStructure.firstDiff[i] << " ";
		}
		cout << "\n\n the second difference: ";
		for (int i = 0; i < intStructure.secondDiff.size(); i++)
		{
			cout << intStructure.secondDiff[i] << " ";
		}
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

void showTheSimetricDifference() {
	system("cls");
	if (areTheVectorsFull()) {
		displaySimetricDifferenceFigure();
	}
	else
	{
		cout << "\n\t\t\tYou haven't entered any numbers!!! Go and type some!\n";
	}
	cout << "\n";
	system("pause");
}

bool showSetsFromNumbersMenu() {
	system("cls");
	int userInput;
	cout << " \t\t Sets Of Numbers Menu";
	cout << "\n1. Enter sets\n";
	cout << "2. Display the entered sets\n";
	cout << "3. Display the subsets\n";
	cout << "4. Display the unions\n";
	cout << "5. Display the section\n";
	cout << "6. Display the difference\n";
	cout << "7. Display the simetric difference\n";
	cout << "8. Return to Main Menu\n";
	cout << "Enter your choice: ";
	cin >> userInput;
	switch (userInput)
	{
	case 1:setInputInt(); fillStructInt(); addSetToHistory(); addSetToSaveFile(); break;
	case 2:showSetsOfNumbers(); break;
	case 3:showTheSubsets(); break;
	case 4:showTheUnion(); break;
	case 5:showTheSections(); break;
	case 6:showTheDifference(); break;
	case 7:showTheSimetricDifference(); break;
	case 10: showFileContent("history");
	case 8:return false; break;
	default: {cout << "Incorrect input!!! Try again!\n\n"; return false;
		break; }
	}
	return true;
}

bool showMenu() {


	int userInput;

	displayBorder();

	cout << "\n\n\t\t\t\t\t\t  Main Menu:\n";
	cout << "\t\t\t1. Sets from numbers\n";
	cout << "\t\t\t2. Sets from words\n";
	cout << "\t\t\t3. Sets from letters\n";
	cout << "\t\t\t4. Exit\n";

	displayBorder();

	cout << "\n\nEnter your choice: ";
	cin >> userInput;
	switch (userInput)
	{
	case 1:while (showSetsFromNumbersMenu()); break;
	case 2:break;
	case 3:break;
	case 4:return false; break;
	default:cout << "Incorrect input!!! Please try again!\n"; return false;
		break;
	}
	return true;

}

void showFileContent(string fileName) {
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

				cout << "ID: " << content[0] << endl
					<< "First set: " << fileStringToPrintString(content[1], '|') << endl
					<< "Second set: " << fileStringToPrintString(content[2], '|') << endl
					<< "Firsd difference set: " << fileStringToPrintString(content[3], '|') << endl
					<< "Second difference set: " << fileStringToPrintString(content[4], '|') << endl
					<< "Section set: " << fileStringToPrintString(content[5], '|') << endl
					<< "Union set: " << fileStringToPrintString(content[6], '|') << endl
					<< "First is sub-set of the second: ";
				if (content[7]=="1")
				{
					cout << "Yes"<<endl;
				}
				else
				{
					cout << "No"<<endl;
				}
				cout<< "Second is sub-set of the first: ";
				if (content[8] == "1")
				{
					cout << "Yes"<<endl;
				}
				else
				{
					cout << "No"<<endl;
				}
			}
			cout << "-----------------------------------------------------" << endl;
		}
	}
	
	file.close();
}