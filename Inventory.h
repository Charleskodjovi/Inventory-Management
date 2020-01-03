#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
using namespace std;

//****************************************************************************************************

class Inventory
{
    private:
         string itemName;
         int itemNumber;
         int quantity;
         double cost;

    public:
    
    Inventory();
    Inventory(string, int, int, double);     
    void setItemName(string);
    void setItemNumber(int);
    void setQuantity(int);
    void setCost(double);
    string getItemName(){ return itemName; }
    int getItemNumber() { return itemNumber; }
    int getQuantity(){ return quantity; }
    double getCost(){ return cost; }
    double getTotalCost(){ return (cost * quantity); }

    // Input validation functions
    bool validStr(string);
    bool validInt(int);
    bool validDouble(double);
    
};
    
#endif

//****************************************************************************************************