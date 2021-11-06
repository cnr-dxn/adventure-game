game: game.cpp  item.o user.o room.o door.o
	g++ -o game item.o user.o room.o door.o game.cpp

item.o: Item.cpp Item.h
	g++ -c -o item.o Item.cpp

user.o: User.cpp User.h
	g++ -c -o user.o User.cpp

room.o: Room.cpp  Room.h
	g++ -c -o room.o Room.cpp

door.o: Door.cpp Door.h
	g++ -c -o door.o Door.cpp

clean: 
	rm -f item.o user.o room.o door.o game
