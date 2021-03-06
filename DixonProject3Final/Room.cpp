#include "Room.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

Room::Room()
{
	ifVisited = false;
	xLocation = 0;
	yLocation  = 0;
	westDoor = 0;
	eastDoor = 0;
	northDoor = 0;
	southDoor = 0;
}

Room::Room(bool ifVisited_, int xLocation_, int yLocation_, int westDoor_, int eastDoor_, int northDoor_, int southDoor_)
{
	ifVisited = ifVisited_;
	xLocation = xLocation_;
	yLocation = yLocation_;
	westDoor = westDoor_;
	eastDoor = eastDoor_;
	northDoor = northDoor_;
	southDoor = southDoor_;
}

// ****************************************************************************************************************


void Room::setItemAt(int index, Item item)
{
	items[index] = item;	 
}

void Room::setIfVisited(bool ifVisited_)
{
	ifVisited = ifVisited_;
}

void Room::setXLocation(int xLocation_)
{
	xLocation = xLocation_;
}

void Room::setYLocation(int yLocation_)
{
	yLocation = yLocation_;
}

void Room::setWestDoor(int westDoor_)
{
	westDoor = westDoor_;
}

void Room::setEastDoor(int eastDoor_)
{
	eastDoor = eastDoor_;
}

void Room::setNorthDoor(int northDoor_)
{
	northDoor = northDoor_;
}

void Room::setSouthDoor(int southDoor_)
{
	southDoor = southDoor_;
}

//************************************************************************************************************
int Room::getItemID(int index)
{
	return items[index].getItemID();
}

string Room::getItemName(int index)
{
	return items[index].getNameOfItem();
}

int Room::getIfItemIsNeeded(int index)
{
	return items[index].getIfItemIsNeeded();
}

bool Room::getIfVisited()
{
	return ifVisited;
}

int Room::getXLocation()
{
	return xLocation;	
}


int Room::getYLocation()
{
	return yLocation;
} 


int Room::getWestDoor()
{
	return westDoor;
} 


int Room::getEastDoor()
{
	return eastDoor;
} 


int Room::getNorthDoor()
{
	return northDoor;
} 


int Room::getSouthDoor()
{
	return southDoor;
} 












 
