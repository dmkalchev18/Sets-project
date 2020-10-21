#include "Presentation.h"
#include "Data.h"
#include <string>
void showMenu() {
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
}