#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Item
{
    static int count;
    
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

    virtual void info()
    {
        cout << "Item: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << endl;
    }

    float priceret()
    {
        return price;
    }

    string namereturn()
    {
        return name;
    }

    int stockcheck()
    {
        if (stock > 0)
        {
            stock--;
            return 1;
        }
        else
        {
            cout << "No more stock!" << endl;
            return 0;
        }
    }

};

class Food : public Item
{

private:
    int weight;

public:

    

    Food()
    {
        name = "";
        price = 0.0;
        stock = 0;
        weight = 0;
    }

    Food(string n, float p, int st, int wt)
    {
        name = n;
        price = p;
        stock = st;
        weight = wt;
    }

    void fillinf(string n, float p, int st, int wt)
    {
        name = n;
        price = p;
        stock = st;
        weight = wt;
    }

    virtual void info() const
    {
        cout << endl;
        cout << "Item: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "Weight: " << weight << endl;
    }
};

class Drink : public Item
{
private:
    int volume;

public:

    

    Drink()
    {
        name = "";
        price = 0.0;
        stock = 0;
        volume = 0;
    }

    Drink(string n, float p, int st, int vol)
    {
        name = n;
        price = p;
        stock = st;
        volume = vol;
    }

    void fillinf(string n, float p, int st, int v)
    {
        name = n;
        price = p;
        stock = st;
        volume = v;
    }

    virtual void info() const
    {
        cout << endl;
        cout << "Item: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "Volume: " << volume << endl;
    }
};