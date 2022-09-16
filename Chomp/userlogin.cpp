#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "userclass.cpp"

using namespace std;

static vector<UserData> UserList;
static vector<vector<string>> data2;

static void read_login()
{
	vector<vector<string>> data;									// Creates an array for data
	vector<string> row;												// Internal row for array
	string line, word;												// Stores line and data points temporaril
	fstream file("userdata.csv", ios::in);							// Reads menudata.csv into fstream

	if (file.is_open())												// Checks if file is open, else returns error message
	{
		while (getline(file, line))									// Looping through all the lines in file
		{
			row.clear();											// Erases the contents of row

			stringstream str(line);                                 // Allows us to read from line into str as if it were like cin

			while (getline(str, word, ','))                         // Separates data using comma separation
				row.push_back(word);								// Adds a new element "word" to the end of vector row
			data.push_back(row);									// Adds a new element "row" to the end of vector data
		}
	}
	else
		cout << "Error: File cannot be opened.\n";

	for (int i = 0; i < data.size(); i++)
	{
		UserData newuser(data[i][0], data[i][1]);
		UserList.push_back(newuser);

		cout << "\n";
	}

	data2 = data;
}

static void user_data()
{
	UserList[0].details();
	UserList[1].details();
}

static int login_check()
{
	string name;
	cout << "Please enter your username: " << endl;
	cin >> name;
	string password;
	cout << "Please enter your password: " << endl;
	cin >> password;
	
	int flag = 0;;
	for (int i = 0; i < data2.size(); i++)
	{
		if (name == data2[i][0] and password == data2[i][1])
			flag = 1;
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}