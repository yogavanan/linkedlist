#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>

enum Direction {North, South, East, West};

class MapSite {
public:
	virtual void Enter() = 0;
};

class Room : public MapSite {
public:
	Room(int roomNo)
	{
		_roomNumber = roomNo;
		cout << "New room added to the Maze " << _roomNumber << "\n";
	};

	MapSite* GetSide(Direction) const;
	void SetSide(Direction dir, MapSite* wallOrDoor)
	{
		_sides[dir] = wallOrDoor;
		cout << "Side" << dir << " added to room " << _roomNumber << "\n";
	};
	virtual void Enter()
	{
		cout << "Entering room no " << _roomNumber << "\n";

	};

private:
	MapSite* _sides[4];
	int _roomNumber;
};

class Wall : public MapSite {
public:
	Wall()
	{
		cout << "New wall created !! \n";
	};
	virtual void Enter()
	{
		cout << "Nose is broken..!! Hitting on a wall dude!! \n";
	};
};

class Door : public MapSite {
public:
	Door(Room* r1, Room* r2)
	{
		_room1 = r1;
		_room2 = r2;
	};
	virtual void Enter()
	{
		cout << "Entering Door \n";
		_isOpen = true;
	};
	Room* OtherSideFrom(Room*);
private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
};

class Maze {
public:
	Maze()
	{
		cout << "Maze is created !! \n";
	};
	void AddRoom(Room* newRoom)
	{
		_roomList[_roomCount++] = newRoom;
	};
	Room* RoomNo(int) const;
private:
	Room * _roomList[10];
	int _roomCount;
// ...
};

class MazeGame
{
public:
	static Maze* CreateMaze ();

};


Maze* MazeGame::CreateMaze () 
{
	Maze* aMaze = new Maze;
	Room* r1 = new Room(1);
	Room* r2 = new Room(2);

	Door* theDoor = new Door(r1, r2);
	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(North, new Wall);
	r1->SetSide(East, theDoor);
	r1->SetSide(South, new Wall);
	r1->SetSide(West, new Wall);

	r2->SetSide(North, new Wall);
	r2->SetSide(East, new Wall);
	r2->SetSide(South, new Wall);
	r2->SetSide(West, theDoor);

	cout << "Maze Game created !! \n";

	return aMaze;
}



int main()
{
	Maze* newMaze = MazeGame::CreateMaze ();

	return 0;
}