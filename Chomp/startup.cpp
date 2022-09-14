#include <iostream>
#include <stdio.h>

#include "menu.cpp"
#include "login.cpp"
using namespace std;

int main()
{
	printf("|=======================================================================|\n|\t\t\t\t\t\t\t\t\t|\n|\t\t\tChomp Food Delivery Portal\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n|=======================================================================|\n");
	
	cout << "\n|========================================================|\n|\t\t\t\t\t\t\t |\n|\t\t\tMenu\t\t\t\t |\n|\t\t\t\t\t\t\t |\n|========================================================|\n";
	
	User user1;
	user1.new_user_read();
	
	Food Cheese("Cheese", 300, 5);
	Cheese.info();

	Drink Pepsi("Pepsi", 300, 5);
	Pepsi.info();

	return 0;
}