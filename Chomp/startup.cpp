#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastuff.cpp"
#include "login.cpp"
#include "userlogin.cpp"
using namespace std;

int main()
{
	printf("|=======================================================================|\n|\t\t\t\t\t\t\t\t\t|\n|\t\t\tChomp Food Delivery Portal\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n|=======================================================================|\n");
	
	cout << "\n|========================================================|\n|\t\t\t\t\t\t\t |\n|\t\t\tMenu\t\t\t\t |\n|\t\t\t\t\t\t\t |\n|========================================================|\n";
	
	//User user1;
	//user1.new_user_read();
	
	//Food Cheese("Cheese", 300, 5);
	//Cheese.info();

	//Drink Pepsi("Pepsi", 300, 5);
	//Pepsi.info();
	//Pepsi.info();

	//read_csv();
	//show_data();

	readUserData();

	string username;
	string password;
	int verification = 0;

	while (verification == 0)
	{
		cout << "Enter Username: " << endl;
		cin >> username;

		cout << "Enter Password: " << endl;
		cin >> password;

		verification = loginVerification(3, username, password);
		cout << endl;
	}
	

	return 0;
}