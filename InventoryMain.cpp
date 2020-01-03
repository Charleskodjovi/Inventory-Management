#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "Inventory.h"
#include "Inventory.cpp"

using namespace std;

//****************************************************************************************************

void getInventoryItem(Inventory &);
void showInventoryItem(Inventory);
void showInventory( Inventory[], int);
void editInventoryItem(Inventory &);
void displayMenu();
Inventory * addNewItem(Inventory *, int &);
Inventory * myStoreInventory(Inventory *, int &, int &);
void displayItems( Inventory[], int);
int getChoice(int, int);
int chooseItem(int, int);

//****************************************************************************************************

int main()
{
    int MaxNumber = 20;
    int maxItems = 0, 
    choice, inv;
    
    cout << endl;
    cout << "*** Corporate Inventory Managment Systems *** \n\n";
    cout << "Please enter the number of Items in the inventory: ";
    cin >> MaxNumber;

    while (MaxNumber <= 0)
    {
        cout << "Please enter the number of Items in the inventory: ";
        cin >> MaxNumber;
    }

    Inventory * item = new Inventory[MaxNumber];
    item  = myStoreInventory(item, MaxNumber, maxItems);
    
    do
    {
        displayMenu();
        choice = getChoice(1,5);
        switch (choice)
        {
            case 1:
                if (maxItems >= MaxNumber)
                {
                    cout << "You have reached the maximum number of inventory items.\n";
                    break;
                }

                getInventoryItem(item[maxItems]);
                cout << "You have entered information for inventory item ";

                cout << "number " << maxItems + 1 << endl;
                maxItems++;
                break;

                case 2:
                displayItems(item, maxItems);
                inv = chooseItem(1,maxItems);
                editInventoryItem(item[inv]);
                break;

                case 3:
                displayItems(item, maxItems);
                inv = chooseItem(1,maxItems);
                showInventoryItem(item[inv]);
                break;

                case 4:
                cin.get();
                showInventory(item, maxItems);

        }
    } while (choice != 5);

    delete [] item;
    item = nullptr;     

    return 0;           
}           

//****************************************************************************************************

Inventory * addNewItem(Inventory *inv, int & maxNum)
{
    Inventory *tempInv = new Inventory[maxNum+10];
    
    for(int i = 0; i < maxNum; i++)
    {
        tempInv[i].setItemName(inv[i].getItemName());
        tempInv[i].setItemNumber(inv[i].getItemNumber());
        tempInv[i].setQuantity(inv[i].getQuantity());
        tempInv[i].setCost(inv[i].getCost());
    }

    delete [] inv;
    inv = 0;
    maxNum+=10;
    return tempInv;
}

//****************************************************************************************************

Inventory * myStoreInventory(Inventory *inv, int & maxNum, int & maxItem)
{
    string name;
    int number;
    int quan;
    double price;
    ifstream fileName;
    int size = 0;
    fileName.open("inventory.txt");

    if (!fileName)
    {
        cout << "Inventory File not found\n";
        return NULL;
    }

    while (!fileName.eof())
    {
        fileName >> name >> number >> quan >> price;
        inv[size].setItemName(name);
        inv[size].setItemNumber(number);
        inv[size].setQuantity(quan);
        inv[size].setCost(price);
        size++;
        if (size >= maxNum)
        {
               inv = addNewItem(inv, maxNum);
        } 
    }      
    maxItem = size;
    return inv;
}

//****************************************************************************************************

void getInventoryItem(Inventory &inv)
{
      string name;
      int num, quan;
      float cost;
      cin.ignore();                 // skip the \n left by the last cin
      cout << "\nPlease enter information for every field requested.\n";

      cout << "Item Name: ";
      getline(cin, name);
      inv.setItemName(name);

      cout << "Item Number: ";
      cin >> num;
      inv.setItemNumber(num);

      cout << "Item Quantity: ";
      cin >> quan;
      inv.setQuantity(quan);

      cout << "Item Cost: ";
      cin >> cost;
      inv.setCost(cost);
}

//****************************************************************************************************

void editInventoryItem(Inventory & inv)
{ 
    int choice;
    string name;
    int num, quan;
    float cost;

    do
    {
        // Call showInventoryItem function to display the current record
        cout << fixed << showpoint << setprecision(2);
        cout << "1. Item name  : " << inv.getItemName() << endl;
        cout << "2. Item number: " << inv.getItemNumber() << endl;
        cout << "3. Quantity   : " << inv.getQuantity() << endl;
        cout << "4. Cost       : " << inv.getCost() << endl;
        cout << "5. Exit." << endl;
        cout << "\nEnter the number of the field you wish to update: ";

        choice = getChoice(1,5);

        //Accept a new value for the field the user selectedswitch (choice)
        switch (choice)
        {
                case 1:
                    cout << "Item Name:   " << inv.getItemName() << endl;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    inv.setItemName(name);
                    break;

                case 2:
                    cout << "Item Number: " << inv.getItemNumber() << endl;
                    cout << "Enter new Item Number: ";
                    cin >> num;
                    inv.setItemNumber(num);
                    break;

                case 3:
                    cout << "Item Quantity: " << inv.getQuantity() << endl;
                    cout << "Enter new Item Quantity: ";
                    cin >> quan;
                    inv.setQuantity(quan);
                    break;

                case 4:      
                    cout << "Item Cost: " << inv.getCost() << endl;
                    cout << "Enter new Item Cost: ";
                    cin >> cost;
                    inv.setCost(cost);
                    break;

        }showInventoryItem(inv);

    } while (choice != 5);  
}

//****************************************************************************************************

void showInventoryItem(Inventory inv)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "\nInventory Display...\n";
    cout << "Item name  : " << inv.getItemName() << endl;
    cout << "Item number: " << inv.getItemNumber() << endl;
    cout << "Quantity   : " << inv.getQuantity() << endl;
    cout << "Cost       : " << inv.getCost() << endl;
    cout << "Total Cost : " << inv.getTotalCost() << endl << endl;
}

//****************************************************************************************************

void showInventory( Inventory *inv, int size)
{
    double inventoryCost = 0.0;
    cout << fixed << showpoint << setprecision(2);
    cout << "\nInventory Display...\n";
         for(int i = 0; i<size; i++)
         {
              cout << "\nInventory item " << i+1 << " ...\n";
              cout << "Item name  :  " << (inv+i) ->getItemName() << endl;
              cout << "Item number:  " << (inv+i) ->getItemNumber() << endl;
              cout << "Quantity   :  " << (inv+i) ->getQuantity() << endl;
              cout << "Cost       : $" << (inv+i) ->getCost() << endl;
              cout << "Total Cost : $" << (inv+i) ->getTotalCost() << endl << endl;
              inventoryCost += (inv+i) ->getTotalCost();
         }
    cout << endl;
    cout << "|  Total Cost of the Store Inventory: $ " << left << setw(10) << inventoryCost << "|";
    cout << "\n+------------------------------------------------+\n\n";
}

//****************************************************************************************************

void displayMenu()
{
    cout << "1. Add new inventory item\n";
    cout << "2. Change inventory information\n";
    cout << "3. Display an inventory item\n";
    cout << "4. Display all inventory items\n";
    cout << "5. Exit the program\n\n";
    cout << "Enter your choice: ";
}

//****************************************************************************************************

void displayItems( Inventory inv[], int size)
{
    cout << "\nInventory Items\n";
    for(int i = 0; i<size; i++)
    { 
        cout << i+1 << " " << inv[i].getItemName() << endl;
    }
    cout << "Enter your choice: ";
}

//****************************************************************************************************

int getChoice(int lower, int upper)
{
    int ch;
    cin >> ch;
    // Validate the menu choice.
    while (ch < lower || ch > upper)
    {
     cout << "Please Enter a number between " << lower << " and " << upper << endl;
     cin >> ch;
    }
  return ch;
}

//****************************************************************************************************

int chooseItem(int lower, int upper)
{
   int inv;
   cout << "Inventory item number(" << lower << "-"<< upper << "): ";
   cin >> inv;

   // Validate input
   while (inv < lower || inv > upper)
   {
       cout << "Invalid inventory item Number.\nPlease Re-enter a correct item number(" 
       << lower << "-"<< upper << "): ";
       cin >> inv;
   }

   cin.ignore();
   return (inv-1);
}

//****************************************************************************************************

