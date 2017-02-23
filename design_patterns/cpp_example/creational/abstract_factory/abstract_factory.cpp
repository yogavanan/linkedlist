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
	virtual void ~Enter() = 0;
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
		_isOpen = false;
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
		_roomCount = 0;
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

class MazeFactory {
public:
	MazeFactory(){};
	virtual ~MazeFactory(){};
	virtual Maze* MakeMaze() const
	{ return new Maze; }
	virtual Wall* MakeWall() const
	{ return new Wall; }
	virtual Room* MakeRoom(int n) const
	{ return new Room(n); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const
	{ return new Door(r1, r2); }
};

class Spell
{
public:
	Spell()
	{
		cout << "new spell is created\n";
	};
};

class EnchantedRoom : public Room {
public:
	EnchantedRoom (int roomNo, Spell * roomspell) : Room (roomNo)
	{
		cout << "Enchanted room is created \n";
		_spell =  roomspell;
	}

private: 
	Spell * _spell;
};

class DoorNeedingSpell: public Door{

public:
	DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2)
	{
		cout << "Door needing spell is created \n";
	};

};

class EnchantedMazeFactory : public MazeFactory {
public:
	EnchantedMazeFactory()
	{
		cout << "Creating Enchanted Maze factory!! \n";
	};
	virtual Room* MakeRoom(int n) const
	{ return new EnchantedRoom(n, CastSpell()); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const
	{ return new DoorNeedingSpell(r1, r2); }
protected:
	Spell* CastSpell() const
	{	
		return new Spell();
	};
};


class MazeGame
{
public:
	Maze* CreateMaze (MazeFactory& factory);

};


Maze* MazeGame::CreateMaze (MazeFactory& factory) 
{
	Maze* aMaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);

	Door* aDoor = factory.MakeDoor(r1, r2);
	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);
	
	r1->SetSide(North, factory.MakeWall());
	r1->SetSide(East, aDoor);
	r1->SetSide(South, factory.MakeWall());
	r1->SetSide(West, factory.MakeWall());
	

	r2->SetSide(North, factory.MakeWall());
	r2->SetSide(East, factory.MakeWall());
	r2->SetSide(South, factory.MakeWall());
	r2->SetSide(West, aDoor);


	cout << "Maze Game created !! \n";

	return aMaze;
}



int main()
{
	MazeGame game;
	EnchantedMazeFactory enchantedMazeFactory;
	game.CreateMaze (enchantedMazeFactory);

	return 0;
}
