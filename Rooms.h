#pragma once
#include "template.h"

extern int current_room;

void DebugRun();

void RunRoom(int roomid);
void UpdateRoom();
void CloseRoom(int roomid);
void GoToRoom(int roomid);

void RunRoom0();
void UpdateRoom0();
void CloseRoom0();
void RunRoom1();
void UpdateRoom1();
void CloseRoom1();
void RunRoomBattle();
void UpdateRoomBattle();
void CloseRoomBattle();

int HowManySounds();
int HowManyImages();
int HowManySprites();