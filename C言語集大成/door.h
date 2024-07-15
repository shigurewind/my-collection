#pragma once


#define DOORMAX (4)

struct DOOR
{
	int opened;

	int startY;
	int startX;

	int H;
	int W;


};

void InitDoor();
int CheckDoor(int y, int x);
void DrawDoor();

extern DOOR door[DOORMAX];