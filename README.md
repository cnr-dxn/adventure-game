# Adventure Game

A choose your own adventure game, involving items to collect, a maze to follow and puzzles to solve in order to complete the game. 

**Scalable**: With just a few edits to preset values, the quantity of “rooms” in the game can be increased immensely. This is due to the fact that when building this game, I designed it to be scalable, that way it wasn’t restricted to a certain size, and thus difficulty, but was fluid as to allow it to be increasingly enjoyable to play as well. 

**Object Oriented Programming**: In order for the scalability to work, I designed a dynamically allocating object oriented programming schema to ensure that the game was able to grow, and grow as efficiently as possible. 

**Graphics**: Even though this is a terminal-based game, I designed a game interface that used all of the capabilities of the terminal to create a quaint yet engaging interface, the aspects of which can be changed in the same settings as the scale factors. 

## How to run this application:

This is run as a C++ application, and thus to allow correct access to existing credientials to the necessary executables, utilize the Makefile and run the following code:
```
make clean
make
```
This will compile the necessary code into an executable titled main, so to run simply execute it:
```
./game
```
Then just simply follow the directions output to the screen! 

## File Structure

**game.cpp** is where all the main functionality is written.

**Door.h/cpp, User.h/cpp, Room.h/cpp and Item.h/cpp** are the implimentation of the various classes necessary for the running of the game.

## Notes

To adjust the number of rooms/size of rooms, adjust the **X_DIMENSION< Y_DIMENSION, ROOM_SIZE, DOOR_SIZE** flags defined at the beginning.
