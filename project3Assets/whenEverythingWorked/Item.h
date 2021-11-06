#ifndef ITEM_H
#define ITEM_H

#include "Door.h"
#include "User.h"
#include "Room.h"
#include <iostream>
#include <vector> 
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Item
{
        public:
      	Item();
        Item(string, bool, bool);

        void setNameOfItem(string);
        void setIfItemIsHeld(bool);
        void setIfItemIsNeeded(bool);

        string getNameOfItem();
        bool getIfItemIsHeld();
        bool getIfItemIsNeeded();

        private:
        string nameOfItem;
	bool ifItemIsHeld;
	bool ifItemIsNeeded;
};

#endif
