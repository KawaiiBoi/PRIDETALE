#include "Rooms.h"
#include "template.h"
#include <fstream>
using namespace std;

ofstream roomdebug;

//roomdebug >> mountain_angle;
//myfileangle.close();

int current_room;

void DebugRun()
{
	roomdebug.open("roomdebug.txt");
}

void RunRoom(int roomid)
{
	if (roomid == 0)
	{
		RunRoom0(); roomdebug << "runroom0" << endl;
	}
	if (roomid == 1)
	{
		RunRoom1(); roomdebug << "runroom1" << endl;
	}
	if (roomid == 99)
	{
		RunRoomBattle(); roomdebug << "runroombattle" << endl;
	}
	roomdebug << "(runroom) current_room = " << current_room << endl;
}

void UpdateRoom()
{
	roomdebug << "(updateroom1) current_room = " << current_room << endl;
	if (current_room == 0)
	{
		UpdateRoom0(); roomdebug << "updateroom0" << endl;
	}
	roomdebug << "(updateroom2) current_room = " << current_room << endl;
	if (current_room == 1)
	{
		UpdateRoom1(); roomdebug << "updateroom1" << endl;
	}
	if (current_room == 99)
	{
		UpdateRoomBattle(); roomdebug << "updateroombattle" << endl;
	}
	roomdebug << "(updateroom3) current_room = " << current_room << endl;
}

void CloseRoom(int roomid)
{
	if (roomid == 0)
	{
		CloseRoom0(); roomdebug << "closeroom0" << endl;
	}
	if (roomid == 1)
	{
		CloseRoom1(); roomdebug << "closeroom1" << endl;
	}
	if (roomid == 99)
	{
		CloseRoomBattle(); roomdebug << "closeroombattle" << endl;
	}
	roomdebug << "(closeroom) current_room = " << current_room << endl;
}

void GoToRoom(int roomid)
{
	CloseRoom(current_room);
	roomdebug << "go from room " << current_room;
	current_room = roomid;
	roomdebug << " to room " << current_room << endl;
	RunRoom(current_room);
	roomdebug << "(gotoroom) current_room = " << current_room << endl;
}

int HowManySounds()
{
	int i = 100001;
	while (agk::GetSoundExists(i))
		i++;
	return i - 100001;
}

int HowManyImages()
{
	int i = 100001;
	while (agk::GetImageExists(i))
		i++;
	return i - 100001;
}

int HowManySprites()
{
	int i = 100001;
	while (agk::GetSpriteExists(i))
		i++;
	return i - 100001;
}