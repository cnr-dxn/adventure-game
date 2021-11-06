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
	nameOfItem = "";
	ifItemIsHeld = false;
	ifItemIsNeeded = false;
}

Item::Item(string nameOfItem_, bool ifItemIsHeld_, bool ifItemIsNeeded_)
{
	nameOfItem = nameOfItem_;
	ifItemIsHeld = ifItemIsHeld_;
	ifItemIsNeeded = ifItemIsNeeded_;
}

void Item::setNameOfItem(string nameOfItem_)
{
        nameOfItem = nameOfItem_;
}

void Item::setIfItemIsHeld(bool ifItemIsHeld_)
{
        ifItemIsHeld = ifItemIsHeld_; 
}

void Item::setIfItemIsNeeded(bool ifItemIsNeeded_)
{
        ifItemIsNeeded = ifItemIsNeeded_;
}

string Item::getNameOfItem()
{
	return nameOfItem;
}

bool Item::getIfItemIsHeld()
{
	return ifItemIsHeld;
}

bool Item::getIfItemIsNeeded()
{
	return ifItemIsNeeded;
}




















 
