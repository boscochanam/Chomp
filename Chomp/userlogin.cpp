#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

static int userbalance = 0;

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

    string username()
    {
        return un;
    }

    string password()
    {
        return pw;
    }

    string balance()
    {
        return bal;
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

static int loginVerification(int count, string username, string password)
{
    int flag = 0;
    for (int i = 0; i < count; i++)
    {
        if (username == users[i].username() && password == users[i].password())
        {
            flag = 1;
            cout << "Welcome " << users[i].username() << endl;
            cout << "Balance: $" << users[i].balance() << endl;
            userbalance = stoi(users[i].balance());
            return 0;
        }
        
    }
    if (flag == 0)
    {
        cout << "Invalid Credentials" << endl;
        return 1;
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

    //userInfo(count);

}

// Registration

static bool writeToFile(string file_name, string field_one, string field_two, string field_three);

static void registration(string username, string password, string balance)
{
    bool registeruser = writeToFile("userdata.csv", username, password, balance);

}

static bool writeToFile(string file_name, string field_one, string field_two, string field_three)
{
    ofstream file;
    file.open(file_name, ios_base::app); // If we don't include ios_base we will overwrite existing file
    file << field_one << "," << field_two << "," << field_three << endl;
    file.close();

    return true;
}

