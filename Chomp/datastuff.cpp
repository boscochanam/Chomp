#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void read_csv()
		{
			fstream fin;
			fin.open("yum.csv",ios::in);
			
			vector<string> data;
			string line, word, temp;
			
			while (fin >> temp) 
			{
		        data.clear();			// read an entire row and
		        getline(fin, line);		// store it in a string variable 'line'
		        stringstream s(line); 	// used for breaking words
		        
		        
		        
	        while (getline(s, word, ', ')) 	// read every column data of a row and
	        							  	// store it in a string variable, 'word'
			{
								            // add all the column data
								            // of a row to a vector
	            data.push_back(word);
	        }
	        
	        
		}
