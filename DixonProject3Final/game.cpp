#include "User.h"
#include "Room.h"
#include "Item.h"
#include "Door.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
 
#define EW 0
#define NS 1
#define X_ROOMS 3
#define Y_ROOMS 3
#define TOTAL_ROOMS 9
#define MAX_DOORS 99
#define X_DIMENSION 15 
#define Y_DIMENSION 15
#define ROOM_SIZE 5
#define DOOR_SIZE 3
#define EXIT_DOOR_INDEX -2

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
// Function for creating the map

/*
* Algorithm: print out the map with the user in the corresponding location
* Steps: 
	1. Define the 2D map array, the room's x origin and y origin
	2. Fill the array with spaces initially
	3. Enter a for loop that cycles through each room and establishes the 
	   proper dimensions
	   - Establish the origin to the current room by multiplying it's x & y 
	     values by the defined room size
	   - Enter first foor loop that establishes the northern & southern walls 
	     for the room
	   - Enter second for loop that establishes the eastern & western walls
	   - Establish the corner characters
	   - Establish the doors as spaces by inquiring if the doors exist 
	4. Place the user in the center of the room
	5. Print out the map
* Input parameters: The user object, the array of rooms, the array of doors 
* Output (prints to screen): The above statements 
* Returns: Nothing 
*/
    
void buildMap(User &user, Room rooms[], Door doors[])
{
	// 1. Define the 2D map array, the room's x origin and y origin:
	string mapArray[X_DIMENSION][Y_DIMENSION];
	int xOrigin = 0;
	int yOrigin = 0;

	for (int x = 0; x < X_DIMENSION; x++)
	// 2. Fill the array with spaces initially
	{
		for (int y = 0; y < Y_DIMENSION; y++)
		{
			mapArray[x][y] = "  ";
		}
	}

	for (int i = 0; i < TOTAL_ROOMS; i++)
	// 3. Enter a for loop that cycles through each room and establishes the 
	// proper dimensions
	{
	        // - Establish the origin to the current room by multiplying it's x & y 
	        //   values by the defined room size
		xOrigin = (rooms[i].getXLocation())*ROOM_SIZE;
		yOrigin = (rooms[i].getYLocation())*ROOM_SIZE;
		
		// make the northern & southern walls
		for (int j = 0; j < ROOM_SIZE; j++)
		{
			mapArray[xOrigin + j][yOrigin] = "--";		
			mapArray[xOrigin + j][yOrigin+ROOM_SIZE - 1] = "--";

			mapArray[xOrigin][yOrigin + j] = "|";
			mapArray[xOrigin + ROOM_SIZE - 1][yOrigin + j] = "|";
		}

	        // - Establish the corner characters:
          	mapArray[xOrigin][yOrigin] = "+";
          	mapArray[xOrigin + ROOM_SIZE - 1][yOrigin] = "+";
          	mapArray[xOrigin][yOrigin + ROOM_SIZE - 1] = "+";
          	mapArray[xOrigin + ROOM_SIZE - 1][yOrigin + ROOM_SIZE - 1] = "+";

		if (rooms[i].getSouthDoor() >= 0)
	        // - Establish the doors as spaces by inquiring if the doors exist 
		{
			mapArray[xOrigin+(ROOM_SIZE/2)][yOrigin] = "  ";
		}
		
		if (rooms[i].getNorthDoor() >= 0)
	        // - Establish the doors as spaces by inquiring if the doors exist 
		{
			mapArray[xOrigin+(ROOM_SIZE/2)][yOrigin + ROOM_SIZE - 1] = "  ";
		}
		
		if (rooms[i].getWestDoor() >= 0)
	        // - Establish the doors as spaces by inquiring if the doors exist 
		{
			mapArray[xOrigin][yOrigin+(ROOM_SIZE/2)] = " ";
		}
		
		if (rooms[i].getEastDoor() >= 0)
	        // - Establish the doors as spaces by inquiring if the doors exist 
		{
			mapArray[xOrigin + ROOM_SIZE - 1][yOrigin+(ROOM_SIZE/2)] = " ";
		}
	}

	// 4. Place the user in the center of the room:
	int userXLocation = (rooms[user.getLocation()].getXLocation())*ROOM_SIZE + ROOM_SIZE/2;
	int userYLocation = (rooms[user.getLocation()].getYLocation())*ROOM_SIZE + ROOM_SIZE/2;
	mapArray[userXLocation][userYLocation] = "}{";

	// 5. Print out the map:
	for (int m = X_DIMENSION - 1; m >= 0 ; m--)
	{
		for (int n = 0; n < Y_DIMENSION; n++)
		{
			cout << mapArray[n][m];
			sleep_for(milliseconds(3));
		}

		cout << endl;
	}
}

// Function for looking around the room *****************************************************************************

/*
* Algorithm: display characteristics of the room the user is currently located
* Steps: 
	1. Print "here are the attributes of your room:
	2. If a door exists, print "there is a door on the ___ side" (whichever side it exists)
	3. Print the items in the room
	4. Print the item the user has 
* Input parameters: The user object, the array of rooms, the array of doors 
* Output (prints to screen): The above statements 
* Returns: Nothing 
*/
    
void lookAround(User &user, Room rooms[], Door doors[])
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	cout << "Here are the current attributes of your location: " << endl;
			sleep_for(milliseconds(60));
	cout << "Map: " << endl;
			sleep_for(milliseconds(60));
	buildMap(user, rooms, doors);
	cout << endl;
			sleep_for(milliseconds(60));

	if (rooms[user.getLocation()].getNorthDoor() != -1)
	{
		  cout << "There is a door on the north side in which you can move through." << endl;
			sleep_for(milliseconds(60));
	}
	
	if (rooms[user.getLocation()].getSouthDoor() != -1)
	{
		  cout << "There is a door on the south side in which you can move through." << endl;
			sleep_for(milliseconds(60));
	}
	
	if (rooms[user.getLocation()].getWestDoor() != -1)
	{
		  cout << "There is a door on the west side in which you can move through." << endl;
			sleep_for(milliseconds(60));
	}
	
	if (rooms[user.getLocation()].getEastDoor() != -1)
	{
		  cout << "There is a door on the east side in which you can move through." << endl;
			sleep_for(milliseconds(60));
	}

	cout << endl;
			sleep_for(milliseconds(60));
	cout << "There is currently a " << user.getItemName() << " in your inventory." << endl;
			sleep_for(milliseconds(60));
	cout << endl;
			sleep_for(milliseconds(60));
	cout << "There is a " << rooms[user.getLocation()].getItemName(0) << " and a " << rooms[user.getLocation()].getItemName(1) << " which you could grab." << endl;
			sleep_for(milliseconds(60));
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
}

// Function for doing all sorts of fun stuff when you finish (displaying stats, writing to a certificate, etc)*******************************************

/*
* Algorithm: occur when the user has found the exit, print out various lines, write out to a file, and exit the program
* Steps: 
	1. Print a congratulations
	2. Print out many moves the user took
	3. Give the user a rating based upon how many moves they took
	4. Direct them to the certificate file found in the directory
	5. Open an ofstream to the designated certificate file 
	6. Write to the file the designted lines
	7. Wait for them to enter '1', and then exit the game 
* Input parameters: The user object, the counter from the main function 
* Output (prints to screen): The above statements 
* Returns: Nothing 
*/

void exitFunction(User &user, int &counter)
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	int choice;
	ofstream fileTool;
	char rating;
	if (user.getItemID() == -1)
	{
		cout << "Congratulations! You successfully guessed the correct number, thus allowing you to exit the game!" << endl;
		sleep_for(milliseconds(60));
	}

	else
	{
		cout << "Congratulations! You have found the exit, and the " << user.getItemName() << " you have can open the door!" << endl;
		sleep_for(milliseconds(60));
	}
	// 1. Print a congratulations
	cout << "You completed the game in: " << counter << " moves. ";
			sleep_for(milliseconds(60));
	// 2. Print out many moves the user took
	if (counter ==  0)
	// 3. Give the user a rating based upon how many moves they took
	{
		cout << "Perfect!" << endl;
			sleep_for(milliseconds(60));
		rating = 'A';
	}

	if (counter < 10)
	// 3. Give the user a rating based upon how many moves they took
	{
		cout << "Not bad for a beginner!" << endl;
			sleep_for(milliseconds(60));
		rating = 'B';
	}

	else if (counter < 20)
	{
		cout << "Not bad, however you could do better..." << endl;
			sleep_for(milliseconds(60));
		rating = 'C';
	}

	else
	{
		cout << "Surely you can do better." << endl;
			sleep_for(milliseconds(60));
		rating = 'D';
	}
	
	
	// 4. Direct them to the certificate file found in the directory
	cout << "After exiting the game, if you take a look in this directory, there is a txt file labeled 'Certificate.txt'." << endl;
			sleep_for(milliseconds(60));
	cout << "In which you will find a certificate of completion of the game Rooms!" << endl;
			sleep_for(milliseconds(60));
	cout << "Thanks for playing, " << user.getName() << "!" << endl;
			sleep_for(milliseconds(60));
	cout << "When finished reading this message, enter 1 to exit the game. Good job!" << endl;
			sleep_for(milliseconds(60));
	cin >> choice;

	fileTool.open("certificate.txt");
	// 5. Open an ofstream to the designated certificate file
	fileTool << "======================= Cerificate of Completion: =======================" << endl;
	// 6. Write to the file the designated lines 
	fileTool << "This hereby certifies that " << user.getName() << " completed Rooms!" << endl;
	fileTool << "They completed this game in " << counter << " moves, earning them a " << rating << " rating!" << endl;
	fileTool << "Thanks for playing!" << endl;
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));

	while (choice != 1)
	// 7. Wait for them to enter '1', and then exit the game 
	{
		cout << "Take all the time you need to read the above message." << endl;
			sleep_for(milliseconds(60));
		cin >> choice;
	}

	exit(0);
	
}

// Function for moving around the house *****************************************************************************

/*
* Algorithm: allow for the user to move from room to room should that room exist 
* Steps: 
	1. Print a menu that asks the user which direction to move
	2. Enter a while loop that has user re-input their choice should it not be one of the provided
	3. If choice aligns with that of the menu, enter if statement:
	   - If the designated door doesn't exist, print "that's a wall, you can't go there"
	   - Else if the door is the exit door, go to the exit function 
	   - Else, change the user's location to the room that is in the designated direction
* Input parameters: The user object, the room arrays, and the door arays the counter from the main function 
* Output (prints to screen): The above statements 
* Returns: Nothing 
*/

void moveAround(User &user, Room rooms[], Door doors[], int &counter)
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	cout << "This is your current location: " << endl;
	buildMap(user, rooms, doors);
	cout << endl;
	int choice = 0;
	counter++;
	cout << "Which direction would you like to go? " << endl;
			sleep_for(milliseconds(60));
	// 1. Print a menu that asks the user which direction to move
	cout << "1. North" << endl;
			sleep_for(milliseconds(60));
	cout << "2. South" << endl;
			sleep_for(milliseconds(60));
	cout << "3. West" << endl;
			sleep_for(milliseconds(60));
	cout << "4. East" << endl;
			sleep_for(milliseconds(60));
	cin >> choice;
			sleep_for(milliseconds(60));
	while (choice < 1 || choice > 4)
	// 2. Enter a while loop that has user re-input their choice should it not be one of the provided
	{
		cout << "Invalid option. Please choose one of the provided options." << endl;
			sleep_for(milliseconds(60));
		cin >> choice;
	}

     /* 3. If choice aligns with that of the menu, enter if statement:
	   - If the designated door doesn't exist, print "that's a wall, you can't go there"
	   - Else if the door is the exit door, go to the exit function 
           - Else, change the user's location to the room that is in the designated direction
     */ 
	if (choice == 1)
	{
		if (rooms[user.getLocation()].getNorthDoor() == -1)  
		{
			cout << endl;
			sleep_for(milliseconds(60));
			cout << "That's a wall, you can't go there." << endl;
			sleep_for(milliseconds(60));
		}
		
		else if (rooms[user.getLocation()].getNorthDoor() == EXIT_DOOR_INDEX)
		{
			if (user.getIfItemIsNeeded() == 0)
			{
				cout << "Unfortunately, the item you have is not the item needed to exit the house. Please go grab another item." << endl;
			sleep_for(milliseconds(60));
			}

			else
			{
				exitFunction(user, counter);
			}
		}

		else
		{
			cout << endl;
			sleep_for(milliseconds(60));
			user.setLocation(doors[rooms[user.getLocation()].getNorthDoor()].getNorthRoom());
			rooms[user.getLocation()].setIfVisited(true);
			buildMap(user, rooms, doors);
			cout << "You moved to the northern room." << endl; 
			sleep_for(milliseconds(60));
		}
	}
	
	else if (choice == 2)
	{
		if (rooms[user.getLocation()].getSouthDoor() == -1)  
		{
			cout << endl;
			sleep_for(milliseconds(60));
			cout << "That's a wall, you can't go there." << endl;
			sleep_for(milliseconds(60));
		}

		else
		{
			sleep_for(milliseconds(60));
			cout << endl;
			sleep_for(milliseconds(60));
			user.setLocation(doors[rooms[user.getLocation()].getSouthDoor()].getSouthRoom());
			rooms[user.getLocation()].setIfVisited(true);
			buildMap(user, rooms, doors);
			cout << "You moved to the southern room." << endl; 
			sleep_for(milliseconds(60));
		}
	}
	
	else if (choice == 3)
	{
		if (rooms[user.getLocation()].getWestDoor() == -1)  
		{
			cout << endl;
			sleep_for(milliseconds(60));
			cout << "That's a wall, you can't go there." << endl;
			sleep_for(milliseconds(60));
		}

		else
		{
			sleep_for(milliseconds(60));
			cout << endl;
			sleep_for(milliseconds(60));
			user.setLocation(doors[rooms[user.getLocation()].getWestDoor()].getWestRoom());
			rooms[user.getLocation()].setIfVisited(true);
			buildMap(user, rooms, doors);
			cout << "You moved to the western room." << endl; 
			sleep_for(milliseconds(60));
		}
	}
	
	else
	{
		if (rooms[user.getLocation()].getEastDoor() == -1)  
		{
			cout << endl;
			sleep_for(milliseconds(60));
			cout << "That's a wall, you can't go there." << endl;
			sleep_for(milliseconds(60));
		}


		else
		{
			sleep_for(milliseconds(60));
			cout << endl;
			sleep_for(milliseconds(60));
			user.setLocation(doors[rooms[user.getLocation()].getEastDoor()].getEastRoom());
			rooms[user.getLocation()].setIfVisited(true);
			buildMap(user, rooms, doors);
			cout << "You moved to the eastern room." << endl; 
			sleep_for(milliseconds(60));
		}
	}
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
}

// Function to build the name of the txt file used **************************************************************

/*
* Algorithm: creates a string used for the file name 
* Steps: 
	1. Set input identity from the 'place items' section of the main function to a string
	2. Build a string by adding that identity to the phrase '.txt'
	3. Return the filename string
* Input parameters: int identity  
* Output (prints to screen): Nothing 
* Returns: the filename 
*/

string buildName(int identity)
{
	string identityString = to_string(identity);
	// 1. Set input identity from the 'place items' section of the main function to a string
	string fileName = identityString + ".txt";
	// 2. Build a string by adding that identity to the phrase '.txt'
	return fileName;
	// 3. Return the filename string
}

// Function used to exchange the item in the room ***************************************************************

/*
* Algorithm: swap the user's item with one of the room's items that the user is currently in 
* Steps: 
	1. Display the two choices of items
	2. Ask which item they would like to swap, give them two options in terms of integers 1 & 2
	3. If the input option is not equal to 1 or 2, prompt the user to enter one of the provided options
	4. Else if input option equals 1 or 2:
	   - Create a temp item object  
	   - Set id, name and if it is needed to the item in the room with the corresponding id (0 if the  
             option is 1, 1 if the option is 2)
	   - Create another temp object that sets equal all the user's item attributes to that of the temp item's
	   - Set the user's item values equal to that of the first temp item, and the room's to the second
	5. Print out the items' names that were swapped 
* Input parameters: the user object, the array of rooms object   
* Output (prints to screen): Various lines when called 
* Returns: Nothing
*/

void exchangeItem(User &user, Room rooms[])
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	int choice;
	
	// 1. Display the two choices of items:
	cout << "Your choices of items in this room are: " << endl;
			sleep_for(milliseconds(60));
	cout << "1. " << rooms[user.getLocation()].getItemName(0) << endl;
			sleep_for(milliseconds(60));
	cout << "2. " << rooms[user.getLocation()].getItemName(1) << endl;
			sleep_for(milliseconds(60));
	cout << endl;
			sleep_for(milliseconds(60));

	// 2. Ask which item they would like to swap, give them two options in terms of integers 1 & 2:
	cout << "Which item would you like to swap? " << endl;
			sleep_for(milliseconds(60));
	cout << "If you'd like to exchange item 1, enter '1'." << endl;
			sleep_for(milliseconds(60));
	cout << "If you'd like to exchange item 2, enter '2'." << endl;
			sleep_for(milliseconds(60));
	cout << "If neither seem appealing, enter '3' to return to the main menu." << endl;
			sleep_for(milliseconds(60));
	cin >> choice;

	while (choice < 1 || choice > 3)
	// 3. If the input option is not equal to 1 or 2, prompt the user to enter one of the provided options
	{
		cout << "Invalid choice. Please enter one of the provided options." << endl;
			sleep_for(milliseconds(60));
		cin >> choice;
	}

	// 4. Else if input option equals 1 or 2:
	if (choice == 1)
	{
		Item tempItem1;
	   	// - Create a temp item object  
		tempItem1.setItemID(rooms[user.getLocation()].getItemID(0));
		tempItem1.setNameOfItem(rooms[user.getLocation()].getItemName(0));
		tempItem1.setIfItemIsNeeded(rooms[user.getLocation()].getIfItemIsNeeded(0));
	   	// - Set id, name and if it is needed to the item in the room with the corresponding id (0 if the  
           	//   option is 1, 1 if the option is 2)
	
		Item tempItem2;	
	   	// - Create another temp object that sets equal all the user's item attributes to that of the temp item's
		tempItem2.setItemID(user.getItemID());
		tempItem2.setNameOfItem(user.getItemName());
		tempItem2.setIfItemIsNeeded(user.getIfItemIsNeeded());

	   	// - Set the user's item values equal to that of the first temp item, and the room's to the second:
		user.setItem(tempItem1);
		rooms[user.getLocation()].setItemAt(0, tempItem2);
		
		cout << endl;
			sleep_for(milliseconds(60));
		cout << "You have swapped your " << rooms[user.getLocation()].getItemName(0) << " for a " << user.getItemName() << endl;
			sleep_for(milliseconds(60));
		// 5. Print out the items' names that were swapped 
	}

	else if (choice == 2)
	{
		
		Item tempItem1;
		tempItem1.setItemID(rooms[user.getLocation()].getItemID(1));
		tempItem1.setNameOfItem(rooms[user.getLocation()].getItemName(1));
		tempItem1.setIfItemIsNeeded(rooms[user.getLocation()].getIfItemIsNeeded(1));

		Item tempItem2;	
		tempItem2.setItemID(user.getItemID());
		tempItem2.setNameOfItem(user.getItemName());
		tempItem2.setIfItemIsNeeded(user.getIfItemIsNeeded());

		user.setItem(tempItem1);
		rooms[user.getLocation()].setItemAt(1, tempItem2);
		
		cout << endl;
			sleep_for(milliseconds(60));
		cout << "You have swapped your " << rooms[user.getLocation()].getItemName(1) << " for a " << user.getItemName() << endl;
			sleep_for(milliseconds(60));
	}

	else 
	{
		cout << "Returning to main menu" << endl;
			sleep_for(milliseconds(60));
	}
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
}

// Function used to split the text file *********************************************************************

int split(string lineSequence, char delimitor, string splitArray[], int length)
{
  
        string temp; 
        // Establish a temporary variable used to transfer array values later 
        // in the fuction
        int lengthwords = 0; 
     
        if(lineSequence == "")
        // If the line doesn't exist, return 0
        {
            return 0;
        } 
      
        else
        {
       
        lineSequence = lineSequence + delimitor;
        // Ensure the sequence includes the delimitor as to prevent unwanted
        // values being populated
     
        for(int count = 0; count < lineSequence.length(); count++)
        // Enter for loop 
        {
           
            if(lineSequence[count] != delimitor)
            // If the character in the string at that certain point isn't 
            // the delimitor, set the temporary variable equal to the temp character
            // plus the new character
            {
                temp = temp + lineSequence[count];
            }
          
            else 
            // Else, create an entry in the array that equals the temp variable
            {
                if(temp.length()!=0)
                {
                    splitArray[lengthwords] = temp;  
                    lengthwords++; 
                }
                temp = ""; 
                // Clear the temp variable
            }
    
        }  
            if(lengthwords > length)
            // Ensure the number of times the loop was executed wasn't larger than the 
            // length of the array
            {
                return -1;
            }
        }
        return lengthwords;
        // Return the counter variable (lengthWords)
}

// Function for teleporting user to a random room********************************************************************

/*
* Algorithm: Move the user to a random room 
* Steps: 
	1. Create a random integer between 0 and the amount of rooms - 1
	2. Incriment the move counter from the main function (passed in by reference) by 1
	3. Set the user's location to that randomly generated integer
* Input parameters: The user object, the array of rooms object, the move counter   
* Output (prints to screen): The room the user was moved to  
* Returns: Nothing
*/

void teleportUser(User &user, Room rooms[], Door doors[], int &counter)
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	int randomRoom = (rand()%(X_ROOMS*Y_ROOMS));
	// 1. Create a random integer between 0 and the amount of rooms - 1
	counter++;
	// 2. Incriment the move counter from the main function (passed in by reference) by 1
	cout << "This was your current room: " << endl;
			sleep_for(milliseconds(60));
	buildMap(user, rooms, doors);
	user.setLocation(randomRoom);
	// 3. Set the user's location to that randomly generated integer
	cout << "This is now your current room: " << endl;
			sleep_for(milliseconds(60));
	buildMap(user, rooms, doors);
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
}

// Function used for the random choice option ***********************************************************************


/*
* Algorithm: offer the user 3 chances to escpae the house all together  
* Steps: 
	1. Create a random number for which the user has to guess
	2. Confirm if the user wants to use up one of their attemps, display the amount of attempts remaining
	3. If the option is neither 1 or 2, tell user their entry was invalid and ask them to input another choice
	4. If the user selects 1 (confirming their intent to attempt):
	   - Prompt them to guess a number 1 - 10 that the number might be 
	   - If the guess was invalid, tell them and prompt them to guess again
	   - Else:
             - If the guess was corrent, move on to the exit function
	     - If not, decriment the attempt counter by 1
* Input parameters: the user object, the array of room objects, the attempt counter and the move counter   
* Output (prints to screen): Various prompted lines 
* Returns: Nothing
*/

void randomChoice(User &user, Room rooms[], int &counter, int &counter2)
{
	cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
	int choice;
	int choice2;	
	int randomChoice = (rand()%10 + 1);
	int randomChoice2 = 8;
	// 1. Create a random number for which the user has to guess

	if (counter == 0)
	{
		cout << "Unfortunately you have used all your attempts. Please select an option provided by the main menu." << endl;
		cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
		return;
	}
	
	// 2. Confirm if the user wants to use up one of their attemps, display the amount of attempts remaining:
	if (counter == 1)
	// - If the attemps == 1, make 'attempt' singular
	{
		cout << "Are you sure you'd like to try your luck? You only have " << counter << " attempt left." << endl;
		sleep_for(milliseconds(60));
	}

	else
	// - Else, make 'attempts' plural
	{
		cout << "Are you sure you'd like to try your luck? You only have " << counter << " attempts left." << endl;
		sleep_for(milliseconds(60));
	}
		
	cout << "1. Yes." << endl;
			sleep_for(milliseconds(60));
	cout << "2. No." << endl;
			sleep_for(milliseconds(60));
	cin >> choice;
		
	while (choice < 1 || choice > 2)
	// 3. If the option is neither 1 or 2, tell user their entry was invalid and ask them to input another choice
	{
		cout << "Invalid choice. Please enter one of the provided options." << endl;
			sleep_for(milliseconds(60));
		cin >> choice;
	}
	
	if (choice == 1)
	// 4. If the user selects 1 (confirming their intent to attempt):
	{
		cout << endl;
			sleep_for(milliseconds(60));
		cout << "Please enter a guess (1-10) for what the random number might be: " << endl;
			sleep_for(milliseconds(60));
	   	// - Prompt them to guess a number 1 - 10 that the number might be 
		cin >> choice2;
	
		while (choice2 < 1 || choice2 > 10)
	   	// - If the guess was invalid, tell them and prompt them to guess again
		{
			cout << "Invalid choice. Please enter one of the provided options." << endl;
			sleep_for(milliseconds(60));
			cin >> choice2;
		}
	
		if (choice2 == randomChoice)
                // - If the guess was corrent, move on to the exit function
		{
			exitFunction(user, counter2);
		}

		else if (choice2 == randomChoice2)
                // - If the guess was corrent, move on to the exit function
		{
			cout << endl;
			cout << "Uh oh! You chose the losing number!" << endl;
			sleep_for(milliseconds(60));
			cout << "Unfortunately, this means you no longer can move throughout the house, and thus your game has ended." << endl;
			sleep_for(milliseconds(60));
			cout << "Better luck next time!" << endl;	
			sleep_for(milliseconds(60));
			exit(0);
		}

		else
	        // - If not, decriment the attempt counter by 1
		{
			if (counter == 1)
			{
				cout << "Unfortunately, you did not guess it correctly. " << endl;	
			}

			else if (counter == 2)
			{
				cout << "Unfortunately, you did not guess it correctly. You still have " << counter - 1 << " attempt." << endl;
				sleep_for(milliseconds(60));
			}

			else
			{
				cout << "Unfortunately, you did not guess it correctly. You still have " << counter - 1 << " attempts." << endl;
				sleep_for(milliseconds(60));
			}
				
			counter--;
		}
				
	}
cout << "******************************************************************" << endl;
			sleep_for(milliseconds(60));
}   

// Function for displaying a menu of what to do and calling to proper funcitons based on choice *********************

/*
* Algorithm: provide the user with a menu of options, and direct them to the proper function based on their choice 
* Steps: 
	1. Print out the user's current statistics: their current location, which room they're in,
	   the number of times they've moved, and the item they're holding
	2. Print a menu for the user to choose from
	3. If the attempt counter equals 0, don't print option 5
	4. Else, print that option
	5. Have user input their choice
	6. If their choice doesn't fit the parameters, tell them and prompt them to input a valid choice 
	7. If their choice equals 1, pass the proper parameters to the lookAround function
	8. Else if their choice equals 2, pass the proper parameters to the moveAround function 
	9. Else if their choice equals 3, pass the proper parameters to the exchangeItem function 
	10. Else if their choice equals 4, pass the proper parameters to the teleportUser function 
	11. Else if their choice equals 5, pass the proper parameters to the randomChoice  function 
	12. Else if their choice equals 6, print a farwell statement and exit the program 
* Input parameters: the user object, the array of room objects, the array of door objects, the attempt counter and the move counter   
* Output (prints to screen): Various prompted lines 
* Returns: Nothing
*/

void decisionFunction(User &user, Room rooms[], Door doors[], int &counterForOption5, int &counterForOption2)
{
	// 1. Print out the user's current statistics: their current location, which room they're in,
	//    the number of times they've moved, and the item they're holding:
	int choice = 0;
	cout << "Current statistics: " << endl;
			sleep_for(milliseconds(60));
	
	if (counterForOption2 != 1)
	{
		cout << "You have moved " << counterForOption2 << " times." << endl;
			sleep_for(milliseconds(60));
	}

	else 
	{
		
		cout << "You have moved " << counterForOption2 << " time." << endl;
			sleep_for(milliseconds(60));
	}
	cout << "You're currently holding a " << user.getItemName() << "." << endl;
			sleep_for(milliseconds(60));

	// 2. Print a menu for the user to choose from
	cout << endl;
			sleep_for(milliseconds(60));
	cout << "What would you like to do, " << user.getName() << "?" << endl;
			sleep_for(milliseconds(60));
	cout << "1. Look around the room." << endl; 
			sleep_for(milliseconds(60));
	cout << "2. Move to a different room." << endl; 
			sleep_for(milliseconds(60));
	cout << "3. Exchange item." << endl; 
			sleep_for(milliseconds(60));
	cout << "4. Teleport to a random room." << endl;
			sleep_for(milliseconds(60));
	if (counterForOption5 == 0)
	// 3. If the attempt counter equals 0, don't print option 5
	{
	
	}
	else if (counterForOption5 == 1)
	// 4. Else, print that option
	{
		cout << "5. Guess a pre-set number (1-10) which, if guessed correctly, can bail you out of the house! You only have " << counterForOption5 << " attempt left, however." << endl;
			sleep_for(milliseconds(60));
	}
	else if (counterForOption5 == 3)
	// 4. Else, print that option
	{
		cout << "5. Guess a pre-set number (1-10) which, if guessed correctly, can bail you out of the house! You only have " << counterForOption5 << " attempts, however." << endl;
			sleep_for(milliseconds(60));
	}
	else 
	// 4. Else, print that option
	{
		cout << "5. Guess a pre-set number (1-10) which, if guessed correctly, can bail you out of the house! You only have " << counterForOption5 << " attempts left, however." << endl; 
			sleep_for(milliseconds(60));
	}	
	cout << "6. Quit." << endl;
			sleep_for(milliseconds(60));
	cin >> choice;
	
	while (choice < 1 || choice > 6) 
	// 6. If their choice doesn't fit the parameters, tell them and prompt them to input a valid choice 
	{
		cout << "Invalid choice. Please enter one of the provided options." << endl;
			sleep_for(milliseconds(60));
		cin >> choice;
	}

	if (choice == 1)
	// 7. If their choice equals 1, pass the proper parameters to the lookAround function
	{
		cout << endl;
			sleep_for(milliseconds(60));
		lookAround(user, rooms, doors);
		cout << endl;
			sleep_for(milliseconds(60));
	}

	else if (choice == 2)
	// 8. Else if their choice equals 2, pass the proper parameters to the moveAround function 
	{
		cout << endl;
			sleep_for(milliseconds(60));
		moveAround(user, rooms, doors, counterForOption2);
		cout << endl;
			sleep_for(milliseconds(60));
	}

	else if (choice == 3)
	// 9. Else if their choice equals 3, pass the proper parameters to the exchangeItem function 
	{
		cout << endl;
			sleep_for(milliseconds(60));
		exchangeItem(user, rooms);
		cout << endl;
			sleep_for(milliseconds(60));
	}

	else if (choice == 4)
	// 10. Else if their choice equals 4, pass the proper parameters to the teleportUser function 
	{
		cout << endl;
			sleep_for(milliseconds(60));
		teleportUser(user, rooms, doors, counterForOption2);
		cout << endl;
			sleep_for(milliseconds(60));
	}

	else if (choice == 5)
	// 11. Else if their choice equals 5, pass the proper parameters to the randomChoice  function 
	{
		cout << endl;
			sleep_for(milliseconds(60));
		randomChoice(user, rooms, counterForOption5, counterForOption2);
		cout << endl;
			sleep_for(milliseconds(60));
	}
	
	else
	// 12. Else if their choice equals 6, print a farwell statement and exit the program 
	{
		cout << endl;
			sleep_for(milliseconds(60));
		cout << "Sorry to see you go! Hope to see you again soon! " << endl;
			sleep_for(milliseconds(60));
		exit(0);
	}
}

// Main function: creates map, assigns items to rooms, holds loop for game to continue to excecute *****

int main()
{

        srand( time(NULL) );
        ifstream fileTool;
	
/*
	* SUB_ALGORITHM OF MAIN: build the rooms for the house  
	* Steps: 
		1. Initialize a room array and a door array
		2. Set the currentRoom and currentDoor equal to 0
		3. Enter a nested for loop:
		   - Iterate the outer for loop one time until the counter equals Y_ROOMS (a definition set at the beginning of the program):
		     - Iterate the inner for loop one time until the counter equals X_ROOMS (a definition set at the beginning of the program):
		       - Set the room's x coordinate to the inner loop's counter, and the y value to the outer loop's
		       - If the room's x location is less than the max num of x rooms - 1 (in other words, not an eastern edged room):
			 - Create a door with:
                           - An EW orientation
			   - It's west room equal to the current room
			   - It's east room equal to the current room's eastern room 
		         - Set the current room's east door equal to that door, and the next room's west door equal to that door
			 - Incriment the door counter
		       - Else (in other words, it IS an eastern edged room), set the east door equal to -1 (in other words, it doesn't exist)
		       - Also, if the current room's x value is equal to 0 (meaning it's a western edged room), set it's western room equal to -1
		       - If the room's y location is less than the max num of y rooms - 1 (in other words, not a northern edged room):
			 - Create a door with:
                           - An NS orientation
			   - It's south room equal to the current room
			   - It's north room equal to the current room's northern room 
		         - Set the current room's northern door equal to that door, and the northernmost room's south door equal to that door
			 - Incriment the door counter
		       - Else (in other words, it IS a northern edged room), set the north door equal to -1 (in other words, it doesn't exist)
		       - Also, if the current room's y value is equal to 0 (meaning it's a southern edged room), set it's southern room equal to -1
		       - Incriment the room counter
		       - Finally, if the room equals a specific room (parameters varying), set the northern most door equal to EXIT_DOOR_INDEX (meaning it's the exit room) */

	Room rooms[TOTAL_ROOMS];
	Door doors[MAX_DOORS];
	// 1. Initialize a room array and a door array

	int currentRoom = 0;
	int currentDoor = 0;
	// 2. Set the currentRoom and currentDoor equal to 0

	for (int y = 0; y < Y_ROOMS; y++)
	// - Iterate the outer for loop one time until the counter equals Y_ROOMS (a definition set at the beginning of the program):
	{
		for(int x = 0; x < X_ROOMS; x++)
		// - Iterate the inner for loop one time until the counter equals X_ROOMS (a definition set at the beginning of the program):
		{
			rooms[currentRoom].setXLocation(x);
			rooms[currentRoom].setYLocation(y);
		        // - Set the room's x coordinate to the inner loop's counter, and the y value to the outer loop's
	
			if (x < X_ROOMS - 1)
		        // - If the room's x location is less than the max num of x rooms - 1 (in other words, not an eastern edged room):
			// - Create a door with:
			{
				doors[currentDoor].setOrientation(EW);
                                // - An EW orientation
				doors[currentDoor].setWestRoom(currentRoom);
			        //  - It's west room equal to the current room
				doors[currentDoor].setEastRoom(currentRoom + 1);
			        //  - It's east room equal to the current room's eastern room 
				rooms[currentRoom].setEastDoor(currentDoor);
			        //  - It's east room equal to the current room's eastern room 
				rooms[currentRoom + 1].setWestDoor(currentDoor);
				currentDoor++;
			        //  - Incriment the door counter
			} 

			else 
		        // - Else (in other words, it IS an eastern edged room), set the east door equal to -1 (in other words, it doesn't exist)
			{
			        rooms[currentRoom].setEastDoor(-1);
                        }
                        
			if ( x == 0 ) 
		        // - Also, if the current room's x value is equal to 0 (meaning it's a western edged room), set it's western room equal to -1
			{
			        rooms[currentRoom].setWestDoor(-1);
                        }
			
			if (y < Y_ROOMS - 1)
		        // - If the room's y location is less than the max num of y rooms - 1 (in other words, not a northern edged room):
			//  - Create a door with:
			{
				doors[currentDoor].setOrientation(NS);
                                // - An NS orientation
				doors[currentDoor].setNorthRoom(currentRoom + X_ROOMS);
			        // - It's south room equal to the current room
				doors[currentDoor].setSouthRoom(currentRoom);
			        // - It's north room equal to the current room's northern room 
				rooms[currentRoom].setNorthDoor(currentDoor);
		                // - Set the current room's northern door equal to that door, and the northernmost room's south door equal to that door
				rooms[currentRoom+ X_ROOMS].setSouthDoor(currentDoor);
				currentDoor++;
				// Incriment the door counter
			} 
			
			else 
		        // - Also, if the current room's x value is equal to 0 (meaning it's a western edged room), set it's western room equal to -1
			{
			        rooms[currentRoom].setNorthDoor(-1);
                        }
                        
			if ( y == 0 ) 
		        // - Also, if the current room's y value is equal to 0 (meaning it's a southern edged room), set it's southern room equal to -1
			{
				rooms[currentRoom].setSouthDoor(-1);
                        }
			
			
			if (rooms[currentRoom].getXLocation() == (X_ROOMS-2) && rooms[currentRoom].getYLocation() == (Y_ROOMS-1))
		        // - Finally, if the room equals a specific room (parameters varying), set the northern most door equal to EXIT_DOOR_INDEX (meaning it's the exit room) */
			{
				rooms[currentRoom].setNorthDoor(EXIT_DOOR_INDEX);
			}
			
			currentRoom++;
			// - Incriment the room counter
		} 
	}
	
// Next segment of main (assigns items to rooms ******************************************************************** 

    	for (int i = 0; i < (X_ROOMS * Y_ROOMS); i++)
	{
	        string fileName = buildName(i);
		fileTool.open(fileName);
       
        	if (fileTool.is_open())
        	{
            		string line = ""; 
            		int counter = 0;
            		while (getline(fileTool, line))
            		{
                                string tmp[3];
	        		for (int i = 0; i < 3; i++)
                		{		
                    			tmp[i] = " ";
                		}
                  
                		split(line, ',', tmp, 3);

                		int itemID = stoi(tmp[0]);
                		string itemName = tmp[1];
                		int itemNeeded = stoi(tmp[2]);

                		Item temp;
                		// Split the line using the split function by commas
                		temp.setItemID(itemID);
                		// Set the first entry in the array equal to the author
              	  		temp.setNameOfItem(itemName);
                		// Set the second entry in the array equal to the title
              	  		temp.setIfItemIsNeeded(itemNeeded);
                		// Set the second entry in the array equal to the title
                		rooms[i].setItemAt(counter, temp);
                		// Store the index of the book array equal to the temp 
	               		// object 
                		counter++;
                		// Incriment the number of books now stored in the 
               			// arrays by 1
            		}
                }
        	
		else 
               	{
            		cout << "The file didn't open correctly" << endl;
			sleep_for(milliseconds(60));
        	}
	fileTool.close();
	}

// Main game loop, as well as prints out pre-game instructions ***************************************

/*
	* SUB_ALGORITHM OF MAIN: initializing and establishing the needed variables, and implimenting the main game loop 
	* Steps: 
		1. Establish all the required main varables for the game
		2. Set the user's initial item
		3. Print out the beginning of game prompt
		4. Prompt user to enter 1 when they've finished reading the prompt
		5. If the user's input does not equal 1, allow for them to read the prompt again and ask for 1 to be entered in the end
		6. Ask user to input his/her name
		7. Set the user's name to the input name, the user's location to the origin room, and their item to the starting item
		8. Set the user's attributes 
		9. Enter game loop
		
*/
	// 1. Establish all the required main varables for the game:
	User user;
	string name;
	int option;
	int option2;
	int counterForLuckFunction = 3;
	int counterForMoveAroundFunction = 0;
	bool allowForGameLoopToRunEndlessly = true;
	
	// 2. Set the user's initial item:
	Item item;
	item.setItemID(-1);
	item.setNameOfItem("phone");
	item.setIfItemIsNeeded(0);
	
	// 3. Print out the beginning of game prompt:
	// - Buffer to a blank screen
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << "*****************************************************************************************************************************************************************************" << endl;
	cout << "Welcome to Rooms!" << endl;
			sleep_for(milliseconds(60));
	cout << "This game has one simple objective: get out." << endl;
			sleep_for(milliseconds(60));
			cout << endl;
	cout << "In this game, you're stuck in a house which contains " << (X_ROOMS * Y_ROOMS) << " rooms, of which you have to navigate to eventually find the exit." << endl;
			sleep_for(milliseconds(60));
	cout << "One of the bordering rooms will have an exit attached, which you can use to leave the house and complete the game." << endl;
			sleep_for(milliseconds(60));
			cout << endl;
	cout << "There are two items placed in each room, making a total of " << 2*(X_ROOMS * Y_ROOMS) << " items, one of which is required to exit the house. It's up to you to find which one is needed to exit." << endl;
			sleep_for(milliseconds(60));
	cout << "You begin with a phone in your inventory, which you can trade for any of the items found in the rooms." << endl;
			sleep_for(milliseconds(60));
			cout << endl;
	cout << "You'll also have 3 attempts to guess a specific random number, which if you guess correctly, will immediately allow you to exit the house." << endl;
			sleep_for(milliseconds(60));
	cout << "However, should you happen to guess another certain number, you'll lose the ability to move, stranding you and ultimately ending your game right then and there." << endl;
			sleep_for(milliseconds(60));
	cout << "So, be careful when utilizing this option!" << endl;
			sleep_for(milliseconds(60));
			cout << endl;
	cout << "In short, in order to exit the house, you must aquire the correct object and then proceed to find the exit attached to the outside of one of the bordering rooms." << endl; 
			sleep_for(milliseconds(60));
	cout << "At the end, you will recieve a certificate containing, among other things, a grade based upon the number of moves it took you to exit, so be mindful of how many times you move rooms! " << endl;
	cout << "*****************************************************************************************************************************************************************************" << endl;
	cout << "Please enter 1 when you have read and understood these instructions: " << endl;
			sleep_for(milliseconds(60));
	// 4. Prompt user to enter 1 when they've finished reading the prompt
	cin >> option2;
	
	while (option2 != 1)
	{
		cout << "Take all the time you need, enter 1 when ready." << endl;
		cin >> option2;
	}

	cout << endl;
        cout << "Please enter your name to begin the game: " << endl;
        cin.get();
        getline(cin, name);
	cout << endl;
        cout << "Best of luck to you " << name << "!" << endl;
        cout << endl;

        user.setName(name);
        user.setLocation(0);
        user.setItem(item);

        while (1 > 0)
        {
                decisionFunction(user, rooms, doors, counterForLuckFunction, counterForMoveAroundFunction);
        }

        return 0;
}




























