#include "Presentation.h"
#include "Data.h"
#include <string>

void greetings() {
	cout << "\t\t\t\t\t\tHello User,\n";
	cout << "\n\t\tWelcome to the <program_name> ! ! !\n\n";
	cout << "\t   We are thankful that you use our program\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tHave fun!\n\n";
}

bool showMenu() {
	int userInput;
	for (int i = 0; i < 120; i++) {
		cout << char(177);
	}
	
	cout << endl;
	cout << "\t1. Enter a set of numbers" << endl;
	cout << "\t2. Show the sets" << endl;
	cout << "\t3. Show the subset"<< endl;
	cout << "\t4. Show the union" << endl;
	cout << "\t5. Show the section" << endl;
	cout << "\t6. Show the difference" << endl;
	cout << "\t7. Exit" << endl;

	for (int i = 0; i < 120; i++) {
		cout << char(177);
	}
	cout << "Enter your choice by pressing a number and press ENTER!!!\n";
	cin >> userInput;
	switch (userInput)
	{
	case 1:break;
	case 2:break;
	case 3:break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:break;
	default:cout << "Incorrect input!!! Please try again!\n"; return false;
		break;
	}
	return true;
	
}