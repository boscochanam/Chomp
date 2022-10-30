#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

static struct MenuData
{
public:
    MenuData
    (
        string type,
        string name,
        string quantity,
        string price
    )

    {
        t = type;
        n = name;
        qt = quantity;
        p = price;
    }

    void display()
    {
        cout << "Type: " << t << endl;
        cout << "Name: " << n << endl;
        cout << "Quanity: " << qt << endl;
        cout << "Price:  $" << p << endl;
        cout << endl;
    }

    string t;
    string n;
    string qt;
    string p;

};

static vector<UserData> menu;

static void menuInfo(int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        menu[i].display();
    }
}

static void readMenuData()
{
    ifstream inputFile;
    inputFile.open("menudata.csv");
    string line = "";
    int count = 0;

    while (getline(inputFile, line)) {

        stringstream inputString(line);

        string t;
        string n;
        string qt;
        string p;

        getline(inputString, t, ',');
        getline(inputString, n, ',');
        getline(inputString, qt, ',');
        getline(inputString, p, ',');

        MenuData m(t, n, qt, p);
        users.push_back(m);
        line = "";
        count++;
    }

    //userInfo(count);

}
