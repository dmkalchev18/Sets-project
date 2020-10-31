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

//   horizontal border
void horizontalBorder(int n) {
	for (auto i = 0; i < n; i++) {
		cout << char(205);
	}
}

void upperSide(int n, bool flag = true, char m = 'd') {
	cout << char(201); //upper side of the square    
	horizontalBorder(n);
	if (flag)
	{
		cout << char(187);
		cout << endl;
	}

	else
	{
		if (m == 'b') {
			cout << char(185);
		}
		else
		{
			cout << char(206);
		}
	}
}

void stars(int n) {
	for (auto i = 0; i < n; i++) {
		cout << "* ";
	}
}

void space(int n) {
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}
}

void downSide(int n, bool flag = true, char m = 'd') {
	cout << char(200);//down side of the square
	horizontalBorder(n);
	if (flag) {
		cout << char(188);
		cout << endl;
	}
	else
	{
		if (m == 'b') {
			cout << char(185);
		}
		else
		{
			cout << char(206);
		}

	}
}

void sideForDifference(int n) {
	for (int i = 0; i < n; i++) {
		cout << char(186);//barrier symbol
		stars(10);
		cout << char(186);
		cout << endl;
	}
}

void sideForSubset(int n) {
	for (int i = 0; i < n; i++) {
		cout << char(186);//barrier symbol
		space(10);
		cout << char(186);
		cout << endl;
	}
}



// the side of the square
//u-union
//s - section
//d-difference
//b-subset
void side(int n, char m) {
	switch (m) {
	case 'u':sideForDifference(n); break;
	case 's':sideForSubset(n); break;
	case 'd':sideForDifference(n); break;
	case 'b':sideForSubset(n); break;
	}

}

void upperSideToSideDifference(int n) {
	upperSide(9, false);
	horizontalBorder(6);
	cout << char(187);
}

void downSideToSideDifference(int n) {
	downSide(9, false);
	horizontalBorder(6);
	cout << char(188);
}
void middleSideToSideDifference(char m = 'd') {
	cout << char(186);
	if (m == 's') {

		stars(4);
		cout << "*";
		cout << char(186);
		space(3);

	}
	else if (m == 't') {
		space(4);
		cout << " ";
		cout << char(186);
		stars(3);
	}
	else
	{
		space(4);
		cout << " ";
		cout << char(186);
		space(3);
	}
}

void middleSideToSideSubset(char m = 'u') {
	if (m == 'u') {
		stars(5);
	}
	else
	{
		space(5);
	}

	cout << char(186);
	stars(4);
	cout << "*";
	if (m == 'u') {
		cout << char(186);
		stars(3);
	}
}

// where the two squares meet
void sideToSide(int n, char m) {

	for (int i = 0; i < n; i++) {
		cout << char(186);

		if (i == 0) {//printing the upper side of the small square
			switch (m) {
			case 'u':stars(5); upperSideToSideDifference(n); break;
			case 's':space(5); upperSideToSideDifference(n); break;
			case 'd':stars(5); upperSideToSideDifference(n); break;
			case 'b':space(5); upperSide(9, false, 'b'); break;
			case 't':stars(5); upperSideToSideDifference(n); break;
			}

		}
		else if (i == n - 1) {//printing the down side of the small square


			switch (m) {
			case 'u':stars(5); downSideToSideDifference(n); break;
			case 's':space(5); downSideToSideDifference(n); break;
			case 'd':stars(5); downSideToSideDifference(n); break;
			case 'b':space(5); downSide(9, false, 'b'); break;
			case 't':stars(5); downSideToSideDifference(n); break;
			}
		}
		else {//printing the other two sides 


			switch (m) {
			case 'u': middleSideToSideSubset('u'); break;
			case 's':space(5); middleSideToSideDifference('s'); break;
			case 'd':stars(5); middleSideToSideDifference(); break;
			case 'b':middleSideToSideSubset('b'); break;
			case 't':stars(5); middleSideToSideDifference('t'); break;
			}
			cout << char(186);
		}

		cout << endl;

	}

}

void difference() {
	upperSide(20);
	side(1, 'd');
	sideToSide(8, 'd');
	side(1, 'd');
	downSide(20);
}


void subset() {
	upperSide(20);
	side(1, 'b');
	sideToSide(8, 'b');
	downSide(20);
}

void section() {
	upperSide(20);
	side(1, 's');
	sideToSide(8, 's');
	downSide(20);
}

void Union() {
	upperSide(20);
	side(1, 'u');
	sideToSide(8, 'u');
	downSide(20);
}

void simetricDifference() {
	upperSide(20);
	side(1, 'd');
	sideToSide(8, 't');
	downSide(20);
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
	subset();
	system("pause");
}

void showTheUnion() {
	system("cls");
	Union();
	system("pause");
}

void showTheSections() {
	system("cls");
	section();
	system("pause");
}

void showTheDifference() {
	system("cls");
	difference();
	system("pause");
}

void showTheSimetricDifference() {
	system("cls");
	simetricDifference();
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
	case 1:setInputInt(); fillStructInt(); break;
	case 2:showSetsOfNumbers(); break;
	case 3:showTheSubsets(); break;
	case 4:showTheUnion(); break;
	case 5:showTheSections(); break;
	case 6:showTheDifference(); break;
	case 7:showTheSimetricDifference(); break;
	case 8:return false; break;
	default: {cout << "Incorrect input!!! Try again!\n\n"; return false;
		break; }
	}
	return true;
}

bool showMenu() {
	

	int userInput;

	border();

	cout << "\n\n\t\t\t\t\t\t  Main Menu:\n";
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