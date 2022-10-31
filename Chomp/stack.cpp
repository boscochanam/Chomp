#include <iostream>
#include <string>

#define MAX 100

using namespace std;

static struct Stack
{
	string stck[MAX];
	float prices[MAX];
	int top;
}cart;


static void push(string item, float price)
{
	cout << "Added: " << item << " to Cart! ($" << price << ") " << endl;
	cart.top++;
	cart.stck[cart.top] = item;
	cart.prices[cart.top] = price;
}

static int isEmpty()
{
	if (cart.top == -1)
	{
		cout << "Empty Cart!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

static void pop()
{
	if (isEmpty() == 0)
	{
		cout << "Removed: " << cart.stck[cart.top] << " from Cart!" << endl;
		cart.top--;
	}
	else
	{
		cout << "Stack Underflow!" << endl;
	}
}

static void show()
{
	
	cout << endl << endl;
	cout << endl << "Your Cart: " << endl;
	for (int i = 0; i < cart.top + 1; i++)
	{
		cout << "Item " << i + 1;
		cout << " " << cart.stck[i] << "  |  $" << cart.prices[i] << endl;
	}
	
	cout << endl;
}

static float total()
{
	float tot = 0;
	for (int i = 0; i < cart.top + 1; i++)
	{
		tot += cart.prices[i];
	}

	return tot;
}
