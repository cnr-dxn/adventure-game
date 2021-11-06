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

string lookAround(User user, Room rooms[], Door doors[], Item item)
{
	return "You called the look around function";
}

void moveAround(User &user, Room rooms[], Door doors[], Item item)
{
	int choice;
	cout << "Which direction would you like to go? " << endl;
	cout << "1. North" << endl;
	cout << "2. South" << endl;
	cout << "3. West" << endl;
	cout << "4. East" << endl;
	cin >> choice;
	
	if (choice < 1 || choice > 4)
	{
		cout << "Invalid option. Please choose one of the provided options." << endl;
	}

	else if (choice == 1)
	{
		if (rooms[user.getLocation()].getNorthDoor() == -1)  
		{
			cout << "That's a wall, you can't go there." << endl;
		}

		else
		{
			cout << "Moving from room: " << user.getLocation() << endl;;
			user.setLocation(doors[rooms[user.getLocation()].getNorthDoor()].getNorthRoom());
			cout << "Moved to room: " << user.getLocation() << endl;
		}
	}
	
	else if (choice == 2)
	{
		if (rooms[user.getLocation()].getSouthDoor() == -1)  
		{
			cout << "That's a wall, you can't go there." << endl;
		}

		else
		{
			cout << "Moving from room: " << user.getLocation() << endl;
			user.setLocation(doors[rooms[user.getLocation()].getSouthDoor()].getSouthRoom());
			cout << "Moved to room: " << user.getLocation()<< endl;
		}
	}
	
	else if (choice == 3)
	{
		if (rooms[user.getLocation()].getWestDoor() == -1)  
		{
			cout << "That's a wall, you can't go there." << endl;
		}

		else
		{
			cout << "Moving from room: " << user.getLocation() << endl;
			user.setLocation(doors[rooms[user.getLocation()].getWestDoor()].getWestRoom());
			cout << "Moved to room: " << user.getLocation() << endl;
		}
	}
	
	else
	{
		if (rooms[user.getLocation()].getEastDoor() == -1)  
		{
			cout << "That's a wall, you can't go there." << endl;
		}

		else
		{
			cout << "Moving from room: " << user.getLocation() << endl;
			user.setLocation(doors[rooms[user.getLocation()].getEastDoor()].getEastRoom());
			cout << "Moved to room: " << user.getLocation() << endl;
		}
	}
}

string exchangeItem(User user, Room rooms[], Door doors[], Item item)
{
	return "You called the exchange item function";
}

void decisionFunction(User &user, Room rooms[], Door doors[], Item &item)
{
	int choice = 0;
	cout << "What would you like to do, " << user.getName() << "?" << endl;
	cout << "1. Look around the room." << endl; 
	cout << "2. Move to a different room." << endl; 
	cout << "3. Exchange item." << endl; 
	cout << "4. Quit." << endl;
	cin >> choice;
	
	while (choice < 1 || choice > 4) 
	{
		cout << "Invalid choice. Please enter one of the provided options." << endl;
		cin >> choice;
	}

	if (choice == 1)
	{
		cout << "Calling the look around function." << endl;
		cout << lookAround(user, rooms, doors, item) << endl;
	}

	else if (choice == 2)
	{
		cout << "Calling the move around function." << endl;
		moveAround(user, rooms, doors, item);
	}

	else if (choice == 3)
	{
		cout << "Calling the exchange item function." << endl;
		cout << exchangeItem(user, rooms, doors, item) << endl;
	}

	else
	{
		exit(0);
	}
}

int main()
{
// Creating conceptual map******************************************************************************************
	
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
			rooms[currentRoom].setNorthDoor(-1);
			rooms[currentRoom].setSouthDoor(-1);
			rooms[currentRoom].setWestDoor(-1);
			rooms[currentRoom].setEastDoor(-1);
			cout << "room: " << currentRoom << ", x-location: " << x << ", y-location: " << y << endl;
	
			if (x < X_ROOMS - 1)
			{
				// make an east door
				doors[currentDoor].setOrientation(EW);
				doors[currentDoor].setWestRoom(currentRoom);
				doors[currentDoor].setEastRoom(currentRoom + 1);
				rooms[currentRoom].setEastDoor(currentDoor);
				rooms[currentRoom+1].setWestDoor(currentDoor);
				cout << "door: " << currentDoor << ", direction: EW, west room: " << doors[currentDoor].getWestRoom() << ", east room: " << doors[currentDoor].getEastRoom() << endl;
				currentDoor++;
			}

			
			if (y < Y_ROOMS - 1)
			{
				// make an east door
				doors[currentDoor].setOrientation(NS);
				doors[currentDoor].setNorthRoom(currentRoom + X_ROOMS);
				doors[currentDoor].setSouthRoom(currentRoom);
				rooms[currentRoom].setNorthDoor(currentDoor);
				rooms[currentRoom+ X_ROOMS].setSouthDoor(currentDoor);
				cout << "door: " << currentDoor << ", direction: NS, north room: " << doors[currentDoor].getNorthRoom() << ", south room: " << doors[currentDoor].getSouthRoom() << endl;
				currentDoor++;
			}

			cout << endl;
			currentRoom++;
		} 
	}
	cout << endl;
	cout << "******************************************************************************************" << endl;

//******************************************************************************************************************
// Initialize the moving of rooms

	User user;
	string name;
	Item item;
	int option;
	cout << "Please enter a name: " << endl;
	cin >> name;
	user.setName(name);
	user.setLocation(0);
	while (1 > 0)
	{
		decisionFunction(user, rooms, doors, item);
	}
//******************************************************************************************************************	
	return 0;
}




























