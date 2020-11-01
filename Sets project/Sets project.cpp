#include <iostream>
#include <string>
#include <vector>
#include<Windows.h>
#include "Data.h"
#include "Presentation.h"
using namespace std;

int main()
{
	system("chcp 437");
	/*backup();*/
	system("cls");
	system("color 0b");
	greetings();
	while (showMenu());
	goodbyeMessage();
	
}