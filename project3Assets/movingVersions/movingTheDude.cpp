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

int parametersOfChoice(int option, bool top, bool bottom, bool left, bool right)
{
	if (top == false && bottom == false && left == false right == false)
	{
		while(option)
		{
			if (option < 1 || option > 4)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == true && bottom == false && left == false && right == false) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 1)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}
	
	else if (top == true && bottom == false && left == true && right == false) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 1 || option == 3)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == false && bottom == false && left == true && right == false) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 3)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	
	else if (top == false && bottom == true && left == true && right == false) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 2 || option == 3)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == false && bottom == true && left == false && right == false) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 2)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == false && bottom == true && left == false && right == true) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 2 || option == 4)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == false && bottom == false && left == false && right == true) 
	{
		while(option)
		{
			if (option < 1 || option > 4 || option == 4)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}

	else if (top == true && bottom == false && left == false && right == true) 
	{
		while(option)
		{
			if (option < 1 || option > 5 || option == 1 || option == 4)
			{
				cout << "Invalid input. Please enter one of the given choices."
				cin >> option;
			}
			
			else 
			{
				return option;
			}
		}
	}
}
void movingUser(User user1, Room Rooms[], Door Doors[])
{
	int choice;
	bool topRow = true;
	bool bottomRow = true;
	bool leftSide = true;
	bool rightSide = true;		

	cout << "Which direction would you like to move, " << name << "? You can move: " << endl;

	if (Rooms[user1.getLocation()].getYLocation() < Y_ROOMS - 1 ) 
	{
		cout << "1. North" << endl;
		topRow = false;
	}

	if (Rooms[user1.getLocation()].getYLocation() > 0 )
	{
		cout << "2. South" << endl;
		bottomRow = false;
	}
	
	if (Rooms[user1.getLocation()].getXLocation() > 0 )
	{
		cout << "3. West" << endl;
		leftSide = false;
	}
	 
	if (Rooms[user1.getLocation()].getYLocation() < X_ROOMS - 1 )
	{
		cout << "4. East" << endl;
		rightSide = false;
	}
	
	cin >> choice;
	
	choice = parametersOfChoice(choice, topRow, bottomRow, leftSide, rightSide);

		
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
	cout << endl;
	cout << "******************************************************************************************" << endl;

//******************************************************************************************************************
// Initialize the moving of rooms

	User user;
	string name;
	int option;
	cout << "Please enter a name: " << endl;
	cin >> name;
	user.setName(name);
	user.setLocation(0);
	while (1 > 0)
	{
	
	movingUser(user, rooms, doors);

//******************************************************************************************************************	
	return 0;
}




























