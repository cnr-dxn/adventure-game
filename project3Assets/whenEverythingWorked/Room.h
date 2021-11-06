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
        Room(int, bool, bool, int, int, int, int, int, int);

        void setItemID(int);
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
        int itemID;
	bool ifVisited;
	bool ifSolved;
	int xLocation;
	int yLocation;
	int westDoor;
	int eastDoor;
	int northDoor;
	int southDoor;
};

#endif
