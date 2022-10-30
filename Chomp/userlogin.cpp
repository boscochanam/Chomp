#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

static struct UserData
{
public:
    UserData
    (
        string username,
        string password,
        string balance
    )

    {
        un = username;
        pw = password;
        bal = balance;
    }

    void display()
    {
        cout << "Username: " << un << endl;
        cout << "Password: " << pw << endl;
        cout << "Balance:  $" << bal << endl;
        cout << endl;
    }

    string un;
    string pw;
    string bal;

};

static vector<UserData> users;

static void userInfo(int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        users[i].display();
    }
}




static void readUserData()
{
    ifstream inputFile;
    inputFile.open("userdata.csv");
    string line = "";
    int count = 0;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        string username;
        string password;
        string balance;

        getline(inputString, username, ',');
        getline(inputString, password, ',');
        getline(inputString, balance, ',');

        UserData u(username, password, balance);
        users.push_back(u);
        line = "";
        count++;
    }

    userInfo(count);

}