#ifndef ROOM_H 
#define ROOM_H

#include "Door.h" 
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
        Room(bool, int, int, int, int, int, int);

        // void setItemAt(int, Item);
	void setItemAt(int, Item);
        void setIfVisited(bool);
	void setXLocation(int);
	void setYLocation(int);
	void setWestDoor(int);
	void setEastDoor(int);
	void setNorthDoor(int);
	void setSouthDoor(int);
     	
	int getItemID(int);
	string getItemName(int);
	int getIfItemIsNeeded(int);
        bool getIfVisited();
	int getXLocation();
	int getYLocation();
	int getWestDoor();
	int getEastDoor();
	int getNorthDoor();
	int getSouthDoor();

        private:
        Item items[2];
	bool ifVisited;
	int xLocation;
	int yLocation;
	int westDoor;
	int eastDoor;
	int northDoor;
	int southDoor;
};

#endif
