#include "User.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

User::User()
{
	name = "";
	location = 0;
}

User::User(string name_, int location_)
{
	name = name_;
	location = location_;
	
}

void User::setName(string name_)
{
	name = name_;
}

void User::setLocation(int location_)
{
	location = location_;
}

void User::setItem(Item item_)
{
        item = item_;
}

string User::getName()
{
	return name;
}

int User::getLocation()
{
	return location;
}

int User::getItemID()
{
        return item.getItemID();
}

string User::getItemName()
{
        return item.getNameOfItem();
}

int User::getIfItemIsNeeded()
{
        return item.getIfItemIsNeeded();
}
