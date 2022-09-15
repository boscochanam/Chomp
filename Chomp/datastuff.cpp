#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

static void read_csv()
{

	vector<vector<string>> data;									// Creates an array for data
	vector<string> row;												// Internal row for array
	string line, word;												// Stores line and data points temporarily

	fstream file("menudata.csv", ios::in);							// Reads menudata.csv into fstream

	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			data.push_back(row);
		}
	}
	else
		cout << "Error: File cannot be opened.\n";

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << "\n";
	}
}