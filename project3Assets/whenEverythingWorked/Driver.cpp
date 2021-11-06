#include "User.h"
#include "User.cpp"
#include "Room.h"
#include "Room.cpp"
#include "Item.h"
#include "Item.cpp"
#include "Door.h"
#include "Door.cpp"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	User user1("Parker", 0, 4);
	cout << "Example User: " << endl;
	cout << "Name should be 'Parker': " << user1.getName() << endl;
	cout << "Location should be 0: " << user1.getLocation() << endl;
	cout << "ItemID should be 4: " << user1.getItemID() << endl;
	
	cout << endl;
	
	Room room1(4, false, false, 0, 0, 0, 1, 2, 3);
	cout << "Example Room: " << endl;
	cout << "ItemID should be 4: " << room1.getItemID() << endl;
	cout << "IfVisited should be 0/false: " << room1.getIfVisited() << endl;
	cout << "IfSolved should be 0/false: " << room1.getIfSolved() << endl;
	cout << "X-Location should be 0: " << room1.getXLocation() << endl;
	cout << "Y-Location should be 0: " << room1.getYLocation() << endl;
	cout << "West Door should be 0: " << room1.getWestDoor() << endl;
	cout << "East Door should be 1: " << room1.getEastDoor() << endl;
	cout << "North Door should be 2: " << room1.getNorthDoor() << endl;
	cout << "South Door should be 3: " << room1.getSouthDoor() << endl;
	
	cout << endl;

	Item item1("24 foot gravity bong", false, false);
	cout << "Example item: " << endl;
	cout << "Name should be '24 foot gravity bong': " << item1.getNameOfItem() << endl;
	cout << "If item is held should be false: " << item1.getIfItemIsHeld() << endl;
	cout << "If item is needed should be false: " << item1.getIfItemIsHeld() << endl;

	cout << endl;

	// Door door1(1, 0, 
	return 0;
}
