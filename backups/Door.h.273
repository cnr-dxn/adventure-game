#ifndef DOOR_H 
#define DOOR_H

#include "Room.h"
#include "Item.h"
#include "User.h"
#include <iostream>
#include <vector> 
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Door
{
	public:
	Door();
	Door(int, int, int, int, int);
	
	void setOrientation(int);
	void setWestRoom(int);
	void setEastRoom(int);
	void setNorthRoom(int);
	void setSouthRoom(int);
	
	int getOrientation();
	int getWestRoom();
	int getEastRoom();
	int getNorthRoom();
	int getSouthRoom();

	private:
	int orientation;
	int westRoom;
	int eastRoom;
	int northRoom;	
	int southRoom;	
};


#endif
