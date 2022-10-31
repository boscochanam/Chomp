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
        int type,
        string name,
        string price,
        string quantity,
        string attrib
    )

    {
        t = type;
        n = name;
        qt = quantity;
        p = price;
        at = attrib;
    }

    void display()
    {
        cout << "Type: " << t << endl;
        cout << "Name: " << n << endl;
        cout << "Quanity: " << qt << endl;
        cout << "Price:  $" << p << endl;
        cout << endl;
    }

    int t;
    string n;
    string qt;
    string p;
    string at;

    int type()
    {
        return t;
    }
    
    string name()
    {
        return n;
    }

    int quantity()
    {
        return stoi(qt);
    }

    float price()
    {
        return stof(p);
    }

    int attribute()
    {
        return stoi(at);
    }
};

static vector<MenuData> menu;

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
        string atr;

        getline(inputString, t, ',');
        getline(inputString, n, ',');
        getline(inputString, p, ',');
        getline(inputString, qt, ',');
        getline(inputString, atr, ',');

        MenuData m(stoi(t), n, p, qt, atr);
        menu.push_back(m);
        line = "";
        count++;
    }
    //userInfo(count);
}