#include <iostream>
using namespace std;

int startup()
{
	cout << "Welcome to chomp." << endl;
	cout << "Please enter your phone number" << endl;
	int phoneno = 0;
	cin >> phoneno;
	return phoneno;
}

int main()
{

	cout << startup() << endl;

	return 0;
}