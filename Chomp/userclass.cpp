#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class UserData
{
	protected:
		string username;
		string password;
		string balance;

	public:

		UserData()
		{
			username = "";
			password = "";
		}

		UserData(string u, string p, string b)
		{
			username = u;
			password = p;
			balance = b;
		}

		int login(string u, string p)
		{
			if (u == username and p == password)
			{
				cout << "Successfully logged in. " << endl;
				return 1;
			}
			else
			{
				cout << "Invalid username or password " << endl;
				return 0;
			}
		}

	void details()
	{
		cout << "Username: " << username << "  Password: " << password << endl;
	}

};
