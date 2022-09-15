#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Item
{
	protected:
		string name;
		float price;
		int stock;

	public:
		Item()
		{
			name = "unknown";
			price = 0;
			stock = 0;
		}

		Item(string n, float p, int st)
		{
			name = n;
			price = p;
			stock = st;
		}

		void info()
		{
			cout << "Item: " << name << endl;
			cout << "Price: $" << price << endl;
			cout << "Stock: " << stock << endl;
		}
};

class Food : private Item
{
	public:

		Food()
		{
			name = "";
			price = 0.0;
			stock = 0;
		}

		Food(string n, float p, int st)
		{
			name = n;
			price = p;
			stock = st;
		}

		void info()
		{
			cout << "Item: " << name << endl;
			cout << "Price: $" << price << endl;
			cout << "Stock: " << stock << endl;
		}
};

class Drink : private Item
{
	int volume;

	public:

		Drink(string n, float p, int st)
		{
			name = n;
			price = p;
			stock = st;
		}

		void info()
		{
			cout << "Item: " << name << endl;
			cout << "Price: $" << price << endl;
			cout << "Stock: " << stock << endl;
		}
};
