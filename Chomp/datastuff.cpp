#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "menu.cpp"
using namespace std;


static void read_csv()
{
	vector<vector<string>> data;									// Creates an array for data
	vector<string> row;												// Internal row for array
	string line, word;												// Stores line and data points temporaril
	fstream file("menudata.csv", ios::in);							// Reads menudata.csv into fstream

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

	// Placing values into objects

	string food = "Food";
	
	vector<Food> food_items;
	vector<Drink> drink_items;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i][0] == food)
		{
			Food fooditem(data[i][1], stof(data[i][2]), stod(data[i][3]));
			food_items.push_back(fooditem);
		}
		else
		{
			Drink drinkitem(data[i][1], stof(data[i][2]), stod(data[i][3]));
			drink_items.push_back(drinkitem);
		}
		
		cout << "\n";
	}


}
