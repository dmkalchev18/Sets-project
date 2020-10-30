#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
#include "Presentation.h"
using namespace std;

int main()
{
	backup();
	system("color 0b");
	greetings();
	while (showMenu());
	goodbyeMessage();
	
}

