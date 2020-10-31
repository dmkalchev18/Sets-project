#include "Presentation.h"
#include "Data.h"
#include <string>
#include <vector>



void border() {
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

void setInputInt() {
	int userInput;
	border();
	border();
	cout << "\n\n\t\t\t\t\t\t  Sets input integer numbers\n";
	cout << "Enter how many numbers you want in your first set: ";
	cin >> userInput;

	cout << "\n\nEnter the numbers: ";
	intStructure.firstSet = inputSetInteger(userInput);

	cout << "\n\nEnter how many numbers you want in your second set: ";
	cin >> userInput;

	cout << "\n\nEnter the numbers: ";
	intStructure.secondSet = inputSetInteger(userInput);

}

void showSetsOfNumbers() {
	system("cls");
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
	system("pause");
}

void showTheSubsets() {
	system("cls");

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
	cout << "7. Return to Main Menu\n";
	cout << "Enter your choice: ";
	cin >> userInput;
	switch (userInput)
	{
	case 1:setInputInt(); fillStructInt(); break;
	case 2:showSetsOfNumbers(); break;
	case 3:showTheSubsets(); break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:return false; break;
	default: {cout << "Incorrect input!!! Try again!\n\n"; return false;
		break; }
	}
	return true;
}

bool showMenu() {
	

	int userInput;

	border();

	cout << "\n\t\t\t\t\t\t  Main Menu:\n";
	cout << "\t\t\t1. Sets from numbers\n";
	cout << "\t\t\t2. Sets from words\n";
	cout << "\t\t\t3. Sets from letters\n";
	cout << "\t\t\t4. Exit\n";

	border();

	cout << "\n\nEnter your choice: ";
	cin >> userInput;
	switch (userInput)
	{
	case 1:while(showSetsFromNumbersMenu()); break;
	case 2:break;
	case 3:break;
	case 4:return false; break;
	default:cout << "Incorrect input!!! Please try again!\n"; return false;
		break;
	}
	return true;

}