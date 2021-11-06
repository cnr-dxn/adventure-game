#include "Item.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


Item::Item()
{
	itemID = 0;
	nameOfItem = "";
	ifItemIsNeeded = 0;
}

Item::Item(int itemID_, string nameOfItem_, int ifItemIsNeeded_)
{
	itemID = itemID_;	
	nameOfItem = nameOfItem_;
	ifItemIsNeeded = ifItemIsNeeded_;
}

void Item::setItemID(int itemID_)
{
	itemID = itemID_;
}

void Item::setNameOfItem(string nameOfItem_)
{
        nameOfItem = nameOfItem_;
}

void Item::setIfItemIsNeeded(int ifItemIsNeeded_)
{
        ifItemIsNeeded = ifItemIsNeeded_;
}

int Item::getItemID()
{
	return itemID;
}

string Item::getNameOfItem()
{
	return nameOfItem;
}

int Item::getIfItemIsNeeded()
{
	return ifItemIsNeeded;
}






















 
