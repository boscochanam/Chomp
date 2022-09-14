#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class User
{
    string name;
    string address;
    string city;
    string phone_no;

public:

    void new_user_read()
    {
        cout << "Enter Your First Name : " << endl;
        getline(cin, name);

        cout << "Enter Your Phone Number: " << endl;
        getline(cin, phone_no);

        cout << "Enter your address: " << endl;
        getline(cin, address);

        cout << "Welcome, " << name << "." << endl;
    }
};
