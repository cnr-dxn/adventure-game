#ifndef USER_H
#define USER_H

#include "Item.h"  
#include "Room.h"  
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class User 
{
	public:
	User();
	User(string, int);
	
	void setName(string);
	void setLocation(int);
	void setItem(Item);

	string getName();
	int getLocation();
	int getItemID();
        string getItemName();
        int getIfItemIsNeeded();	

	private:
	Item item;
	string name;
	int location;
};

#endif
