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

#define EW 0
#define NS 1
#define CLOSED 0
#define OPEN 1
#define OUTSIDE 999
#define X_ROOMS 3
#define Y_ROOMS 3
#define TOTAL_ROOMS 9
#define MAX_DOORS 81

using namespace std;

void createConceptMap(int choice)
{
	Room rooms[TOTAL_ROOMS];
	Door doors[MAX_DOORS];

	int currentRoom = 0;
	int currentDoor = 0;
	for (int y = 0; y < Y_ROOMS; y++)
	{
		for(int x = 0; x < X_ROOMS; x++)
		{
			rooms[currentRoom].setXLocation(x);
			rooms[currentRoom].setYLocation(y);
			cout << "room: " << currentRoom << ", x-location: " << x << ", y-location: " << y << endl;
	
			if (x < X_ROOMS - 1)
			{
				// make an east door
				doors[currentDoor].setOrientation(EW);
				doors[currentDoor].setWestRoom(currentRoom);
				doors[currentDoor].setEastRoom(currentRoom + 1);
				cout << "door: " << currentDoor << ", direction: EW, west room: " << doors[currentDoor].getWestRoom() << ", east room: " << doors[currentDoor].getEastRoom() << endl;
				currentDoor++;
			}

			
			if (y < Y_ROOMS - 1)
			{
				// make an east door
				doors[currentDoor].setOrientation(NS);
				doors[currentDoor].setNorthRoom(currentRoom);
				doors[currentDoor].setSouthRoom(currentRoom + X_ROOMS);
				cout << "door: " << currentDoor << ", direction: NS, north room: " << doors[currentDoor].getNorthRoom() << ", south room: " << doors[currentDoor].getSouthRoom() << endl;
				currentDoor++;
			}

			cout << endl;
			currentRoom++;
		} 
	}
}

int main()
{
	createConceptMap(3);
	return 0;
}
