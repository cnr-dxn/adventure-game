#ifndef ROOM_H 
#define ROOM_H

#include "Door.h" 
#include "User.h" 
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

class Room
{
        public:
        Room();
        Room(bool, bool, int, int, int, int, int, int);

        // void setItemAt(int, Item);
        void setIfVisited(bool);
	void setIfSolved(bool);
	void setXLocation(int);
	void setYLocation(int);
	void setWestDoor(int);
	void setEastDoor(int);
	void setNorthDoor(int);
	void setSouthDoor(int);
     	
	int getItemID();
        bool getIfVisited();
	bool getIfSolved();
	int getXLocation();
	int getYLocation();
	int getWestDoor();
	int getEastDoor();
	int getNorthDoor();
	int getSouthDoor();

        private:
        Item items[2];
	bool ifVisited;
	bool ifSolved;
	int xLocation;
	int yLocation;
	int westDoor;
	int eastDoor;
	int northDoor;
	int southDoor;
	int split(string, char, string*, int);
};

#endif
