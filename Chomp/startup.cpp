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
	string balance;

	cout << "Would you like to: " << endl << "1. Login" << endl << "2. Register" << endl;

	int operation = 0;

	cin >> operation;
	
	while (1==1)
	{
		if (operation == 1)
		{
			while (operation == 1)
			{
				cout << endl << "Login Menu:" << endl;

				cout << "type 'register' to go to registration" << endl;

				cout << "Enter Username: " << endl;
				cin >> username;

				if (username == "register")
				{
					operation = 2;
					continue;
				}

				cout << "Enter Password: " << endl;
				cin >> password;

				operation = loginVerification(3, username, password);
				operation;
				cout << endl;
			}
			if (operation != 2)
			{
				break;
			}
			
		}
		else if (operation == 2)
		{
			cout << endl << "Registration Menu:" << endl;
			cout << "Enter New Username: " << endl;
			cin >> username;

			cout << "Enter New Password: " << endl;
			cin >> password;

			cout << "Enter Your Balance: " << endl;
			cin >> balance;

			registration(username,password,balance);
			cout << "Registered Successfuly" << endl;

			break;
		}
	}
	
	


	return 0;
}