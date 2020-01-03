#include <iostream>
#include "Inventory.h"
using namespace std;

//****************************************************************************************************

Inventory::Inventory()
{
    setItemName(" ");
    setItemNumber(0);
    setQuantity(0);
    setCost(0);
}

//****************************************************************************************************

Inventory::Inventory(string nm, int in, int q, double c)
{
    setItemName(nm);
    setItemNumber(in);
    setQuantity(q);
    setCost(c);    
}

//****************************************************************************************************

void Inventory::setItemName(string nm)
{
    while (!validStr(nm))
    {
        cout << "Item Name must contain at least one character. Please re-enter: ";
        getline(cin, nm);
    }
    itemName = nm;
}

//****************************************************************************************************

void Inventory::setItemNumber(int in)
{
    while (!validInt(in))
    {
        cout << "Item Number must be positive. Please re-enter: ";
        cin  >> in;
    }
        itemNumber = in;
}

//****************************************************************************************************

void Inventory::setQuantity(int q)
{
    while (!validInt(q))
    { 
        cout << "Quantity must be positive. Please re-enter: ";
        cin  >> q;
    }
        quantity = q;
}

//****************************************************************************************************

void Inventory::setCost(double c)
{
    while (!validDouble(c))
    {
        cout << "Cost must be positive. Please re-enter: ";
        cin  >> c;
    }
    cost = c;
}

//****************************************************************************************************

bool Inventory::validStr(string value)
{
    if (value.length() == 0)
    {   
        return false;
    }
    else
    {             
        return true;
    }
}

//****************************************************************************************************

bool Inventory::validInt(int value)
{
    if (value < 0) 
    {   
        return false;
    }
    else    
    {
        return true;
    }
}

//****************************************************************************************************

bool Inventory::validDouble(double value)
{
    if (value < 0)
    {
        return false;
    }
    else  
    {            
        return true;
    }
}

//****************************************************************************************************