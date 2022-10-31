#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastuff.cpp"
#include "login.cpp"
#include "userlogin.cpp"
#include "menu.cpp"
#include "stack.cpp"
using namespace std;


void showmenu(Food f[],Drink d[])
{
	int i;
	for (i = 0; i < 7; i++)
	{
		f[i].info();
	}

	for (i = 0; i < 3; i++)
	{
		d[i].info();
	}
}

int main()
{
	string username;
	string password;
	string balance;

	printf("|=======================================================================|\n|\t\t\t\t\t\t\t\t\t|\n|\t\t\tChomp Food Ordering Portal\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n|=======================================================================|\n");
	
	cout << "\n|========================================================|\n|\t\t\t\t\t\t\t |\n|\t\t\tMenu\t\t\t\t |\n|\t\t\t\t\t\t\t |\n|========================================================|\n";

	// Reading Menu and User Databases
	readMenuData();			//menuInfo(2);
	readUserData();			//userInfo(3);

	
	// Reading Login Details from User
	cout << "Would you like to: " << endl << "1. Login" << endl << "2. Register" << endl; 
	int operation = 1;
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

				operation = loginVerification(username, password);
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
			int isunique = 0;
			cout << endl << "Registration Menu:" << endl;

			while (isunique == 0)
			{
				cout << "Enter New Username: " << endl;
				cin >> username;

				if (isUnique(username) == 1)
				{
					break;
				}

			}
			

			while (true)
			{
				cout << "Enter New Password: " << endl;
				cin >> password;;

				if (password.size() >= 6)
				{
					break;
				}
				else
				{
					cout << "Password too short!" << endl;
				}
			}


			
			

			cout << "Enter Your Balance: " << endl;
			cin >> balance;

			registration(username,password,balance);
			cout << "Registered Successfuly" << endl;

			break;
		}
	}
	
	// Transferring Food Data into Object Arrays
	Food f[7];
	Drink d[3];
	int i = 0;
	int j = 0;
	int comp = 0;

	for (int n = 0; n < 10; n++)
	{
		comp = menu[n].type();

		if (comp == 0)
		{
			f[i].fillinf(menu[n].name(), menu[n].price(), menu[n].quantity(), menu[n].attribute());
			i++;
		}

		else if (comp == 1)
		{
			d[j].fillinf(menu[n].name(), menu[n].price(), menu[n].quantity(), menu[n].attribute());
			j++;
		}
	}

	int ordering = 1;
	int option = 0;
	cart.top = -1;
	string addtocart;
	int incart = 0;
	float cartprice = 0;

	while (ordering == 1)
	{
		cout << "==========================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. See the Menu" << endl;
		cout << "2. Add item to cart" << endl;
		cout << "3. Remove item from cart" << endl;
		cout << "4. View Cart" << endl;
		cout << "5. Checkout" << endl;
		cout << "=========================" << endl;
		cin >> option;
		if (option == 1)
		{
			showmenu(f,d);
		}
		else if (option == 2)
		{
			incart = 0;
			cout << "What would you like to add?" << endl;
			cin >> addtocart;

			for (i = 0; i < 7; i++)
			{
				if (addtocart == f[i].namereturn())
				{
					incart = 1;
					cout << endl;
					if (f[i].stockcheck() == 1)
					{
						cartprice = f[i].priceret();
					}
					else
					{
						incart = 2;
					}
				}
			}

			for (i = 0; i < 3; i++)
			{
				if (addtocart == d[i].namereturn())
				{
					incart = 1;
					cout << endl;
					if (d[i].stockcheck() == 1)
					{
						cartprice = d[i].priceret();
					}
					else
					{
						incart = 2;
					}
				}
			}

			if (incart == 1)
			{	
				push(addtocart, cartprice);
			}
			else if (incart == 2)
			{
				cout << "Try again!" << endl;
			}
			else
			{
				cout << "Item does not exist! Try again!"<<endl;
			}
		}
		else if (option == 3)
		{
			pop();
		}
		else if (option == 4)
		{
			show();
			cout << endl << "Total :  $" << total() << endl;
		}
		else if (option == 5)
		{
			cout << "Your Order Details: " << endl;
			show();
			cout << "Total : " << total() << endl;

			cout << "Confirm Payment?"<<endl<<"1. Yes"<<endl<<"2. No"<<endl;
			int payment;
			cin >> payment;
			if (payment == 1 && userbalance >= total())
			{
				cout << "Payment Successful!" << endl;
				cout << "Remaining Balance = $" << userbalance - total() << endl;
				break;
			}
			else
			{
				cout << "Not enough balance!" << endl;
			}
		}
		else
		{
			cout << "Invalid Response";
		}
	}
	string phoneno = "";

	while (true)
	{
		cout << "Enter phone number: " << endl;
		cin >> phoneno;

		if (phoneno.size() == 10)
		{
			cout << "Phone number accepted!" << endl;
			break;
		}
		else
		{
			cout << "Invalid phone number!" << endl;
		}
	}

	return 0;
}